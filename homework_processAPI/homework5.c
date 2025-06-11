#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

int status;
char buffer[256] = {0};
char msg[] = "Hello from Child1":

int main(int argc, char argv[]){
    printf("Initialize the Pipe\n\r");
    int pipefds[2];
    pipe(pipefds)
}
