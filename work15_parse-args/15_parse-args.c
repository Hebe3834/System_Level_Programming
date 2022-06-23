#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char * line){
  char * s = line;
  char ** args = calloc(6, sizeof(char *));
  char * token;
  int i = 0;
  while(line){
    token = strsep(&line, " ");
    args[i] = token;
    i++;
  }
  return args;
}


int main(){
  char line[50] = "ls -a -l";
  char ** args = parse_args(line);
  execvp(args[0], args);
  return 0;
}
