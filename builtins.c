#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

// Builtin : cd
int builtin_cd(char **args)
{
    char *target;
    
    if (args[1] == NULL)
        target = getenv("HOME");
    else if (strcmp(args[1], "~") == 0)
        target = getenv("HOME");
    else if (strcmp(args[1], "..") == 0)
        target = "..";
    else
        target = args[1];
    
    if (chdir(target) != 0)
    {
        perror("cd");
        return -1;
    }
    return 0;
}

// Builtin : pwd
int builtin_pwd(void)
{
    char cwd[BUFFER_SIZE];
    
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        return -1;
    }
    printf("%s\\n", cwd);
    return 0;
}

// Builtin : env
int builtin_env(void)
{
    extern char **environ;
    
    for (int i = 0; environ[i] != NULL; i++)
        printf("%s\\n", environ[i]);
    return 0;
}

// Builtin : exit
int builtin_exit(void)
{
    exit(0);
}

// Vérifie si c'est un builtin et l'exécute
int is_builtin(char **args)
{
    if (args[0] == NULL)
        return 0;
    
    if (strcmp(args[0], "cd") == 0)
        return builtin_cd(args);
    if (strcmp(args[0], "pwd") == 0)
        return builtin_pwd();
    if (strcmp(args[0], "env") == 0)
        return builtin_env();
    if (strcmp(args[0], "exit") == 0)
        return builtin_exit();
    
    return -1; 
}
