/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv_fork_prog2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:48:26 by dacrespo          #+#    #+#             */
/*   Updated: 2025/05/03 12:48:40 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i = 0;

	printf("%s : PID = %d\n", argv[0], getpid());
	while (i < argc)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
}
