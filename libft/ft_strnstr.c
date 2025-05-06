/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:30:24 by dacrespo          #+#    #+#             */
/*   Updated: 2024/02/14 16:11:55 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Finds a substring where no more than len characters are searched.
If the complete substring is found, it returns a pointer to the current
position in the haystack. Otherwise, null.*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] != '\0' && haystack[i + j] == needle[j]
				&& (i + j) < len)
				j++;
			if (needle[j] == '\0')
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
