/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:54:42 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 14:42:51 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Allocates (with malloc(3)) and returns a copy of ’s1’
 *   with the characters specified in ’set’ removed from the beginning
 *   and the end of the string.
 * + returns the trimmed string or NULL if the allocation fails
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	s = (char *)malloc(end - start + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		s[i] = s1[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
