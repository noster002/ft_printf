/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_min_field_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:36:32 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/14 16:45:41 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_set_min_field_width(const char *offset, t_flags *flag)
{
	int	cnt_chars;
	int	num;

	cnt_chars = 0;
	num = 0;
	while (ft_isdigit(offset[cnt_chars]))
	{
		num = num * 10 + (offset[cnt_chars] - '0');
		cnt_chars++;
	}
	flag->min_field_width = num;
	return (cnt_chars);
}
