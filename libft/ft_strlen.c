/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:17:23 by dacrespo          #+#    #+#             */
/*   Updated: 2025/05/06 15:56:39 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Returns the length of the string 's'.

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
