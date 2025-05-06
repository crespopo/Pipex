/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:46:33 by dacrespo          #+#    #+#             */
/*   Updated: 2024/04/26 12:15:17 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(char input, va_list args)
{
	int	count;

	count = 0;
	if (input == 'c')
		count = count + (char)printf_char(va_arg(args, int));
	else if (input == 'i' || input == 'd')
		count = count + printf_int_dec(va_arg(args, int));
	else if (input == 'p')
		count = count + printf_pointer(va_arg(args, void *));
	else if (input == 's')
		count = count + printf_string(va_arg(args, char *));
	else if (input == 'u')
		count = count + printf_unsigned(va_arg(args, unsigned int));
	else if (input == 'x' || input == 'X')
		count = count + printf_hex(va_arg(args, int), input);
	else if (input == '%')
		return (write(1, "%", 1));
	return (count);
}
