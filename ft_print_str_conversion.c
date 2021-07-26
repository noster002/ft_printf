/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_conversion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:39:09 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/21 21:44:09 by nosterme         ###   ########.fr       */
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
	while (str_len < flag->min_field_width)
	{
		cnt_chars += write(1, " ", 1);
		str_len++;
	}
	return (cnt_chars);
}

int	ft_print_str_conversion(t_arguments *arg, t_flags *flag)
{
	int		cnt_chars;
	char	*string;
	int		output_str_len;
	int		flag_free;

	string = va_arg(arg->list, char *);
	flag_free = 0;
	if (!string)
	{
		flag_free = 1;
		if ((flag->dot && flag->precision >= 6) || !(flag->dot))
			string = ft_strdup("(null)");
		else if (flag->dot && flag->precision < 6)
			string = ft_strdup("\0");
	}
	output_str_len = ft_set_str_len(string, flag);
	cnt_chars = 0;
	if (flag->minus)
		cnt_chars += ft_write_str(string, output_str_len);
	cnt_chars += ft_fill_field_width_str(output_str_len, flag);
	if (!(flag->minus))
		cnt_chars += ft_write_str(string, output_str_len);
	if (flag_free)
		free(string);
	return (cnt_chars);
}
