/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:31:19 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/02 17:00:34 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_pipex(t_pipex pipex)
{
    printf("fd[0]: %d\n", pipex.fd[0]);
    printf("fd[1]: %d\n", pipex.fd[1]);
    printf("pid: %d\n", pipex.pid);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex = init_pipex(argv, envp);
	handle_imput(argc, argv);
    ft_printf("%s\n", pipex);
	/* if (pipe(pipex.fd) == -1)
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
	} */
}
