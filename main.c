/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:31:19 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/03 18:09:25 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex = init_pipex(argv, envp);
	handle_imput(argc, argv);
	if (pipe(pipex.fd) == -1)
		cleanup_and_exit(&pipex, "Pipe creation failed", EXIT_FAILURE);
	pipex.pid = fork();
	if (pipex.pid < 0)
		cleanup_and_exit(&pipex, "Fork failed", EXIT_FAILURE);
	if (pipex.pid == 0)
	{
		//child;
		//execute cmd1 and write to pipe
	}
	if (pipex.pid > 0)
	{
		//parent;
		//read from the pipe and execute cmd2
	}
}
