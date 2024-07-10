/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:34:40 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/31 10:07:16 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Outputs the integer ’n’ to the given file descriptor.
 */

static int	ft_abs(int n)
{
	int	mask;

	mask = n >> 31;
	return ((n ^ mask) - mask);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n / 10)
		ft_putnbr_fd(ft_abs(n / 10), fd);
	ft_putchar_fd((ft_abs(n % 10) + '0'), fd);
}
