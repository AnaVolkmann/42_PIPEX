/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:42:44 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/19 14:56:37 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** @brief Initializes the pipex structure with command and path information.
 * 
 * This function extracts the command-line arguments, checks if any command
 * contains single quotes, and splits the command strings into arrays. It also
 * retrieves and processes the PATH environment variable.
 * 
 * @param argv Array of command-line arguments
 *  (input file, cmd1, cmd2, output file).
 * @param env  Array of environment variables passed from the shell.
 * @return t_pipex Initialized pipex structure containing command and path info.
 */
t_pipex	init_pipex(char **argv, char **env)
{
	t_pipex	pipex;

	pipex.pid = 0;
	pipex.fd[0] = 0;
	pipex.fd[1] = 0;
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

/** @brief Validates the input arguments and exits the program
 *  if any errors are found.
 * 
 * This function checks that the correct number of arguments are passed and that
 * none of the command-line arguments are empty or invalid. It will exit with an
 * error message if the input is incorrect.
 * 
 * @param argc The number of command-line arguments.
 * @param argv Array of command-line arguments
 *  (input file, cmd1, cmd2, output file).
 */
void	handle_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5)
		error_exit ("Error\nCorrect usage: %s file1 cmd1 cmd2 file2\n", \
		EXIT_FAILURE);
	i = -1;
	while (argv[++i])
	{
		if (argv[i][0] == 0 || argv[i][0] == 39)
			error_exit("Error\nInvalid arguments\n", EXIT_FAILURE);
		j = 0;
		while (!ft_isspace(argv[i][j]))
		{
			if (!argv[i][++j])
				error_exit("Error\nEmpty string\n", EXIT_FAILURE);
		}
	}
}

/** @brief Extracts the PATH env. variables and splits it into directories.
 * 
 * This function searches the environment variables 
 * for the PATH, removes the "PATH="
 * prefix, and splits the string by ':' into an array
 *  of directory paths. Each directory
 * path is appended with a '/' for easier command concatenation later.
 * 
 * @param env Array of environment variables.
 * @return char** Array of directories extracted from the PATH.
 */
char	**get_path_name(char **env)
{
	char	**path;
	char	*temp;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	temp = ft_strtrim(env[i], "PATH=");
	path = ft_split(temp, ':');
	i = -1;
	while (path[++i])
		path[i] = ft_strjoin(path[i], "/");
	free(temp);
	return (path);
}

/** @brief Splits a string based on a delimiter and trims
 *  whitespace from each part.
 * 
 * This function first trims leading and trailing whitespace
 *  from the input string,
 * splits it by a given delimiter, and trims each resulting substring.
 * 
 * @param str The input string to be split and trimmed.
 * @param c   The delimiter character used to split the string.
 * @return char** Array of trimmed substrings or NULL if an error occurs.
 */
char	**ft_split_trim(char *str, char c)
{
	char	*first_trim;
	char	**split;
	char	**trim;
	int		i;

	first_trim = ft_strtrim(str, " ");
	split = ft_split(first_trim, c);
	free(first_trim);
	trim = ft_calloc(sizeof(char *), 3);
	i = -1;
	while (split[++i])
	{
		trim[i] = ft_strtrim(split[i], " ");
	}
	free_array(split);
	return (trim);
}
