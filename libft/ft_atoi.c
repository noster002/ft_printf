/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:14:31 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 11:41:16 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + converts the initial portion of the string pointed to by nptr to int
 * + returns converted value
 * + man atoi
 */

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v' || \
		*nptr == '\f' || *nptr == '\r' || *nptr == ' ')
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
