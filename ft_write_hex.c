/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:49:40 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/26 11:03:12 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex(unsigned long long nbr, unsigned char hex_chars)
{
	int		cnt_chars;
	char	c;

	cnt_chars = 0;
	if (nbr >= 16)
		cnt_chars = ft_write_hex(nbr / 16, hex_chars);
	if ((nbr % 16) >= 10)
		c = (nbr % 16) + hex_chars - 10;
	else
		c = (nbr % 16) + '0';
	cnt_chars += write(1, &c, 1);
	return (cnt_chars);
}
