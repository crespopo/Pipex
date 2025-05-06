/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:28:37 by dacrespo          #+#    #+#             */
/*   Updated: 2025/05/06 16:09:11 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Assigns a value of 0 to a memory block
//Returns nothing
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
