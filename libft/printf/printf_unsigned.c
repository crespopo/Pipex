/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:46:46 by dacrespo          #+#    #+#             */
/*   Updated: 2024/04/25 16:45:11 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	{
		if (nb > 9)
		{
			count = count + printf_int_dec (nb / 10);
			count = count + printf_int_dec (nb % 10);
		}
		else
			count = count + printf_char (nb + '0');
	}
	return (count);
}
