/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:24:14 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/19 18:53:22 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_initialize_flags(const char *offset, t_flags *flags)
{
	int	cnt_chars;

	ft_memset(flags, 0, sizeof(*flags));
	cnt_chars = ft_check_cases(offset, flags);
	return (cnt_chars);
}
