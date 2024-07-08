/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:24:43 by szhong            #+#    #+#             */
/*   Updated: 2024/07/08 15:45:04 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

/**
 * @brief Counts the number of words in a string separated by a delimiter.
 *
 * Counts the number of words in the string @p s, using the delimiter @p c.
 *
 * @param s The string to count words in.
 * @param c The delimiter character.
 * @return The number of words in the string.
 */
static size_t	count_words(char const *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c && *s)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

/*
 * it is a tailed version for the split function
 */
static char	*get_word(char *tar_word, char separator)
{
	static int		cursor;
	char			*word;
	int				i;
	int				len;

	len = 0;
	i = 0;
	while (tar_word[cursor] == separator)
		++cursor;
	while ((tar_word[cursor] != separator) && tar_word[cursor + len])
		len++;
	word = malloc(sizeof(char) * ((size_t)len + 1));
	if (word == NULL)
		return (NULL);
	while ((tar_word[cursor] != separator) && tar_word[cursor])
		word[i++] = tar_word[cursor++];
	word[i] = '\0';
	return (word);
}

/*this is a modified version of ft_split.
 * because the program requires somewhat similar structure
 * of argv which is the first position should contain some values*/
char	**ps_split(char const *s, char c)
{
	int			words_count;
	char		**vector;
	int			i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	vector = malloc(sizeof(char *) *(size_t)(words_count + 2));
	if (vector == NULL)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (0 == i)
		{
			vector[i] = (char *)malloc(sizeof(char));
			if (!vector[i])
				return (NULL);
			vector[i++][0] = '\0';
			continue ;
		}
		vector[i++] = get_word((char *)s, c);
	}
	vector[i] = NULL;
	return (vector);
}
