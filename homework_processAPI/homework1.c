#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//YAVIN 4
int x;

/*So apperantly we shall write some code and answer questions :raised_eyebrow:*/

int main(int argc, char argv[]){
    x = 100;
    int check = fork();
    if (check < 0){
        printf("Fork failed!")
        exit(1);
    } return(0);
}