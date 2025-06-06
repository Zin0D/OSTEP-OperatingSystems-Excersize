#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFSIZE 1024;

int fd;
int rc;

int main(int argc, char argv[]){
    fd = open("./flag.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    rc = fork();

    // Yes they can access the fd at the same time, this is due to the implementation of the OS and how it handles it.
    //write(fd, BUFFER, BIFFSIZE) if at the same time....

}