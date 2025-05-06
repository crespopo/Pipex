/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:19:00 by dacrespo          #+#    #+#             */
/*   Updated: 2025/05/06 16:18:57 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Checks if a 'c' is an alphabetic character (letter (a-z, A-Z)

int	ft_isalpha(int str)
{
	if (str < 'A' || str > 'Z' && str < 'a' || str > 'z')
		return (0);
	return (1);
}


