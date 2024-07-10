/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:48:58 by nosterme          #+#    #+#             */
/*   Updated: 2024/05/02 14:31:01 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + copies no more than n bytes from memory area src to memory area dest,
 *   stopping when the character c is found
 *   If the memory areas overlap, the results are undefined.
 * + returns a pointer to the next character in dest after c,
 *   or NULL if c was not found in the first n characters of src
 * + man memccpy
 */

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		if (*(unsigned char *)dest == (unsigned char)c)
			return (++dest);
		dest++;
		src++;
		n--;
	}
	return (NULL);
}
