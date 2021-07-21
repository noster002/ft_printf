/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width_dec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:48:18 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/20 21:11:34 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_width_dec(long long nbr, int cnt_width, t_flags *flag)
{
	int	nbr_len;

	nbr_len = ft_nbr_len(nbr, 10);
	if (!cnt_width)
	{
		if (nbr < 0 || flag->plus || flag->space)
			cnt_width++;
		if (flag->precision > nbr_len)
			cnt_width += flag->precision;
		else
			cnt_width += nbr_len;
	}
	return (cnt_width);
}
