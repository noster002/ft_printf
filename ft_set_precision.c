/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:54:57 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/14 16:46:02 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_set_precision(const char *offset, t_flags *flag)
{
	int	cnt_chars;
	int	num;

	cnt_chars = 1;
	num = 0;
	flag->dot = 1;
	while (ft_isdigit(offset[cnt_chars]))
	{
		num = num * 10 + (offset[cnt_chars] - '0');
		cnt_chars++;
	}
	flag->precision = num;
	return (cnt_chars);
}
