#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int rc_wait;

//YAVIN4, REBELL-BASE!
int main(int argc , char argv[]){
    int fc = fork();

    if (fc < 0){
        printf("Failed to FORK\n");
        exit(1); //exit with negativ Code 
    }

    if (fc == 0){
        printf("Child Process: %d | HELLO!!\n\r", getpid());
    } else {
        rc_wait = waitpid(fc, NULL, NULL);
        printf("Parent of %d , PARENT:%d | GOODBYE!! \n\r", rc, getpid());
    }
    return(0);
}