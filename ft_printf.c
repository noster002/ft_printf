/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:41:08 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/19 11:49:52 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	int			cnt_input;
	int			cnt_output;
	t_arguments	arg;
	t_flags		flags;

	cnt_input = 0;
	cnt_output = 0;
	va_start(arg.list, input);
	while (input[cnt_input] != 0)
	{
		if (input[cnt_input] != '%')
		{
			cnt_output += write(1, &(input[cnt_input]), 1);
			cnt_input++;
		}
		else
		{
			cnt_input += ft_initialize_flags(&(input[cnt_input + 1]), &flags);
			cnt_output += ft_conversion(arg, &flags);
		}
	}
	va_end(arg.list);
	return (cnt_output);
}
