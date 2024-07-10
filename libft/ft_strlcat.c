/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:39:26 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 11:11:09 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + appends the NUL-terminated string src to the end of dst
 *   It will append at most (size - strlen(dst) - 1) bytes,
 *   NUL-terminating the result.
 * + returns the total length of the string it tried to create
 *   (the initial length of dst plus the length of src)
 * + man strlcat (bsd-library)
 */

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size)
	{
		while (dest[i] && i < size)
			i++;
		while (src[j] && (i + j + 1) < size)
		{
			dest[i + j] = src[j];
			j++;
		}
		if (i < size)
			dest[i + j] = '\0';
	}
	while (src[j])
		j++;
	return (i + j);
}
