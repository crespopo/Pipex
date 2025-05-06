/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:46:06 by dacrespo          #+#    #+#             */
/*   Updated: 2024/04/26 12:13:29 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	printf_format(char type, va_list args);
int	printf_char(char c);
int	printf_int_dec(int nb);
int	printf_pointer(void *arg);
int	printf_string(char *str);
int	printf_unsigned(unsigned int nb);
int	printf_hex(unsigned int nb, int type);
int	ft_base16(unsigned long nb, char *hex_digits);

#endif
