/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_conversion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:50:29 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/26 11:05:24 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_prefix_ptr(t_flags *flag)
{
	int	cnt_chars;

	cnt_chars = 0;
	if (flag->plus)
		cnt_chars = write(1, "+", 1);
	else if (flag->space)
		cnt_chars = write(1, " ", 1);
	return (write(1, "0x", 2) + cnt_chars);
}

static int	ft_write_ptr(unsigned long long argument, t_flags *flag)
{
	int	cnt_chars;
	int	cnt_prefix;
	int	nbr_len;

	nbr_len = ft_nbr_len(argument, 16);
	cnt_prefix = ft_write_prefix_ptr(flag);
	cnt_chars = cnt_prefix;
	while (flag->precision > nbr_len || \
		(flag->zero && flag->min_field_width > nbr_len + cnt_prefix))
	{
		cnt_chars += write(1, "0", 1);
		nbr_len++;
	}
	cnt_chars += ft_write_hex(argument, 'a');
	return (cnt_chars);
}

static int	ft_check_width_ptr(unsigned long long nbr, int cnt_width, \
								t_flags *flag)
{
	int	nbr_len;

	nbr_len = ft_nbr_len(nbr, 16);
	if (!cnt_width)
	{
		cnt_width = 2;
		if (flag->plus || flag->space)
			cnt_width++;
		if (flag->precision > nbr_len)
			cnt_width += flag->precision;
		else
			cnt_width += nbr_len;
	}
	return (cnt_width);
}

static int	ft_fill_field_width_ptr(unsigned long long nbr, int output, \
									t_flags *flag)
{
	int	cnt_output;
	int	cnt_min_width;

	cnt_output = 0;
	cnt_min_width = ft_check_width_ptr(nbr, output, flag);
	if (flag->plus || flag->space)
		cnt_min_width++;
	while (flag->min_field_width > cnt_min_width)
	{
		cnt_output += write(1, " ", 1);
		cnt_min_width++;
	}
	return (cnt_output);
}

int	ft_print_ptr_conversion(t_arguments *arg, t_flags *flag)
{
	unsigned long long	argument;
	int					cnt_chars;

	cnt_chars = 0;
	argument = va_arg(arg->list, unsigned long long);
	if (flag->minus)
		cnt_chars += ft_write_ptr(argument, flag);
	if (!(flag->zero))
		cnt_chars += ft_fill_field_width_ptr(argument, cnt_chars, flag);
	if (!(flag->minus))
		cnt_chars += ft_write_ptr(argument, flag);
	return (cnt_chars);
}
