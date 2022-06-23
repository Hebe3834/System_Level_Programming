#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo) {
    if (signo == SIGINT) {
        int out = open("msg.txt", O_WRONLY | O_CREAT | O_APPEND, 0664); 
        char *msg = "Program exited due to SIGINT\n";
        write(out, msg, strlen(msg));
        if(errno)
            printf("Error %d: %s\n", errno, strerror(errno));
        exit(0);
    } 
    else if (signo == SIGUSR1)
        printf("PID of parent process: %d\n", getppid());
}


int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    while (1) {
        printf("Process PID: %d\n", getpid());
        sleep(1);
    }
    return 0;
}