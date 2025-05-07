#include "pipex.h"

void	print_array(char *array[])
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("Array pos %d: %s\n", i, array[i]);
		i++;
	}
}

void	print_args(int argc, char *argv[], char *env[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_printf("Argumento %d: %s\n", i, argv[i]);
		i++;
	}
	i = 0;
	while (env[i])
	{
		ft_printf("Env %d: %s\n", i, env[i]);
		i++;
	}
}
