/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:40:28 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/03 19:10:53 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int in_or_out)
{
	int fd_result;

	if (in_or_out == 0)
		fd_result = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		fd_result = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_result == -1)
		exit(0);
	return (fd_result);
}

void	exec_cmd(char *cmd, char **env)
{
	
}

// int dup2(int fd1, int fd2) : it will close
// fd2 and duplicate the value of fd2 to fd1
//else said, it will redirect fd1 to fd2
void	child_process(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);;
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec_cmd(argv[2], env);
}

void	parent_process(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec_cmd(argv[3], env);
}