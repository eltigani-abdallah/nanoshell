#include "../include/ls.h"

void ls() {
    //arguments to be passed in to execve function
    char* argv[]={"ls", NULL};
    char* envp[]={NULL};

    //execve("path to exectable", arguments, envp)
    execve("/bin/ls",argv, envp);

}