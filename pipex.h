/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:26:16 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/03 18:42:44 by ana-lda-         ###   ########.fr       */
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
	char **cmd1;
	char **cmd2;
	char **path_name;
}				t_pipex;

/**********************UTILS********************/

t_pipex	init_pipex(char **argv, char **envp);
void	handle_input(int argc, char **argv);
char	**get_path_name(char **env);
char	**ft_split_trim(char *str, char c);

/**********************ERROR********************/

void	error_exit(char *error_message, int error_exit);
void	free_array(char **array);
void	cleanup_and_exit(t_pipex *pipex, char *error_message, int error_code);


/***********************PIPEX********************/

int		open_file(char *file, int in_or_out);
void	child_process(char **argv, int *p_fd, char **env);
void	parent_process(char **argv, int *p_fd, char **env);

#endif