/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:31:19 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/19 14:27:33 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** @brief Main function to execute the pipex program.
 * 
 * The program creates a pipe, forks a child process, and redirects the output
 * of the first command (cmd1) into the second command (cmd2) via the pipe.
 * 
 * @param argc The number of arguments passed from the command line.
 * @param argv Array of arguments passed from the command line.
 *             argv[1]: Input file
 *             argv[2]: First command to execute (cmd1)
 *             argv[3]: Second command to execute (cmd2)
 *             argv[4]: Output file
 * @param env  Array of environment variables passed from the shell.
 * @return int Exit code of the program.
 */
int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	handle_input(argc, argv);
	pipex = init_pipex(argv, env);
	if (pipe(pipex.fd) == -1)
		cleanup_and_exit(&pipex, "Pipe creation failed", 1);
	pipex.pid = fork();
	if (pipex.pid < 0)
		cleanup_and_exit(&pipex, "Fork failed", 1);
	if (pipex.pid == 0)
	{
		child_process(&pipex, argv[1], env);
	}
	if (pipex.pid > 0)
	{
		parent_process(&pipex, argv[4], env);
	}
}
