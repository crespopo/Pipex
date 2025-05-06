/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:12:34 by dacrespo          #+#    #+#             */
/*   Updated: 2024/02/13 17:32:16 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The function searches for the first occurrence of a specific byte within
a memory block.
The function returns a pointer to the found byte.
The function returns a NULL if c is not found within the first n bytes of
the memory block.*/
void	*ft_memchr(const void *s, int c, size_t n)

{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return (&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
