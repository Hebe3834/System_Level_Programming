#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


struct pop_entry {
    int year;
    int population;
    char boro[15];
};


int read_csv(){
    int in = open("nyc_pop.csv", O_RDONLY);
    int out = open("nyc_pop.data", O_WRONLY | O_CREAT, 0644);
    struct stat st;
    //int test=0;
    stat("nyc_pop.csv", &st);
    int size = st.st_size;
    char buff[size];
    read(in, &buff, size);
    int i;
    for(i=0; i<size; i++){ // skip header
        if(buff[i] == '\n'){
            break;
        }
    }
    char line[100];
    int li = 0;
    int linedata[6];
    for(i=i+1; i<size+1; i++){
        li = 0;
        while(buff[i] != '\n' && i<size+1){
            line[li] = buff[i];
            i++;
            li++;
        }
        sscanf(line, "%d,%d,%d,%d,%d,%d", &linedata[0], &linedata[1], &linedata[2], &linedata[3], &linedata[4], &linedata[5]);
        int n;
        char * boroArr[5] = {"Manhattan", "Brooklyn", "Queens", "Bronx", "Staten Island"};
        for(n=0; n<5; n++){
            struct pop_entry entry;
            entry.year = linedata[0];
            entry.population = linedata[n+1];
            strcpy(entry.boro, boroArr[n]);
            write(out, &entry, sizeof(entry)); 
            //test++;
        }   
    }
    struct stat st1;
    //printf("%d\n", test);
    stat("nyc_pop.csv", &st1);
    if(errno)
        printf("error %d: %s", errno, strerror(errno));
    return st1.st_size;
    close(in);
    close(out);
}

void read_data(){
    struct stat st2;
    stat("nyc_pop.data", &st2);
    int size = st2.st_size/sizeof(struct pop_entry);
    printf("%ld\n", st2.st_size);
    struct pop_entry entries[size];
    int data = open("nyc_pop.data", O_RDONLY);
    read(data, entries, st2.st_size);
    if(errno){
        printf("error %d: %s", errno, strerror(errno));
        return;
    }
    int i;
    for(i=0; i<size; i++){
        printf("%d year: %d\tboro: %s\t\tpop: %d\n", i, entries[i].year, entries[i].boro, entries[i].population);
    }
    close(data);
}

void add_data(){
    int in = open("nyc_pop.data", O_WRONLY | O_APPEND, 0);
    struct pop_entry update;
    char input[100];
    printf("Enter year boro pop: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %s %d", &update.year, update.boro, &update.population);
    printf("Appended data to file: year: %d\tpopulation: %d\tboro: %s\n", update.year, update.population, update.boro);
    write(in, &update, sizeof(update));
    close(in);
}

void update_data(){
    struct pop_entry new;
    char input[100];
    read_data();
    printf("Entry to update: ");
    int n;
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &n);
    printf("Enter year boro pop:\n");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d %s %d", &new.year, new.boro, &new.population);

    int out = open("nyc_pop.data", O_RDWR);
    lseek(out, n*sizeof(struct pop_entry), SEEK_SET);
    write(out, &new, sizeof(new));
    printf("File updated\n");
    close(out);
}

int main(int argc, char * argv[]){
    if(argc == 2){
        if(!strcmp(argv[1], "-read_csv"))
            printf("reading nyc_pop.csv\nwrote %d bytes to nyc_pop.data\n", read_csv());
        else if(!strcmp(argv[1], "-read_data"))
            read_data();
        else if(!strcmp(argv[1], "-add_data"))
            add_data();
        else if(!strcmp(argv[1], "-update_data"))
            update_data();
    }
    else{
        printf("bad input\n");
    }
    return 0;
}