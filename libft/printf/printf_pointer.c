/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:46:41 by dacrespo          #+#    #+#             */
/*   Updated: 2024/09/04 12:51:25 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_pointer(void *arg)
{
	int				count;
	char			*str;
	unsigned long	arg2;

	count = 0;
	if (!arg)
	{
		(write(1, "(nil)", 5));
		count = count + 5;
	}
	else
	{
		arg2 = (unsigned long)arg;
		str = "0123456789abcdef";
		count = count + printf_string("0x");
		count = count + ft_base16(arg2, str);
	}
	return (count);
}
