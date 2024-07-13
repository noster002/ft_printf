/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 05:21:08 by nosterme          #+#    #+#             */
/*   Updated: 2024/07/13 08:15:39 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct	s_result	t_result;

int	check_results(const t_result expected, const t_result test,\
	int (*cmp)(const t_result, const t_result));

/*
 * Variadic function test macros
 */
# include "variadic/wrapper.h"
# include "variadic/test.h"

#endif
