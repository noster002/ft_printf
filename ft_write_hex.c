/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:49:40 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/20 21:14:12 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex(long long nbr)
{
	int		cnt_chars;
	char	c;

	cnt_chars = 0;
	if (nbr >= 16)
		cnt_chars = ft_write_hex(nbr / 16);
	if ((nbr % 16) >= 10)
		c = (nbr % 16) + 'a' - 10;
	else if ((nbr % 16) >= 0)
		c = (nbr % 16) + '0';
	cnt_chars += write(1, &c, 1);
	return (cnt_chars);
}