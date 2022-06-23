#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define READ 0
#define WRITE 1

int main(){
    char input[100];

    mkfifo("fifo", 0644);
    int fd = open("fifo", O_WRONLY);
    mkfifo("fifo2", 0644);
    int fd2 = open("fifo2", O_RDONLY);

    while(1){
        printf("Input: ");
        fgets(input, 100, stdin);
        write(fd, input, 100);
	printf("wrote to fd\n");
        read(fd2, input, 100);
	printf("read from fd2\n");
        printf("Output: %s\n", input);
    }

    close(fd);
    close(fd2);

    return 0;
}
