#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"

// Cherche un exécutable dans PATH
char *find_in_path(const char *command)
{
    char *path_env;
    char *path_copy;
    char *dir;
    char full_path[BUFFER_SIZE];
    
    // Si la commande contient "/", essayer directement
    if (strchr(command, '/'))
    {
        if (access(command, X_OK) == 0)
            return strdup(command);
        return NULL;
    }
    
    // Récupérer PATH
    path_env = getenv("PATH");
    if (!path_env)
        return NULL;
    
    path_copy = strdup(path_env);
    if (!path_copy)
        return NULL;
    
    // Parser PATH
    dir = strtok(path_copy, ":");
    while (dir)
    {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
        
        // Vérifier si le fichier existe et est exécutable
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return strdup(full_path);
        }
        dir = strtok(NULL, ":");
    }
    
    free(path_copy);
    return NULL;
}

// Exécute une commande externe avec fork/execve
void execute_command(char **args)
{
    char *command_path;
    pid_t pid;
    int status;
    
    // Chercher la commande
    command_path = find_in_path(args[0]);
    if (!command_path)
    {
        printf("nanoshell: weird, %s is not here… :/\\n", args[0]);
        return;
    }
    
    // Fork
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        free(command_path);
        return;
    }
    
    if (pid == 0)
    {
        // Code du processus enfant
        extern char **environ;
        execve(command_path, args, environ);
        perror("execve");
        exit(1);
    }
    else
    {
        // Code du processus parent
        waitpid(pid, &status, 0);
    }
    
    free(command_path);
}
