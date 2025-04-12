/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_pid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:53:36 by dacrespo          #+#    #+#             */
/*   Updated: 2025/04/11 12:45:25 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

size_t	strlen_custom(const char *str)
{
	pid_t	pid;
	size_t	length;

	pid = getpid();
	length = 0;
	while (str[length] != '\0')
		length++;
	printf("PID proceso: %d\n", pid);
	return (length);
}

int	main(void)
{
	char	*str;
	size_t	length;

	str = "hola";
	length = strlen_custom(str);
	printf("La longitud de la cadena '%s' es: %zu\n", str, length);
	return (0);
}
/*
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	int		x;
	pid_t	pid;

	i = 5;
	x = 8;
	pid = fork();
	if (pid == 0)
		printf("Hola, soy el Hijo:%d\n", getpid());
	else if (pid > 0)
		printf("Hola, yo soy el Padre:%d\n", getpid());
	else
		printf("No soy familia de nadie\n");
	return (0);
}
*/

/*
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int	main(void)
{
int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		printf("Soy el hijo. PID: %d\n", getpid());
	else if (pid > 0)
		printf("Soy el padre. Mi PID: %d, hijo PID: %d\n", getpid(), pid);
	else
		perror("fork falló");
	return (0);
}
#include <unistd.h>
#include <stdio.h>

int main() {
    fork();  // Aquí se llama a fork()
    printf("Hola, soy un proceso\n");
    return 0;
}
*/
