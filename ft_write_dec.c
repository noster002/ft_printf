/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:15:21 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/20 20:20:20 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_dec(long long nbr)
{
	int		cnt_chars;
	char	c;

	cnt_chars = 0;
	if (nbr >= 10)
		cnt_chars = ft_write_dec(nbr / 10);
	c = nbr % 10 + '0';
	cnt_chars += write(1, &c, 1);
	return (cnt_chars);
}
