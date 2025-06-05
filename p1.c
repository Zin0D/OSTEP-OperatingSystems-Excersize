#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(int argc, char *argv[]) {
    printf("hello (pid:%d) \n", getpid());
    int rc = fork();
    if (rc < 0) {
        //Fork failed as our PID is not existent 
        fprintf(stderr,"fork failed\n");
        exit(1); //Exit with 1, as 1 is usually the code for saying, something went wrong.
    } else if (rc == 0){ //If the current proccess is a child Process, fork() returns 0
        printf("child (pid:%d)\n", (int) getpid());
    }  else {
        printf("parent of %d (pid:%d)", rc, (int) getpid());
    }
    return 0;
}