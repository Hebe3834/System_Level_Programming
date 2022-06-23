#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>


#define KEY 24602

int main(int argc, char * argv[]){
    int shmid;
    int semd;
    char * c;

    semd = semget(KEY, 1, 0);
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = SEM_UNDO;
    sb.sem_op = -1;
    semop(semd, &sb, 1); 
    int *data = shmat(shmid, 0, 0);
    int fd = open("tele.txt", O_RDONLY, 0777);
	lseek(fd, 0-*data, SEEK_END);
    char line[*data+1];
	read(fd, line, *data);
    printf("Last line: %s\n", line);

    printf("Enter next line: ");
    char line2[1000];
    fgets(line2, 1000, stdin);
    fd = open("tele.txt", O_WRONLY | O_APPEND);
    int e = write(fd, line2, strlen(line2));
    if(e == -1) {
        printf("error %d: %s!\n", errno, strerror(errno));
    }
    close(fd);
    shmdt(data);
	sb.sem_op = 1;
	semop(semd, &sb, 1);
    
    return 0;
}