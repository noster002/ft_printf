/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:04:36 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 14:23:53 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + fills the first n bytes of the memory area pointed to by s with '\0'
 * + no return
 * + man bzero
 */

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(unsigned char *)s = '\0';
		s++;
		n--;
	}
}
