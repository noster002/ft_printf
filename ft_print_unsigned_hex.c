/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:41:17 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/26 10:50:29 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_prefix_unsigned_hex(unsigned int nbr, t_flags *flag)
{
	int	cnt_chars;

	cnt_chars = 0;
	if (!nbr)
		return (0);
	if (flag->lowercase_x && flag->hashtag)
		cnt_chars = write(1, "0x", 2);
	if (flag->uppercase_x && flag->hashtag)
		cnt_chars = write(1, "0X", 2);
	return (cnt_chars);
}

static int	ft_write_unsigned_hex(unsigned int nbr, t_flags *flag)
{
	int	cnt_chars;
	int	nbr_len;

	if (flag->dot && !(flag->precision) && !nbr)
		return (0);
	cnt_chars = ft_write_prefix_unsigned_hex(nbr, flag);
	nbr_len = ft_nbr_len(nbr, 16);
	while (flag->precision > nbr_len || \
		(flag->zero && flag->min_field_width > nbr_len + 2 * flag->hashtag))
	{
		cnt_chars += write(1, "0", 1);
		nbr_len++;
	}
	if (flag->lowercase_x)
		cnt_chars += ft_write_hex(nbr, 'a');
	else if (flag->uppercase_x)
		cnt_chars += ft_write_hex(nbr, 'A');
	return (cnt_chars);
}

static int	ft_check_width_hex(unsigned int nbr, int cnt_width, t_flags *flag)
{
	int	nbr_len;

	nbr_len = ft_nbr_len(nbr, 16);
	if (!cnt_width)
	{
		if (flag->hashtag && nbr)
			cnt_width += 2;
		if (flag->precision > nbr_len)
			cnt_width += flag->precision;
		else
			cnt_width += nbr_len;
	}
	return (cnt_width);
}

static int	ft_fill_field_width_unsigned_hex(unsigned int nbr, \
											int output, t_flags *flag)
{
	int	cnt_chars;
	int	cnt_min_width;

	cnt_chars = 0;
	cnt_min_width = ft_check_width_hex(nbr, output, flag);
	if (flag->dot && !(flag->precision) && !nbr)
		cnt_min_width = 0;
	while (flag->min_field_width > cnt_min_width)
	{
		cnt_chars += write(1, " ", 1);
		cnt_min_width++;
	}
	return (cnt_chars);
}

int	ft_print_unsigned_hex(t_arguments *arg, t_flags *flag)
{
	int				cnt_chars;
	unsigned int	nbr;

	cnt_chars = 0;
	nbr = va_arg(arg->list, unsigned int);
	if (flag->minus || flag->dot)
		flag->zero = 0;
	if (flag->minus)
		cnt_chars += ft_write_unsigned_hex(nbr, flag);
	if (!(flag->zero))
		cnt_chars += ft_fill_field_width_unsigned_hex(nbr, cnt_chars, flag);
	if (!(flag->minus))
		cnt_chars += ft_write_unsigned_hex(nbr, flag);
	return (cnt_chars);
}
