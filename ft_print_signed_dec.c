/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:23:05 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/21 11:35:08 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_prefix_signed_dec(long *nbr, t_flags *flag)
{
	int	cnt_chars;

	cnt_chars = 0;
	if (*nbr < 0)
	{
		cnt_chars = write(1, "-", 1);
		*nbr *= -1;
	}
	else if (flag->plus)
		cnt_chars = write(1, "+", 1);
	else if (flag->space)
		cnt_chars = write(1, " ", 1);
	return (cnt_chars);
}

static int	ft_write_signed_dec(long nbr, t_flags *flag)
{
	int	cnt_chars;
	int	nbr_len;

	cnt_chars = ft_write_prefix_signed_dec(&nbr, flag);
	nbr_len = ft_nbr_len(nbr, 10);
	if (flag->dot && !(flag->precision) && !nbr)
		return (cnt_chars);
	if (flag->zero && flag->min_field_width > nbr_len)
		nbr_len++;
	while (flag->precision > nbr_len || \
		(flag->zero && flag->min_field_width > nbr_len))
	{
		cnt_chars += write(1, "0", 1);
		nbr_len++;
	}
	cnt_chars += ft_write_dec(nbr);
	return (cnt_chars);
}

static int	ft_fill_field_width_signed_dec(long nbr, int output, t_flags *flag)
{
	int	cnt_chars;
	int	cnt_min_width;

	cnt_chars = 0;
	cnt_min_width = ft_check_width_dec(nbr, output, flag);
	while (flag->min_field_width > cnt_min_width)
	{
		cnt_chars += write(1, " ", 1);
		cnt_min_width++;
	}
	return (cnt_chars);
}

int	ft_print_signed_dec(t_arguments arg, t_flags *flag)
{
	int	cnt_chars;
	int	argument;

	cnt_chars = 0;
	argument = va_arg(arg.list, long);
	if (flag->minus || flag->dot)
		flag->zero = 0;
	if (flag->minus)
		cnt_chars += ft_write_signed_dec(argument, flag);
	if (!(flag->zero))
		cnt_chars += ft_fill_field_width_signed_dec(argument, cnt_chars, flag);
	if (!(flag->minus))
		cnt_chars += ft_write_signed_dec(argument, flag);
	return (cnt_chars);
}
