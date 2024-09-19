/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:40:28 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/19 14:56:59 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** @brief Executes the child process logic.
 * 
 * The child process reads input from the specified input file, redirects the
 * write end of the pipe as its standard output (stdout), and then executes
 * the first command (cmd1).
 * 
 * @param pipex  Pointer to the pipex structure containing pipe information.
 * @param infile Path to the input file.
 * @param env    Array of environment variables passed from the shell.
 */
void	child_process(t_pipex *pipex, char *infile, char **env)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		cleanup_and_exit(pipex, infile, EXIT_FAILURE);
	close(pipex->fd[0]);
	dup2(fd, 0);
	dup2(pipex->fd[1], 1);
	close(pipex->fd[1]);
	exec(pipex, env, 'c');
}

/** @brief Executes the parent process logic.
 * 
 * The parent process waits for the child to finish, reads input from the pipe's
 * read end (fd[0]), redirects it as its standard input (stdin), and then writes
 * the output to the specified output file by executing the second
 *  command (cmd2).
 * 
 * @param pipex   Pointer to the pipex structure containing pipe information.
 * @param outfile Path to the output file.
 * @param env     Array of environment variables passed from the shell.
 */
void	parent_process(t_pipex *pipex, char *outfile, char **env)
{
	int	fd;

	wait(NULL);
	fd = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fd < 0)
		cleanup_and_exit(pipex, outfile, EXIT_FAILURE);
	close(pipex->fd[1]);
	dup2(fd, 1);
	dup2(pipex->fd[0], 0);
	close(pipex->fd[0]);
	exec(pipex, env, 'p');
}

/** @brief Attempts to execute a command from the given PATH directories.
 * 
 * Iterates through the directories in the PATH (stored in `pipex->path_name`),
 * appends the command name to each directory, and tries to execute the command
 * using `execve`. If successful, the function does not return.
 * 
 * @param pipex Pointer to the pipex structure containing the
 *  command and path information.
 * @param i     Index of the PATH directory being checked.
 * @param cmd   Array of strings representing the command and its arguments.
 * @param env   Array of environment variables passed from the shell.
 */
void	exec_cmd_path(t_pipex *pipex, int i, char **cmd, char **env)
{
	char	*original_path;
	char	*joined_path;

	original_path = ft_strdup(pipex->path_name[i]);
	joined_path = ft_strjoin(original_path, cmd[0]);
	if (!joined_path)
	{
		perror("ft_strjoin failed");
		exit(EXIT_FAILURE);
	}
	execve(joined_path, cmd, env);
	free(joined_path);
}

/** @brief Executes a command (cmd1 or cmd2) based on the process type.
 * 
 * This function loops through the directories in the PATH, attempts to find
 * the appropriate command (either cmd1 for the child or cmd2 for the parent),
 * and executes it using `execve`. If no matching command is found, the program
 * will exit with a command-not-found error.
 * 
 * @param pipex     Pointer to the pipex structure containing 
 * command and path info.
 * @param env       Array of environment variables passed from the shell.
 * @param exec_type Type of execution: 'c' for child (cmd1)
 *  or 'p' for parent (cmd2).
 */
void	exec(t_pipex *pipex, char **env, char exec_type)
{
	int	i;

	i = 0;
	if (exec_type == 'c')
	{
		while (pipex->path_name[i])
		{
			exec_cmd_path(pipex, i, pipex->cmd1, env);
			i++;
		}
		cleanup_and_exit(pipex, pipex->cmd1[0], EXIT_COMMAND);
	}
	if (exec_type == 'p')
	{
		while (pipex->path_name[i])
		{
			exec_cmd_path(pipex, i, pipex->cmd2, env);
			i++;
		}
		cleanup_and_exit(pipex, pipex->cmd2[0], EXIT_COMMAND);
	}
}
