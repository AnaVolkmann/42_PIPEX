/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:18:54 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/04 17:00:29 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "pipex.h"

/** @brief exits the program w/ am error message and code
 * @param error_message - the ,ssage to display
 * @param error_exit- an error code to exit*/
void	error_exit(char *error_message, int error_code)
{
	write(2, error_message, ft_strlen(error_message));
	exit(error_code);
}

/** @brief Frees an allocated array of strings.
 * Frees the memory allocated for each string in the array,
 * and the array itself.
 * @param array The array of strings to be freed.*/
void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i++])
		free(array[i]);
	free(array);
}

/** @brief Cleans up the resources allocated for the pipex structure and exits the program.
 * @param pipex The pipex structure.
 * @param error The error message to display.
 * @param error_exit The error code to exit with. */
void	cleanup_and_exit(t_pipex *pipex, char *error_message, int error_code)
{
	perror(error_message);
	free_array(pipex->path_name);
	free_array(pipex->cmd1);
	free_array(pipex->cmd2);
	exit(error_code);
} 
