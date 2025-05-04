/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execv_program1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:09:02 by dacrespo          #+#    #+#             */
/*   Updated: 2025/05/03 13:11:33 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char* argv[])
{
	char *const argv2[] = {"prog2","abcde", "fghij", NULL};

	printf("%s : %i \n", argv[0], getpid());
	execv("./prog2", argv2);

	printf("Error \n");
	return (-1);
}
