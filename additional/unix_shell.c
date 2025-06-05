#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Startup the shell
// Wait for user command
// Parse user input
// Run Command and return Output
// Same Process again, start at 2.

char * readline() {
  int buffsize = 1024;
  int position = 0;
  char * buffer = malloc(sizeof(char) * buffsize); //We got a pointer to memory
  int c;
  
  if (!buffer) {
    fprintf(stderr, "Could not Allocate MEMORY"); //Use fprint to write to Standard Error
    exit(EXIT_FAILURE);
    }

  while (1) {
    c = getchar();
    if (c == EOF || c == '\n') {
        printf("\n"); //Essentialy we are simulating the line-break
        buffer[position] = '\0';
        return buffer;
    } 
    buffer[position] = c; // NO else requierd ,as buffer is returned anyways.
    position++;

    if (position >= buffsize) {
        buffsize += 1024;
        buffer = realloc(buffer, buffsize); //Reallocate samem memory.

        if (!buffer) {
            fprintf(stderr, "Could not Allocate MEMORY"); 
            exit(EXIT_FAILURE);
            }
        }
    } 
}

void running() {
    char * line;
    char * * args;
    int status = 1;

    do
    {
        printf(">"); // The ascii Char to be printed on da Shell
        line = read_line();
        int flag = 0;
        args = split_lines(line);
        status = dash_launch(args);
        free(line);
        free(args);

    } while (status);
    

} 