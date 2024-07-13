/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:28:36 by nosterme          #+#    #+#             */
/*   Updated: 2024/07/13 07:22:40 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIADIC_WRAPPER_H
# define VARIADIC_WRAPPER_H

# define VARIADIC_TEST_WRAPPER(test, params)	{\
	pid_t	test_pid;\
	int		status;\
\
	test_pid = fork();\
	if (test_pid == -1)\
		perror("fork");\
	else if (test_pid == 0)\
	{\
		test(params);\
		_exit(EXIT_SUCCESS);\
	}\
	else\
		waitpid(test_pid, &status, 0);\
}\

#endif
