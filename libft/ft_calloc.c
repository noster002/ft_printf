/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:42:07 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/24 10:41:27 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + allocates memory for an array of nmemb elements of size bytes each
 *   and returns a pointer to the allocated memory
 *   The memory is set to zero.
 *   If nmemb or size is 0, then calloc() returns either NULL,
 *   or a unique pointer value that can later be successfully passed to free().
 * + returns a pointer to the allocated memory,
 *   which is suitably aligned for any built-in type
 *   On error, this function returns NULL.
 * + man calloc
 */

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	n;
	void	*p;

	n = nmemb * size;
	p = malloc(n);
	if (p)
	{
		while (n > 0)
		{
			n--;
			*(char *)(p + n) = '\0';
		}
	}
	return (p);
}
