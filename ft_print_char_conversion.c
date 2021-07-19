/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_conversion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:36:45 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/19 11:50:29 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_set_output_field_width_char(t_flags *flag)
{
	if (flag->min_field_width)
		return (flag->min_field_width);
	return (1);
}

static void	ft_write_char(unsigned char argument)
{
	write(1, &argument, 1);
}

static void	ft_fill_field_width_char(t_flags *flag)
{
	while (flag->min_field_width > 1)
	{
		write(1, " ", 1);
		flag->min_field_width--;
	}
}

int	ft_print_char_conversion(t_arguments arg, t_flags *flag)
{
	int				cnt_chars;
	unsigned char	argument;

	cnt_chars = ft_set_output_field_width_char(flag);
	argument = va_arg(arg.list, int);
	if (flag->minus)
		ft_write_char(argument);
	ft_fill_field_width_char(flag);
	if (!(flag->minus))
		ft_write_char(argument);
	return (cnt_chars);
}
