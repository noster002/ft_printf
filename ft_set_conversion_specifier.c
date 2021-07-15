/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_conversion_specifier.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:21:03 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/14 16:46:41 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	ft_check_valid_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static t_bool	ft_compare_char(char c1, char c2)
{
	return (c1 == c2);
}

t_bool	ft_set_conversion_specifier(char specifier, t_flags *flag)
{
	flag->c = ft_compare_char(specifier, 'c');
	flag->s = ft_compare_char(specifier, 's');
	flag->p = ft_compare_char(specifier, 'p');
	flag->d = ft_compare_char(specifier, 'd');
	flag->i = ft_compare_char(specifier, 'i');
	flag->u = ft_compare_char(specifier, 'u');
	flag->lowercase_x = ft_compare_char(specifier, 'x');
	flag->uppercase_x = ft_compare_char(specifier, 'X');
	return (ft_check_valid_conversion(specifier));
}
