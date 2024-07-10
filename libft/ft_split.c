/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:18:15 by nosterme          #+#    #+#             */
/*   Updated: 2021/06/03 14:57:14 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Allocates (with malloc(3)) and returns an array of strings
 *   obtained by splitting ’s’ using the character ’c’ as a delimiter.
 *   The array must be ended by a NULL pointer.
 *   Frees with free(3).
 * + returns the array of new strings resulting from the split or
 *   NULL if the allocation fails
 */

static void	ft_free(char **p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return ;
}

static size_t	ft_arrlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static size_t	ft_substrlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_fill(char **arr, const char *s, char c)
{
	size_t	i;

	while (*s)
	{
		while (*s == c)
			s++;
		if (!(*s))
			break ;
		*arr = (char *)malloc((ft_substrlen(s, c) + 1) * sizeof(char));
		if (!(*arr))
			return (0);
		i = 0;
		while (*s && *s != c)
		{
			(*arr)[i] = *s;
			i++;
			s++;
		}
		(*arr)[i] = '\0';
		arr++;
	}
	*arr = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **)malloc((ft_arrlen(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_fill(arr, s, c))
	{
		ft_free(arr);
		return (NULL);
	}
	return (arr);
}
