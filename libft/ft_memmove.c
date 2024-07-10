/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:36:23 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 14:22:31 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + copies n bytes from memory area src to memory area dest
 *   The memory areas may overlap:
 *   copying takes place as though the bytes in src are copied first to last
 *   if dest is smaller than src, or last to first if dest is bigger than src,
 *   so that the overlap gets copied before it gets overwritten.
 * + returns a pointer to dest
 * + man memmove
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*save;

	if (dest == NULL && src == NULL)
		return (NULL);
	else if (dest > src)
	{
		while (n > 0)
		{
			n--;
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		}
		return (dest);
	}
	save = dest;
	while (n > 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
		n--;
	}
	return (save);
}
