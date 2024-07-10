/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:03:47 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 13:36:35 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Applies the function ’f’ to each character of the string ’s’
 *   to create a new string (with malloc(3))
 *   resulting from successive applications of ’f’.
 * + returns the string created from the successive applications of ’f’
 *   or NULL if the allocation fails
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
