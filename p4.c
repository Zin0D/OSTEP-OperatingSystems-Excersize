#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    printf("hello (pid:%d)\n", getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "failed to create process\n");
        exit(1);
    } else if (rc == 0){ //define for the 
        close(STDOUT_FILENO); //Piping 101
        open("./p4_out", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU); //Opened the file and all will be put in here now.
        char *myargs[3];
        myargs[0] = strdup("wc"); //Run another PROGRAMM
        myargs[1] = strdup("p3.c");
        myargs[2] = NULL; //End of array.
        execvp(myargs[0], myargs);
        } else {
        int rc_wait = wait(NULL);
        printf("parent pid:%d (child pid:%d), (rc_wait:%d)", getpid() , rc, rc_wait);
    }
    exit(0);
}