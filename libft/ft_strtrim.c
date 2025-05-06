/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:48:35 by dacrespo          #+#    #+#             */
/*   Updated: 2024/03/03 19:41:41 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Removes the specified characters from the beginning and end of a given string
//and returns the resulting string.
//Returns a trimmed copy of s1.
//It returns null if memory allocation fails.

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len_trim;
	char	*str_trim;

	str_trim = NULL;
	if (s1 != NULL && set != NULL)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start ++;
		while (end > start && s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end --;
		if (end > start)
			len_trim = end - start;
		else
			len_trim = 0;
		str_trim = (char *)malloc(len_trim + 1);
		if (str_trim != NULL)
			ft_strlcpy(str_trim, &s1[start], len_trim + 1);
	}
	return (str_trim);
}
