/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:16:59 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 13:40:57 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Allocates (with malloc(3)) and returns a new string,
 *   which is the result of the concatenation of ’s1’(prefix) and ’s2’(suffix).
 * + returns the new string or NULL if the allocation fails
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}
