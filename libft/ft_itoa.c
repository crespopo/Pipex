/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:00:56 by dacrespo          #+#    #+#             */
/*   Updated: 2024/03/10 12:22:21 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Calculates the length of the number
// Dinamically allocates memory and then places the converted numerical values
// into the string considering the negative sign.
// Returns the resulting string to the user

static size_t	get_len(int nbr)
{
	size_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_len(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		result[len--] = '0' + n % 10;
		n = n / 10;
	}
	return (result);
}
