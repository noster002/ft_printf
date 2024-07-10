/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:49:33 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 17:32:12 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * + checks for an alphanumeric character
 * + returns a nonzero value if character c is alphanumeric and zero if not
 * + man isalnum
 */

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || \
		(c >= 'A' && c <= 'Z') || \
		(c >= 'a' && c <= 'z'));
}
