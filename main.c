#include <stdio.h>
#include "./include/ls.h"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>






int main() {

    int running = 1;
    int pid = -1;

    while (running) {
        char line[1024*4]={0};
        char ls_call[] = "ls\n";



        printf("Hello→ ");
        fgets(line, 1024*4,stdin);


        pid = fork();

        if (pid == 0) {

            if (strcmp(ls_call, line) == 0) {
                printf("%d", pid);
                ls();
            }

            exit(-1);

        }
        waitpid(pid, NULL, 0);


    }


    return 0;
}