/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_dec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:03:50 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/21 12:44:09 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_unsigned_dec(unsigned int nbr, t_flags *flag)
{
	int	cnt_chars;
	int	nbr_len;

	cnt_chars = 0;
	nbr_len = ft_nbr_len(nbr, 10);
	if (flag->dot && !(flag->precision) && !nbr)
		return (0);
	while (flag->precision > nbr_len || \
		(flag->zero && flag->min_field_width > nbr_len))
	{
		cnt_chars += write(1, "0", 1);
		nbr_len++;
	}
	cnt_chars += ft_write_dec(nbr);
	return (cnt_chars);
}

int	ft_check_width_unsigned_dec(unsigned int nbr, int cnt_width, t_flags *flag)
{
	int	nbr_len;

	nbr_len = ft_nbr_len(nbr, 10);
	if (!cnt_width)
	{
		if (flag->precision > nbr_len)
			cnt_width += flag->precision;
		else
			cnt_width += nbr_len;
	}
	return (cnt_width);
}

static int	ft_fill_field_width_unsigned_dec(unsigned int nbr, \
											int output, t_flags *flag)
{
	int	cnt_chars;
	int	cnt_min_width;

	cnt_chars = 0;
	cnt_min_width = ft_check_width_unsigned_dec(nbr, output, flag);
	if (flag->dot && !(flag->precision) && !nbr)
		cnt_min_width = 0;
	while (flag->min_field_width > cnt_min_width)
	{
		cnt_chars += write(1, " ", 1);
		cnt_min_width++;
	}
	return (cnt_chars);
}

int	ft_print_unsigned_dec(t_arguments arg, t_flags *flag)
{
	int				cnt_chars;
	unsigned int	nbr;

	cnt_chars = 0;
	nbr = va_arg(arg.list, unsigned int);
	if (flag->minus || flag->dot)
		flag->zero = 0;
	if (flag->minus)
		cnt_chars += ft_write_unsigned_dec(nbr, flag);
	if (!(flag->zero))
		cnt_chars += ft_fill_field_width_unsigned_dec(nbr, cnt_chars, flag);
	if (!(flag->minus))
		cnt_chars += ft_write_unsigned_dec(nbr, flag);
	return (cnt_chars);
}
