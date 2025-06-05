#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcnt1.h>
#include <sys/types.h>



int main(int argc, char * argv[]){
    char *file = "Fortnite.txt"
    int fd = fopen(file, O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
    assert(fd > -1);
    int rc = write(fd, "Hello World\n", 13);
    assert(rc == 13);
    close(fd);
    return 0;
}