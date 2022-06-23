#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1

int main(){
    
    int fd[2];
    if(pipe(fd)){
        printf("Error opening pipe");
    }
    int fd2[2];
    if(pipe(fd2)){
        printf("Error opening pipe 2");
    }

    int f = fork();
    char input[100];

    if(f == 0){ //child
        close(fd[WRITE]);
        close(fd2[READ]);
        while(1){
            int i;
            read(fd[READ], input, 100);
            for (i=0; input[i]!='\0'; i++) {
                if(input[i] >= 'a' && input[i] <= 'z'){
                    input[i] = input[i] - 32;
                } 
            }
            write(fd2[WRITE], input, 100);
        }
    }
    
    else{ //parent
        close(fd[READ]);
        close(fd2[WRITE]);
        while(1){
            printf("Input: ");
            fgets(input, 100, stdin);
            write(fd[WRITE], input, 100);
            read(fd2[READ], input, 100);
            printf("%s", input);
        }
        
    }

    return 0;
}