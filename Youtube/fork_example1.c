/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_example1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:34:07 by dacrespo          #+#    #+#             */
/*   Updated: 2025/04/24 21:18:23 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int var = 22;

int main(void)
{

	pid_t pidC;

	printf("** Proceso PID = %d comienza ** n", getpid());
	pidC = fork();

	printf("proceso PID = %d, pidC = %d ejecutándose \n", getpid(), pidC);

	if(pidC > 0)
	{
		var = 55;
		printf("Yo soy el Padre\n");
	}
	else if(pidC == 0)
	{
		var = 33;
		printf("Yo soy el Hijo\n");
	}
	else /* error */
	{
	}
	while(1)
	{
		printf("proceso PID = %d, var = %d ejecutandose \n", getpid(), var);
		sleep(3);
	}
