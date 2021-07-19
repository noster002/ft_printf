/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:00:04 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/19 18:40:48 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(t_arguments arg, t_flags *flag)
{
	if (flag->c)
		return (ft_print_char_conversion(arg, flag));
	if (flag->s)
		return (ft_print_str_conversion(arg, flag));
	if (flag->p)
		return (ft_print_ptr_conversion(arg, flag));
	/*if (flag->d || flag->i || flag->u || flag->lowercase_x || flag->uppercase_x)
		return (ft_print_nbr_conversion(arg, flag));*/
	return (write(1, "%", 1));
}
