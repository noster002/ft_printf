/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 07:56:18 by nosterme          #+#    #+#             */
/*   Updated: 2024/07/13 08:09:21 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	exit_perror(const char *message);
int		save_fd_or_exit(int fd);
void	restore_fd_or_exit(int oldfd, int newfd);
void	pipe_fds_or_exit(int fd_read, int fd_write);
void	read_or_exit(int fd, void *buffer, size_t size);
void	write_or_exit(int fd, void *buffer, size_t size);

#endif
