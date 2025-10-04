#include <stdio.h>

#define INTRO "Linked list in the holy C"

typedef struct {
    int value;
    int *prev;
    int *next;
} linked ;

int main(int argc, char *argv[]){     
    printf(INTRO);
}