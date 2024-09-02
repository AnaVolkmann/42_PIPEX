/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:27:51 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/09/02 16:49:15 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
