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

    int fd = open("fifo", O_RDONLY);
    int fd2 = open("fifo2", O_WRONLY);

    while(1){
        read(fd, input, 100);
	printf("read from fd\n");
        int i;
        for (i=0; input[i]!='\0'; i++) {
            if(input[i] >= 'a' && input[i] <= 'z'){
                input[i] = input[i] - 32;
            } 
        }
        write(fd2, input, 100);
	printf("wrote to fd2\n");
    }

    close(fd);
    close(fd2);

    return 0;
}
