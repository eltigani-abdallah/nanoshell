#include "../include/manager.h"


// select function to be called depending on input
void functionSelect(char* input) {

    if (strcmp(input , "ls") == 0) {
        ls();

    }

    //send a cute little message since it goes in here regardless when exiting
    if (strcmp(input , "exit") == 0) {
        printf("bye bye");
    }



    else {
        printf("%s not recognized\n", input);
    }
}
