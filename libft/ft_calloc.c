/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:09:36 by dacrespo          #+#    #+#             */
/*   Updated: 2025/05/06 16:11:59 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Reserves a contiguous block of memory for a specified number of elements.
//Initializes each byte of the reserved memory to 0.
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);

	i = 0;
	while (i < count * size)
		ptr[i++] = 0;

	return (ptr);
}

