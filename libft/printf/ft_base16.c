/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:17:02 by dacrespo          #+#    #+#             */
/*   Updated: 2024/04/26 13:08:44 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base16(unsigned long nb, char *hex_digits)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count = count + ft_base16 (nb / 16, hex_digits);
		count = count + ft_base16 (nb % 16, hex_digits);
	}
	else
		count = count + printf_char(hex_digits[nb]);
	if (count < 0)
		return (-1);
	return (count);
}
