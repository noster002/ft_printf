/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_conversion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:39:09 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/19 09:56:59 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_set_str_len(const char *string, t_flags *flag)
{
	int	str_len;

	str_len = ft_strlen(string);
	if (flag->dot && flag->precision < str_len)
		return (flag->precision);
	return (str_len);
}

static int	ft_write_str(const char *string, int str_len)
{
	return (write(1, string, str_len));
}

static int	ft_fill_field_width_str(int	str_len, t_flags *flag)
{
	int	cnt_chars;

	cnt_chars = 0;
	if (flag->min_field_width > str_len)
	{
		cnt_chars = write(1, "", 1);
		str_len++;
		while (str_len < flag->min_field_width)
		{
			cnt_chars += write(1, " ", 1);
			str_len++;
		}
	}
	return (cnt_chars);
}

int	ft_print_str_conversion(t_arguments arg, t_flags *flag)
{
	int			cnt_chars;
	const char	*string;
	int			output_str_len;

	string = va_arg(arg.list, const char *);
	output_str_len = ft_set_str_len(string, flag);
	cnt_chars = 0;
	if (flag->minus)
		cnt_chars += ft_write_str(string, output_str_len);
	cnt_chars += ft_fill_field_width_str(output_str_len, flag);
	if (!(flag->minus))
		cnt_chars += ft_write_str(string, output_str_len);
	return (cnt_chars);
}
