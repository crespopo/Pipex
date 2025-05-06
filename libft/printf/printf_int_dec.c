/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:46:38 by dacrespo          #+#    #+#             */
/*   Updated: 2024/04/25 16:42:45 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int_dec(int nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	if (nb < 0)
	{
		count = count + printf_char('-');
		nb = -nb;
	}
	if (nb > 9)
		count = count + printf_int_dec(nb / 10) + printf_int_dec(nb % 10);
	else
	{
		c = nb + '0';
		write(1, &c, 1);
		count++;
	}
	return (count);
}
