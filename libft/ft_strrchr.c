/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:33:45 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 15:05:11 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + returns a pointer to the last occurrence of the character c
 *   in the string s or NULL if the character is not found
 *   If c is specified as'\0',
 *   these functions return a pointer to the terminator.
 * + man strrchr
 */

char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	while (s >= start && *s != c)
		s--;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
