/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:42:44 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/03 17:13:58 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** @brief function to inicialize the struct
 * @param argv - arguments from the command-line
 * @param envp - 
 */
t_pipex	init_pipex(char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.pid = 0;
	pipex.fd[0] = 0;
	pipex.fd[1] = 0;
	pipex.path_name = get_path_name(envp);
	if (ft_strchr(argv[2], SINGLE_QUOTE) != NULL)
		pipex.cmd1 = ft_split_trim(argv[2], SINGLE_QUOTE);
	else
		pipex.cmd1 = ft_split(argv[2], ' ');
	if (ft_strchr(argv[3], SINGLE_QUOTE) != NULL)
		pipex.cmd2 = ft_split_trim(argv[3], SINGLE_QUOTE);
	else
		pipex.cmd2 = ft_split(argv[3], ' ');
	return (pipex);
}

/** @brief Handles the input arguments, exits the program and prints error, if error.
 * @param argc The number of arguments.
 * @param argv An array of strings containing the arguments.
 * */
void handle_input(int argc, char **argv)
{
	int i;

	if (argc < 5)
		error_exit("Error: Incorrect number of arguments. Usage: ./program file1 cmd1 cmd2 file2\n", EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0' || argv[i][0] == '\'')
			error_exit("Error: Invalid argument provided.\n", EXIT_FAILURE);
		i++;
	}
}

/** @brief Extracts and processes the PATH environment variable into a list of directories.
 *  @param envp The array of environment variables.
 *  @return An array of strings, each representing a directory from the PATH, or NULL on failure. */
char **get_path_name(char **envp) 
{
	char **path;
	char *temp;
	int i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	temp = ft_strtrim(envp[i], "PATH=");
	path = ft_split(temp, ':');
	i = 0;
	while (path[i]) 
		path[i] = ft_strjoin(path[i], "/");
	free(temp);
	return (path);
}
