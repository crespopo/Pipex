/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv_program2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:59:46 by dacrespo          #+#    #+#             */
/*   Updated: 2025/05/03 12:41:57 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char* argv[])
{
	int	i;

	i = 0;
	printf("%s : %i \n", argv[0], getpid());
	while (i < argc)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
	return (0);
}
