/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:18:54 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/19 14:28:55 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** @brief Prints an error message to the standard error and exits the program.
 * 
 * This function is used to handle critical errors by outputting a specified
 * error message and exiting the program with a given error code.
 * 
 * @param error_message The error message to display.
 * @param error_code    The exit code with which to terminate the program.
 */
void	error_exit(char *error_message, int error_code)
{
	write(2, error_message, ft_strlen(error_message));
	exit(error_code);
}

/** @brief Frees an array of dynamically allocated strings.
 * 
 * Iterates over an array of strings (char **) and frees the memory for each
 * string, followed by freeing the array itself.
 * 
 * @param array The array of strings to be freed.
 */
void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

/** @brief Cleans up allocated resources and exits the program.
 * 
 * This function is used to free memory associated with the `pipex` structure,
 * display an error message using `perror`, and exit the program with the
 * specified exit code.
 * 
 * @param pipex         Pointer to the pipex structure to clean up.
 * @param error_message The error message to display.
 * @param error_code    The exit code to terminate the program with.
 */
void	cleanup_and_exit(t_pipex *pipex, char *error_message, int error_code)
{
	perror(error_message);
	free_array(pipex->path_name);
	free_array(pipex->cmd1);
	free_array(pipex->cmd2);
	exit(error_code);
}
