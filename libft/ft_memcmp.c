/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:32:39 by dacrespo          #+#    #+#             */
/*   Updated: 2024/02/13 17:38:17 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// It compares an especified number of bytes in two memory blocks.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*b1;
	const unsigned char	*b2;
	size_t				i;

	b1 = s1;
	b2 = s2;
	i = 0;
	while (i < n)
	{
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}
