#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int readrand(){
    int in = open("/dev/urandom", O_RDONLY);
    int buff;
    read(in, &buff, sizeof(int));
    if(!errno){
        return buff;
    }
    printf("Error %d\n", errno);
    return 0;
}

int main() {
    int rand[10];
    int i;
    printf("Generating random numbers:\n");
    for(i=0; i<10; i++){
        rand[i] = readrand();
        printf("\trandom %d: %d\n", i, rand[i]);
    }

    printf("Writing numbers to file...\n");
    int out = open("out.txt", O_CREAT | O_WRONLY | O_RDONLY, 0644);
    write(out, rand, sizeof(rand));

    printf("Reading numbers from file...\n");
    int in = open("out.txt",O_RDONLY);
    int rand2[10];
    read(in, rand2, sizeof(rand2));

    printf("Verification that written values were the same:\n");
    if(errno){
        printf("Error %d\n", errno);
    }
    else{
        for(i=0; i<10; i++){
            printf("\trandom %d: %d\n", i, rand2[i]);
        }
    }


    return 0;
}