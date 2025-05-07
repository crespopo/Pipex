
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simula ft_split usando strtok y libera el string original
char **split_path(char *path_str)
{
	char **result = malloc(100 * sizeof(char *));
	char *token;
	int i = 0;

	if (!result || !path_str)
		return NULL;

	token = strtok(path_str, ":");
	while (token != NULL)
	{
		result[i] = strdup(token); // copia segura
		i++;
		token = strtok(NULL, ":");
	}
	result[i] = NULL;
	free(path_str); // libera la copia hecha con strdup
	return result;
}

char **get_path_env(char *env[])
{
	int i = 0;
	char *path = NULL;

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break;
		}
		i++;
	}

	if (!path)
		return NULL;

	return split_path(strdup(path)); // hace copia modificable
}

int main(void)
{
	char *env[] = {
		"USER=dani",
		"HOME=/home/dani",
		"PATH=/usr/local/bin:/usr/bin:/bin:/home/dani/bin",
		NULL
	};

	char **paths = get_path_env(env);
	int i = 0;

	if (!paths)
	{
		printf("No PATH found in environment.\n");
		return 1;
	}

	printf("Directories in PATH:\n");
	while (paths[i])
	{
		printf("  [%d] %s\n", i, paths[i]);
		free(paths[i]); // libera cada string
		i++;
	}
	free(paths); // libera array de punteros

	return 0;
}
