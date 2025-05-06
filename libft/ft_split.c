/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:58:15 by dacrespo          #+#    #+#             */
/*   Updated: 2024/03/03 11:57:03 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// It divides an string using char 'c' as delimiter.
static int	word_count(char const *str, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			counter++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (counter);
}

static char	*extract_word(char const *str, char c, size_t *start)
{
	size_t	end;
	char	*word;

	while (str[*start] && str[*start] == c)
		(*start)++;
	end = *start;
	while (str[end] && str[end] != c)
		end++;
	word = ft_substr(str, *start, end - *start);
	if (!word)
		return (NULL);
	*start = end;
	return (word);
}

static void	ft_free_all(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free (array[i]);
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	words;
	size_t	start;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	words = word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (i < words)
	{
		array[i] = extract_word(s, c, &start);
		if (!array[i])
		{
			ft_free_all(i, array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
