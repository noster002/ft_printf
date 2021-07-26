/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:38:59 by nosterme          #+#    #+#             */
/*   Updated: 2021/07/26 11:02:27 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_NBR_H
# define FT_PRINT_NBR_H

int	ft_nbr_len(unsigned long long nbr, int base);
int	ft_write_hex(unsigned long long nbr, unsigned char hex_chars);
int	ft_write_dec(long long nbr);

#endif