#include "../include/manager.h"


// select function to be called depending on input
void functionSelect(char* function, char* params) {

    if (strcmp(function , "ls") == 0) {
        ls(params);

    }

    //send a cute little message since it goes in here regardless when exiting
    if (strcmp(function , "exit") == 0) {
        printf("bye bye");
    }



    else {
        printf("%s not recognized\n", function);
    }
}
