/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:25:07 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/24 13:17:45 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Outputs the string ’s’ to the given file descriptor.
 */

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
