/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:03:35 by nosterme          #+#    #+#             */
/*   Updated: 2024/07/13 08:12:19 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		save_fd_or_exit(int fd)
{
	int	dup_fd;

	dup_fd = dup(fd);
	if (dup_fd == -1)
		exit_perror("save_fd: dup");
	return (dup_fd);
}

void	restore_fd_or_exit(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		exit_perror("restore_fd: dup2");
}

typedef enum	e_pipe
{
	read_end,
	write_end,
	nbr_pipe_ends,
}	t_pipe;

void	pipe_fds_or_exit(int fd_read, int fd_write)
{
	int	fd[nbr_pipe_ends];

	if (pipe(fd) == -1)
		exit_perror("pipe_fds: pipe");
	else if (dup2(fd[read_end], fd_read) == -1 ||\
		dup2(fd[write_end], fd_write) == -1)
		exit_perror("pipe_fds: dup2");
}

void	read_or_exit(int fd, void *buffer, size_t size)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, size);
	if (bytes_read == -1)
		exit_perror("read_or_exit: read");
	((char *)buffer)[bytes_read] = '\0';
}

void	write_or_exit(int fd, void *buffer, size_t size)
{
	ssize_t	bytes_written;

	bytes_written = write(fd, buffer, size);
	if (bytes_written == -1)
		exit_perror("write_or_exit: write");
}
