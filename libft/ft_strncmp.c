/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:58:45 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 11:20:46 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + compares the first n bytes of the strings s1 and s2
 * + returns an integer less than, equal to, or greater than zero
 *   if the first n bytes of s1 is found, respectively,
 *   to be less than, to match, or be greater than s2
 *   For a nonzero return value, the sign is determined
 *   by the sign of the difference between the first pair of characters
 *   (interpreted as unsigned char) that differ in s1 and s2.
 *   If n is zero, the return value is zero.
 * + man strncmp
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && n > 1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
}
