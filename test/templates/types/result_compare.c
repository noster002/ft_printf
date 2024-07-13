/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 06:43:17 by nosterme          #+#    #+#             */
/*   Updated: 2024/07/13 07:33:50 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"

int	result_cmp(const t_result expected, const t_result test)
{
	return (strcmp(expected.buffer, test.buffer) |\
			(expected.chars_written - test.chars_written));
}
