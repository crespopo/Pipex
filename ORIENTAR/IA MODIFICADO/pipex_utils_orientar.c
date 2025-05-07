#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

// Función para dividir una cadena por un delimitador y devolver un arreglo de cadenas
char **split_path(char *path_str, char delimiter)
{
    char **result;
    int count = 1; // al menos habrá un elemento
    char *tmp = path_str;

    // Contar cuántos delimitadores hay
    while (*tmp)
    {
        if (*tmp == delimiter)
            count++;
        tmp++;
    }

    result = malloc((count + 1) * sizeof(char *));
    if (!result)
        return NULL;

    // Dividir la cadena en partes
    int i = 0;
    char *token = path_str;
    while (*token)
    {
        char *start = token;
        while (*token && *token != delimiter)
            token++;

        size_t len = token - start;
        result[i] = malloc(len + 1);
        if (!result[i])
            return NULL;

        strncpy(result[i], start, len);
        result[i][len] = '\0';
        i++;

        if (*token)
            token++; // Saltamos el delimitador
    }

    result[i] = NULL;
    return result;
}

// Encuentra la variable PATH en env y devuelve un arreglo de directorios separados por ":"
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

    return split_path(strdup(path), ':');
}

// Busca el comando en los directorios de PATH y devuelve la ruta del ejecutable
char *find_cmd_in_path(char **split_path, const char *cmd)
{
    int i = 0;
    char *path;
    size_t len;

    if (split_path)
    {
        while (split_path[i])
        {
            len = strlen(split_path[i]) + strlen(cmd) + 2;
            path = (char *)malloc(len);
            if (!path)
                return NULL;

            snprintf(path, len, "%s/%s", split_path[i], cmd);
            if (access(path, F_OK) == 0)
                return path;
            free(path);
            i++;
        }
    }

    if (access(cmd, F_OK) == 0)
        return strdup(cmd);

    return NULL; // No encontró el comando
}

// Ejecuta un comando con redirección de entrada y salida usando pipes
void exec_command(char *cmd, int fd_in, int fd_out, char **env)
{
    char **args;
    char **paths;
    char *cmd_path;

    paths = get_path_env(env);
    args = split_path(strdup(cmd), ' '); // Dividimos el comando por espacios
    cmd_path = find_cmd_in_path(paths, args[0]);

    if (cmd_path)
    {
        dup2(fd_in, STDIN_FILENO);
        dup2(fd_out, STDOUT_FILENO);
        execve(cmd_path, args, env);
        perror("Pipex - execve failed.");
        free(cmd_path);
    }
    else
    {
        perror("Pipex - Command not found.");
    }
    free(args);
}

// Crea un nuevo proceso hijo que ejecuta el comando especificado
void new_process(char *cmd, int (*p1)[2], int (*p2)[2], char **env, int is_first)
{
    int pid;

    pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        exit(1);
    }
    if (pid == 0)
    {
        if (is_first)
        {
            close((*p1)[1]); // Cerrar el descriptor de escritura del primer pipe
            exec_command(cmd, (*p1)[0], (*p2)[1], env);  // Redirigir entrada y salida
        }
        else
        {
            close((*p2)[0]); // Cerrar el descriptor de lectura del segundo pipe
            exec_command(cmd, (*p1)[0], (*p2)[1], env);  // Redirigir entrada y salida
        }
        exit(0);
    }
    else
    {
        close((*p1)[0]);
        close((*p2)[1]);
    }
}


/*
// Espera a que los procesos hijos terminen y maneja errores
int wait_for_children(int num_children)
{
    int status;
    for (int i = 0; i < num_children; i++)
    {
        if (wait(&status) == -1)
        {
            perror("wait");
            return -1;
        }
    }
    return 0;
}

int main(int argc, char *argv[], char *env[])
{
    int p1[2], p2[2];

    if (argc < 5)
    {
        fprintf(stderr, "Usage: %s <file1> <cmd1> <cmd2> <file2>\n", argv[0]);
        return 1;
    }

    // Crear los pipes
    pipe(p1);
    pipe(p2);

    // Ejecutar el primer comando en el primer proceso
    new_process(argv[2], &p1, &p2, env, 1);  // is_first = 1

    // Ejecutar el segundo comando en el segundo proceso
    new_process(argv[3], &p1, &p2, env, 0);  // is_first = 0

    // Esperar a que los procesos hijos terminen
    wait_for_children(2);

    return 0;
}
*/
