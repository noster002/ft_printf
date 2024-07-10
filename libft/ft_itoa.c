/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:35:19 by nosterme          #+#    #+#             */
/*   Updated: 2021/06/03 15:26:47 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Allocates (with malloc(3)) and returns a string representing the integer
 *   received as an argument.
 * + returns the string representing the integer
 *   or NULL if the allocation fails
 */

static size_t	ft_nbrlen(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int n)
{
	int	mask;

	mask = n >> 31;
	return ((n ^ mask) - mask);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;

	i = ft_nbrlen(n);
	s = (char *)malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n == 0)
		s[0] = '0';
	else if (n < 0)
		s[0] = '-';
	while (n)
	{
		s[i - 1] = ft_abs(n % 10) + '0';
		n /= 10;
		i--;
	}
	return (s);
}
