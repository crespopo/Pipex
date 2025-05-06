/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:17:38 by dacrespo          #+#    #+#             */
/*   Updated: 2024/03/09 17:36:36 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//It locates the final ocurrence of the character 'c'.
//If the caracter is found, it returns a pointer to that position.
//If not found, it returns null.

char	*ft_strrchr(const char *s, int c)
{
	int			i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		else
			i--;
	}
	return (0);
}
