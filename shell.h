#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024
#define MAX_ARGS 64

// Déclarations pour le parsing
int parse_line(char *line, char **args);
void free_args(char **args, int argc);

// Déclarations pour l'exécution
void execute_command(char **args);
int is_builtin(char **args);

// Affichage
void display_prompt(void);

#endif