/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:31:19 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/03 19:35:25 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		p_fd[2];

	p_fd[0] = 0;
	p_fd[1] = 0;
	pipex = init_pipex(argv, env);
	handle_input(argc, argv);
	if (pipe(p_fd) == -1)
		cleanup_and_exit(&pipex, "Pipe creation failed", 1);
	pipex.pid = fork();
	if (pipex.pid < 0)
		cleanup_and_exit(&pipex, "Fork failed", 1);
	if (pipex.pid == 0)
	{
		child_process(argv, p_fd, env);
	}
	if (pipex.pid > 0)
	{
		parent_process(argv, p_fd, env);
	}
}
