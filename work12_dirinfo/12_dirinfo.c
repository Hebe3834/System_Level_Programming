#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]){

    struct stat st;
    DIR * d;
    if(argc > 1){
        d = opendir(argv[1]);
        printf("Statistics for directory: %s\n", argv[1]);
    }
    else{
        char dname[100];
        printf("Enter a directory to scan: ");
        fgets(dname, sizeof(dname), stdin);
        dname[strlen(dname)-1] = '\0';
        d = opendir(dname);
        printf("Statistics for directory: %s\n", dname);
    }

    if(!d){
        printf("%s\n", strerror(errno));
        return 0;
    }
    
    struct dirent *entry;
    entry = readdir(d);

    printf("Directories: \n");
    while(entry){
        if(entry->d_type == DT_DIR)
            printf("\t%s\n", entry->d_name);
        entry = readdir(d);
    }

    rewinddir(d);
    entry = readdir(d);

    printf("Regular files: \n");
    long s = 0;
    while(entry){
        if(entry->d_type == DT_REG){
            stat(entry->d_name, &st);
            s += st.st_size;
            printf("\t%ld\t%s\n", st.st_size, entry->d_name);
        }
        entry = readdir(d);
    }

    printf("Total Size of Regular Files: %ld Bytes\n", s);

    closedir(d);

    return 0;
}