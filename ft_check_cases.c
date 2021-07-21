/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:44:10 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/21 11:45:42 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_cases(const char *offset, t_flags *flags)
{
	int	cnt_chars;

	cnt_chars = ft_set_conversion_flags(&offset[0], flags);
	cnt_chars += ft_set_min_field_width(&offset[cnt_chars], flags);
	if (offset[cnt_chars] == '.')
		cnt_chars += ft_set_precision(&offset[cnt_chars], flags);
	if (ft_set_conversion_specifier(offset[cnt_chars], flags))
		return (cnt_chars + 2);
	return (1);
}
