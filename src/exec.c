#include "../include/exec.h"

void exec(Command command) {
    //arguments to be passed in to execve function
    char* argv[]={command.function,command.param, NULL};
    char* envp[]={NULL};

    //execve("path to exectable", arguments, envp)
    execve("/bin/ls",argv, envp);

}