/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:49:40 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/19 19:08:15 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex(long long dec)
{
	int		cnt_chars;
	char	c;

	cnt_chars = 0;
	if (dec < 0)
		dec += 4294967296;
	if (dec >= 16)
		cnt_chars = ft_write_hex(dec / 16);
	if ((dec % 16) >= 10)
		c = (dec % 16) + 'a' - 10;
	else if ((dec % 16) >= 0)
		c = (dec % 16) + '0';
	cnt_chars += write(1, &c, 1);
	return (cnt_chars);
}
