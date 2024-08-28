/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:26:16 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/08/28 16:52:55 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

# define EXIT_COMMAND 127

typedef struct s_pipex
{
	int	pid;
	int	fd[2];
	char **cmd1;
	char **cmd2;
	char **path;
}				t_pipex;

/**********************UTILS********************/

t_pipex	init_pipex(char **argv, char **envp);

#endif