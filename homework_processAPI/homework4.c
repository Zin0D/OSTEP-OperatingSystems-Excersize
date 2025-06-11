#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int status;

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "Fork failed!()\n\n");
        exit(1);
    }
    if (rc == 0){ // Exec right here
        char *arguments[] = {"ping", "-c", "1", "127.0.0.1", NULL};
        execvp("ping", arguments); // p stands for path, v for
        // execl("/usr/bin/echo", "/usr/bin/echo", "oofy", NULL
        perror("Exec failed");
        exit(1);
    }
    else {
        int rc_wait = waitpid(rc, &status, 0);
        printf("Child finished. Beginn Stage-2\n\n\n");
        char *arguments[] = {"echo", "127.0.0.1", NULL};
        execvp("echo", arguments);

        perror("Exec failed");
        exit(1);
    }
    return 0;
}