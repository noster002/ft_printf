/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:03:34 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/19 19:47:51 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len_hex(long long nbr)
{
	int	count;

	count = 0;
	if (!nbr)
		return (1);
	if (nbr < 0)
		nbr += 4294967296;
	while (nbr)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}
