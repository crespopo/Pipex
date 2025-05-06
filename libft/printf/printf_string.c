/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:46:43 by dacrespo          #+#    #+#             */
/*   Updated: 2024/04/25 14:58:37 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_string(char *str)
{
	int		i;
	int		count;

	i = 0;
	if (str == NULL)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	count = i;
	return (count);
}
