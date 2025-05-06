/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:54:52 by dacrespo          #+#    #+#             */
/*   Updated: 2024/02/13 17:41:40 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Converts a string to its integer equivalent.
//If the string doesn't represent a valid number, it returns 0.
int	ft_atoi(const char *str)
{
	int	s;
	int	result;

	s = 1;
	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= s;
	return (result);
}
