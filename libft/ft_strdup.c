/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:39:08 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 10:41:28 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + duplicates string s into memory obtained with malloc(3);
 *   can be freed with free(3)
 * + returns a pointer to the duplicated string
 *   It returns NULL if insufficient memory was available.
 * + man strdup
 */

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	dup = (char *)malloc(i + 1);
	if (dup)
	{
		dup[i] = '\0';
		while (i > 0)
		{
			i--;
			dup[i] = s[i];
		}
	}
	return (dup);
}
