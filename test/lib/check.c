/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:17:01 by nosterme          #+#    #+#             */
/*   Updated: 2024/07/13 06:58:20 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

int	check_results(const t_result expected, const t_result test,\
	int (*cmp)(const t_result, const t_result))
{
	return ((*cmp)(expected, test));
}
