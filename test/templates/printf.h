/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:27:22 by nosterme          #+#    #+#             */
/*   Updated: 2024/07/13 08:18:19 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_PRINTF_H
# define TEMPLATE_PRINTF_H

# include "libtest.h"
# include <stdio.h>
# include <unistd.h>
# include "libftprintf.h"
# include "types/result.h"
# include "utils.h"

# define PRINTF(params)		VARIADIC_TEST_WRAPPER(PRINTF_TEST, params)
# define PRINTF_TEST(params)	VARIADIC_COPYCAT_TEST(PRINTF_COMPUTE_RESULTS,\
				printf, ft_printf, params, result_cmp)

# define PRINTF_COMPUTE_RESULTS(printf_implementation, params, result)	{\
	char	eof;\
	int		std_out;\
\
	eof = EOF;\
	std_out = save_fd_or_exit(STDOUT_FILENO);\
	pipe_fds_or_exit(STDIN_FILENO, STDOUT_FILENO);\
	result.chars_written = printf_implementation(params);\
	write_or_exit(STDOUT_FILENO, &eof, sizeof(eof));\
	read_or_exit(STDIN_FILENO, result.buffer, sizeof(result.buffer));\
	restore_fd_or_exit(std_out, STDOUT_FILENO);\
}

#endif
