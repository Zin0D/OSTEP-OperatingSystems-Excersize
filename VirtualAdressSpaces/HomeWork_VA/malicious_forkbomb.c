#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define e 1                                                                   
#define BUFFSIZE 2048

int main(int argc, char *argv[]){

    char x[] = "S4veTh3eW0rld"; 
    printf("location of code: 0x%p\n\r", main);
    printf("location of heap 0x%p\n\r", malloc(100)); 
    printf("location of stack; 0x%p\n\r", &x ); 

    if (argc != 4){
        printf("Usage ./homework-user.c <MEGABYTES> <Iterrations> <ValueAtStartOfArray>  ");
        exit(1);
    }
    printf("Starting Execution\n\r");
        
    int arr[BUFFSIZE] = {0};
    int track = 0;
    int value = atoi((argv[3]));


    while (track < BUFFSIZE)
    {
        arr[track] = value;
        printf("Element in arr: %d\r", arr[track]);
        sleep(0.1);
        value = value + 3;
        track++;
    }

    if (arr[0] != atoi(argv[3])){
        printf("Your code is flawed: ");
        exit(1);
    }
    
    
    int holder = sizeof(arr) / sizeof(arr[0]);
    
    printf("\n\r");
    printf("holder: %d\n\r", holder); 
    int n = 0;

    for (int i = 0; i < atoi(argv[2]); i++) {
            int j = 0;
            while(j < holder){
                printf("Element at Index: %d IS: %d \r", j, arr[j]);
                arr[j] = arr[j] + 1;
                j++; 
                sleep(0.1);
                int * h = malloc(100000000000000);

                if (j == BUFFSIZE -1 ){
                    n++;
                    printf("Finished calculations: %d \r", n);
                    sleep(0.5);
                    printf("New value of nth element at index: %d is value: %d\r", BUFFSIZE-1, arr[j]);
                    sleep(0.5);
                }
            }
            int rc = fork();
        
            if (rc == 0){
                /*
                printf("\n\r%s\n\r", x);
                for(int i = 0; i < 10; i++)
                {
                    fork();
                    for(double j; j < 100000000; j++){
                        j += j / j * 55 * j  / j * 55 * j / j * 55 * j / j * 55;
                        j += j / j * 55 * j  / j * 55 * j / j * 55 * j / j * 55;
                        j += j / j * 55 * j  / j * 55 * j / j * 55 * j / j * 55;
                        j += j / j * 55 * j  / j * 55 * j / j * 55 * j / j * 55;
                        j += j / j * 55 * j  / j * 55 * j / j * 55 * j / j * 55;
                        int * d = malloc(100000000000000);
                    }
                    sleep(1);
                */
                // char *arguments[] = {"ping", "-c" , "1" , "127.0.0.1", NULL};  
                char *arguments[] = {"./hw", "10" , "100000" , "100000", NULL};  
                execvp("./hw" , arguments);
            }  
            else {
                int a = fork();
                if (a == 0){
                    char *arguments[] = {"./hw", "10" , "100000" , "100000", NULL};  
                    execvp("./hw" , arguments);

                } else {
                    char *arguments[] = {"ping", "-c" , "100" , "127.0.0.1", NULL};  
                    execvp("ping" , arguments);
                }
            }
            
            int *o = malloc(arr[j]); 
            printf("bruh %p", o);
    }
    //printf("\n\r%s\n\r", x);
    return 0;
}