#include <stdio.h>
#include <stdlib.h>

int main(int argc, int argv[]){
    printf("location of code: 0x%p\n\r", main);
    printf("location of heap 0x%p\n\r", malloc(100)); //Heap allocated element, malloc seems to return an adress.
    char x[] = "S4veTh3eW0rld"; //First allocated variable that is stored inside the stack, as the stack keeps variables of each function on it.
    printf("location of stack; 0x%p\n\r", &x ); 
    return 0;
}