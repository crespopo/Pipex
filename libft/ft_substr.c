/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:53:45 by dacrespo          #+#    #+#             */
/*   Updated: 2025/05/06 16:04:45 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// It allocates and return a substring of the string 's'
// starting from index start with max. 'len' using malloc.
// Returns null if mem allocation fails.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (len > slen - start)
		sub = (char *)malloc((slen - start + 1) * sizeof(char));
	else
		sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && len > 0)
	{
		sub[i] = s[start];
		start++;
		len--;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
