#ifndef COMMAND_H
#define COMMAND_H

/**
 *struct that contains two strings, one is the function to be called and the other contains the parameters to be passed\n\n
 *created by passing user input into Manager.handleInput()
*/
typedef struct {
    char* function;
    char* param;
} Command;



#endif
