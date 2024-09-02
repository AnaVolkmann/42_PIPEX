/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:26:16 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/02 16:47:33 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

# define EXIT_COMMAND 127
# define SINGLE_QUOTE 39

typedef struct s_pipex
{
	int	pid;
	int	fd[2];
	char **cmd1;
	char **cmd2;
	char **path_name;
}				t_pipex;

/**********************UTILS********************/

t_pipex	init_pipex(char **argv, char **envp);
void	handle_imput(int argc, char **argv);

/**********************ERROR********************/

void	error_exit(char *error_message, int error_exit);
void	free_array(char **array);
void	free_and_exit(t_pipex *pipex, char *error, int error_exit);
char	**get_path_name(char **envp);

/********************LIBFT_UTILS****************/

char	**ft_split_trim(char *str, char c);

#endif