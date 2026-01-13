#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include "./include/ls.h"
#include "./include/manager.h"

#define INPUT_BUFFER_SIZE (1024 * 4)






int main() {

    int running = 1;
    int pid = -1;

    while (running) {
        char line[INPUT_BUFFER_SIZE]={0};




        printf("Hello→ ");
        fgets(line, INPUT_BUFFER_SIZE,stdin);
        line[strcspn(line, "\n") ]= '\0';

        if (strcmp(line, "exit")==0) {
            running = 0;
        }


        pid = fork();

        if (pid == 0) {

            functionSelect(line);

            exit(-1);

        }
        waitpid(pid, NULL, 0);


    }


    return 0;
}