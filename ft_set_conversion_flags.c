/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_conversion_flags.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:45:07 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/20 21:22:53 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	ft_is_conversion_flag(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+');
}

int	ft_set_conversion_flags(const char *offset, t_flags *flag)
{
	int	cnt_chars;

	cnt_chars = 0;
	while (ft_is_conversion_flag(offset[cnt_chars]))
	{
		if (offset[cnt_chars] == '-')
			flag->minus = 1;
		if (offset[cnt_chars] == '0')
			flag->zero = 1;
		if (offset[cnt_chars] == '#')
			flag->hashtag = 1;
		if (offset[cnt_chars] == ' ')
			flag->space = 1;
		if (offset[cnt_chars] == '+')
			flag->plus = 1;
		cnt_chars++;
	}
	return (cnt_chars);
}
