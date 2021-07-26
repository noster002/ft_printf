/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:24:51 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/26 11:01:20 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(unsigned long long nbr, int base)
{
	int	count;

	count = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= base;
		count++;
	}
	return (count);
}
