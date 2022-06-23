#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>


int main(){
    srand(time(NULL));
    printf("Parent initial message\n");
    int pid1 = fork();
    int pid2 = fork();
    if(!pid1){
        printf("Child %d start\n", getpid());
    }
    if(!pid2){
        printf("Child %d start\n", getpid());
    }
   if(pid1 && pid2){
    int status;
    int child_pid = wait(&status);
    printf("Child process %d slept for %d seconds\n", child_pid, WEXITSTATUS(status));
    printf("Parent process ended\n");
    return 0;
  }
  else{
    printf("Child pid: %d\n", getpid());
    int sec = (rand()%4) + 2;
    sleep(sec);
    printf("Child process %d ended\n", getpid());
    return sec;
  }
    return 0;
}
