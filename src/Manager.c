#include "../include/Manager.h"


// select function to be called depending on input
void externalFunction(Command command) {

    if (strcmp(command.function , "ls") == 0) {
        exec(command);
    }



    else {
        printf("%s not recognized\n", command.function);
    }
}

int isBuiltin(Command command) {
    if (strcmp(command.function , "exit") == 0) {
        return 1;
    }
    if (strcmp(command.function , "cd") == 0) {
        return 1;
    }
    if (strcmp(command.function , "pwd") == 0) {
        return 1;
    }
    if (strcmp(command.function , "env") == 0) {
        return 1;
    }
    return 0;
}

void builtInFunction(Command command) {
    if (strcmp(command.function , "exit") == 0) {
        printf("bye bye (^·^)/");
        exit(0);
    }
    if (strcmp(command.function , "cd") == 0) {

    }
    if (strcmp(command.function , "pwd") == 0) {

    }
    if (strcmp(command.function , "env") == 0) {

    }
}

Command handleInput(char* input) {
    Command command={0,0};

    input[strcspn(input, "\n")]='\0';

    command.function=strtok(input, " ");

    command.param = strtok(NULL, " ");

    return command;
}

