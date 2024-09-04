/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:31:19 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/04 17:13:09 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex = init_pipex(argv, env);
	handle_input(argc, argv);
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
