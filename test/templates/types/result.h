/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 06:19:53 by nosterme          #+#    #+#             */
/*   Updated: 2024/07/13 07:52:53 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESULT_H
# define RESULT_H

# include <string.h>

# define BUFSIZE	4096

typedef struct	s_result
{
	char	buffer[BUFSIZE];
	int		chars_written;
}			t_result;

int	result_cmp(const t_result expected, const t_result test);

#endif
