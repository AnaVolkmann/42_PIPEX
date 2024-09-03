/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:40:28 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/03 19:37:18 by ana-lda-         ###   ########.fr       */
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
/** @brief Sets up and executes a command in the child process with redirected I/O.
 *
 * Redirects standard input to a file and standard output to a pipe. Executes the command specified
 * in `argv[2]` with the given environment.
 *
 * @param argv Array of arguments: `argv[1]` is the input file, `argv[2]` is the command.
 * @param p_fd Pipe file descriptors: `p_fd[0]` for reading, `p_fd[1]` for writing.
 * @param env Environment variables for the command.
 */
void	child_process(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);;
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec_cmd(argv[2], env);
}

/** @brief Sets up and executes a command in the parent process with redirected I/O.
 *
 * Redirects standard output to a file and standard input from a pipe. Executes the command specified
 * in `argv[3]` with the given environment.
 *
 * @param argv Array of arguments: `argv[4]` is the output file, `argv[3]` is the command.
 * @param p_fd Pipe file descriptors: `p_fd[0]` for reading, `p_fd[1]` for writing.
 * @param env Environment variables for the command.
 */
void	parent_process(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec_cmd(argv[3], env);
}