/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:57:20 by nosterme          #+#    #+#             */
/*   Updated: 2024/07/13 07:18:34 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIADIC_TEST_H
# define VARIADIC_TEST_H

# define	VARIADIC_COPYCAT_TEST(COMPUTE_RESULTS, original, copycat,\
			params, result_cmp)	{\
	t_result	original_result;\
	t_result	copycat_result;\
\
	COMPUTE_RESULTS(original, params, original_result);\
	COMPUTE_RESULTS(copycat, params, copycat_result);\
	check_results(original_result, copycat_result, result_cmp);\
}\

#endif
