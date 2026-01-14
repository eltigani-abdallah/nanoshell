#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

// Affiche le prompt
void display_prompt(void)
{
    printf("?> ");
    fflush(stdout);
}

// Parse une ligne en tableau d'arguments
int parse_line(char *line, char **args)
{
    int argc = 0;
    char *token;
    
    // Supprimer le \n à la fin
    line[strcspn(line, "\n")] = 0;
    
    // Copier la ligne pour ne pas la modifier
    char *line_copy = strdup(line);
    if (!line_copy)
        return 0;
    
    token = strtok(line_copy, " \t");
    while (token && argc < MAX_ARGS - 1)
    {
        args[argc] = strdup(token);
        if (!args[argc])
        {
            free(line_copy);
            return argc;
        }
        argc++;
        token = strtok(NULL, " \t");
    }
    args[argc] = NULL;
    free(line_copy);
    return argc;
}

// Nettoie la mémoire des arguments
void free_args(char **args, int argc)
{
    for (int i = 0; i < argc; i++)
    {
        if (args[i])
            free(args[i]);
    }
}

// Boucle principale du shell
int main(void)
{
    char line[BUFFER_SIZE];
    char *args[MAX_ARGS];
    int argc;
    int result;
    
    while (1)
    {
        display_prompt();
        
        if (!fgets(line, sizeof(line), stdin))
            break;
        
        argc = parse_line(line, args);
        if (argc == 0)
            continue;
        
        // Vérifier si c'est un builtin
        result = is_builtin(args);
        if (result != -1)
        {
            free_args(args, argc);
            continue;
        }
        
        // Sinon, exécuter comme commande externe
        execute_command(args);
        free_args(args, argc);
    }
    
    return 0;
}
