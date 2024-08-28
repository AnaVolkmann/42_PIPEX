/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:31:19 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/28 16:45:09 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	handle_imput(argv, envp);
	pipex = init_pipex(argv, envp);
	if (pipe(pipex.fd) == -1)
	{
		//free;
	}
	pipex.pid = fork();
	if (pipex.pid < 0)
	{
		//free;
	}
	if (pipex.pid == 0)
	{
		//child;
	}
	if (pipex.pid > 0)
	{
		//parent;
	}
}
