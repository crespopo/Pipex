/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:36:30 by dacrespo          #+#    #+#             */
/*   Updated: 2024/02/19 13:29:01 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// It sends a string and a new line to the 'fd'.
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	if (s[i] == '\0')
		write(fd, "\n", 1);
}
