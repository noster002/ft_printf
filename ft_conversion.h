/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:36:46 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/21 16:27:53 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSION_H
# define FT_CONVERSION_H
# include "ft_print_nbr.h"

typedef struct s_arguments
{
	va_list	list;
}			t_arguments;

int	ft_conversion(t_arguments arg, t_flags *flag);
int	ft_print_char_conversion(t_arguments arg, t_flags *flag);
int	ft_print_str_conversion(t_arguments arg, t_flags *flag);
int	ft_print_ptr_conversion(t_arguments arg, t_flags *flag);
int	ft_print_nbr_conversion(t_arguments arg, t_flags *flag);
int	ft_print_signed_dec(t_arguments arg, t_flags *flag);
int	ft_print_unsigned_dec(t_arguments arg, t_flags *flag);
int	ft_print_unsigned_hex(t_arguments arg, t_flags *flag);

#endif