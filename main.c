#include "./include/Manager.h"








int main() {
    //condition for the while loop
    int running = 1;
    //process id for the execv process
    int pid = -1;

    while (running) {
        //buffer to replace with user input
        char line[INPUT_BUFFER_SIZE]={0};



        //prompt
        printf("Hello→ ");

        // poplate line from standard input (stdin)
        fgets(line, INPUT_BUFFER_SIZE,stdin);

        // fgets receives text with \n at the end. ↓ replaces \n with \0 to help in comparisons
        line[strcspn(line, "\n") ]= '\0';

        // if the user asks for exit, turns running to 0 and exits the big loop
        // necessary to do before the fork (built in)
        if (strcmp(line, "exit")==0) {
            running = 0;
        }

        // create a new process to maintain functionality
        pid = fork();


        if (pid == 0) {

            functionSelect(line);

            exit(-1);

        }
        waitpid(pid, NULL, 0);


    }


    return 0;
}