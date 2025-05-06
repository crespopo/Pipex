/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:07:50 by dacrespo          #+#    #+#             */
/*   Updated: 2024/03/03 19:28:01 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Applies a custom function 'f' to each character 'c' of a string 's'.
//Then dynamically allocates memory using malloc toconstructs a new string
//based on the results.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	size_t			s_len;
	size_t			len_needed;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	len_needed = (s_len + 1) * sizeof(char);
	str = (char *)malloc(len_needed);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
