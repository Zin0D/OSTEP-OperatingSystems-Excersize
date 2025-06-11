#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

int status;
char buffer[256] = {0};
char msg[] = "Hello from Child1";

int main(int argc, int argv[]) {
    printf("Initialize the Pipe\n\r");
    int pipefds[2];
    pipe(pipefds);

    int rc = fork();
    if (rc < 0){
        fprintf(stderr,"Failed to create child\n\r");
        exit(1);
    }

    if (rc == 0){
        printf("Child created, PID of piping child: %d \n\r", getpid());
        write(pipefds[1], msg, 18);
        int rd = fork();

        if (rd < 0){
            fprintf(stderr,"Failed to create child2\n\r");
            exit(1);
        }

        if (rd == 0){
            printf("Second Child, PID: %d \n\r", getpid());
            read(pipefds[0], buffer, 18);
            printf("BUFF Received: %s ,current PID: %d  \n\r", buffer, getpid());
        }
        else {
            waitpid(rd, &status, 0);
            printf("Finished Parent2\n\r");
        }

    } else {
        waitpid(rc, &status, 0);
        printf("Finished Parent\n\r");
    }
    return 0;
}