#include "../include/ls.h"

void ls() {
    char* argv[]={"ls", NULL};
    char* envp[]={NULL};

    execve("/bin/ls",argv, envp);

}