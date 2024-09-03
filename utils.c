/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:42:44 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/03 18:56:03 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** @brief function to inicialize the struct
 * @param argv - arguments from the command-line
 * @param env - 
 */
t_pipex	init_pipex(char **argv, char **env)
{
	t_pipex	pipex;

	pipex.pid = 0;
	pipex.path_name = get_path_name(env);
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

	if (argc != 5)
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
char	**get_path_name(char **envp)
{
	char	**path;
	char	*temp;
	int		i;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
		i++;
	temp = ft_strtrim(envp[i], "PATH=");
	path = ft_split(temp, ':');
	i = 0;
	while (path[i++])
		path[i] = ft_strjoin(path[i], "/");
	free(temp);
	return (path);
}


/** @brief Splits a string into an array of strings, removing whitespace from each element.
 * @param str The string to be split and trimmed.
 * @param c The delimiter character used to split the string.
 * @return An array of strings, where each element is a trimmed substring of 
 * the original string, or NULL if an error occurs. */
char	**ft_split_trim(char *str, char c)
{
	char	*first_trim;
	char	**split;
	char	**trim;
	int		i;

	i = 0;
	first_trim = ft_strtrim(str, " ");
	split = ft_split(first_trim, c);
	free(first_trim);
	while (split[i])
		i++;
	trim = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (split[i++])
		trim[i] = ft_strtrim(split[i], " ");
	free_array(split);
	return (trim);
}
