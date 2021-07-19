/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:02:20 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/19 11:45:01 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_FLAGS_H
# define FT_SET_FLAGS_H
# include "boolean.h"

typedef struct s_flags
{
	int	c;
	int	s;
	int	p;
	int	d;
	int	i;
	int	u;
	int	lowercase_x;
	int	uppercase_x;
	int	minus;
	int	zero;
	int	dot;
	int	precision;
	int	hashtag;
	int	space;
	int	plus;
	int	min_field_width;
}		t_flags;

int		ft_initialize_flags(const char *offset, t_flags *flags);
int		ft_check_cases(const char *offset, t_flags *flags);
int		ft_set_conversion_flags(const char *offset, t_flags *flag);
int		ft_set_min_field_width(const char *offset, t_flags *flag);
int		ft_set_precision(const char *offset, t_flags *flag);
t_bool	ft_set_conversion_specifier(char specifier, t_flags *flag);

#endif