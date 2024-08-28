/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:42:44 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/28 16:52:55 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	init_pipex(char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.pid = 0;
	pipex.fd[0] = 0;
	pipex.fd[1] = 0;
	/* pipex.path = ft_path(envp);
	if (ft_strchr(argv[2], 39) != NULL)
		pipex.cmd1 = ft_split_trim(argv[2], 39);
	else
		pipex.cmd1 = ft_split(argv[2], ' ');
	if (ft_strchr(argv[3], 39) != NULL)
		pipex.cmd2 = ft_split_trim(argv[3], 39);
	else
		pipex.cmd2 = ft_split(argv[3], ' '); */
	return (pipex);
}