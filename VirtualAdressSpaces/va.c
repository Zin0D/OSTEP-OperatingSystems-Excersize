#include <stdio.h>
#include <stdlib.h>

int main(int argc, int argv[]){
    printf("location of code: 0x%p\n\r", main);
    printf("location of heap 0x%p\n\r", malloc(100));
    char x[] = "S4veTh3eW0rld";
    printf("location of stack; ßx%p\n\r", &x );
    return 0;
}