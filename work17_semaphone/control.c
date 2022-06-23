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

union semun {
  int              val;    /* Value for SETVAL  */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET  */
  unsigned short  *array;  /* Array for GETALL, SETALL  */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO */
                            /*  (Linux-specific)  */
};

int main(int argc, char * argv[]){
    int shmid;
    int semd;

    if(!strcmp(argv[1], "create")){
        int shmid = shmget(KEY, sizeof(int), IPC_CREAT | 0644); 

        int semd = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
        if(semd == -1){
            printf("error %d: %s\n", errno, strerror(errno));
        }
        union semun us;
        us.val = 1;
        int r = semctl(semd, 0, SETVAL, us);

        int file = open("tele.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(file == -1) {
            printf("error %d: %s\n", errno, strerror(errno));
        }
    }

    else if(!strcmp(argv[1], "remove")){
        int story = open("tele.txt", O_RDONLY);
        struct stat st;
        stat("tele.txt", &st);
        char* c = malloc(st.st_size);
        read(story, c, st.st_size); 
        printf("Story so far:\n%s", c);
        int semd = semget(KEY, 1, 0);
        int shmid = shmget(KEY, 1, 0);
        shmctl(shmid, IPC_RMID, 0);
        semctl(semd, IPC_RMID, 0);

    }
    return 0;
}