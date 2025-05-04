/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv_fork_prog1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:48:11 by dacrespo          #+#    #+#             */
/*   Updated: 2025/05/03 13:24:17 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*const argv2[] = {"prog2", "abcde", "fghij", NULL};

	printf("Padre %s : PID = %d\n", argv[0], getpid());

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		// Proceso hijo
		printf("Hijo Ejecutando execv prog2 desde PID = %d (padre = %d)\n", getpid(), getppid());
		execv("./prog2", argv2);
		perror("execv"); // Solo se ejecuta si execv falla
		return (1);
	}
	else
	{
		// Proceso padre
		printf("Padre Esperando a que el hijo termine...\n");
		wait(NULL);
		printf("Padre: el proceso Hijo ha terminado.\n");
	}

	return (0);
}
