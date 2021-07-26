/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_conversion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:27:17 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/21 21:44:34 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr_conversion(t_arguments *arg, t_flags *flag)
{
	if (flag->d || flag->i)
		return (ft_print_signed_dec(arg, flag));
	if (flag->u)
		return (ft_print_unsigned_dec(arg, flag));
	if (flag->lowercase_x || flag->uppercase_x)
		return (ft_print_unsigned_hex(arg, flag));
	return (0);
}
