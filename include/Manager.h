#ifndef MANAGER_H
#define MANAGER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "Exec.h"
#include "BuiltIn.h"
#include "Command.h"

//buffer size in a macro to simplify access
#define INPUT_BUFFER_SIZE (1024 * 4)

/**
 * execute external functions (/bin/blabla) by passing a Command struct
 * @param command Command to be passed in. see Command.h for more info
 */
void externalFunction(Command command);

/**
 * verify if the command is a built-in function or not
 * @param command Command struct containing a function and parameters
 * @return 1 if command is built in, 0 otherwise
 */
int isBuiltIn(Command command);

/**
 * execute built-in functions, no searching in environment paths
 * @param command command struct
 */
void builtInFunction(Command command);

/**
 * take in user input and split it into 2 strings delimited by spaces in the input
 * @param input char* string
 * @return Command struct of user input split into function and parameter
 */
Command handleInput(char* input);




#endif