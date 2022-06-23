#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  int sd = server_setup();

  char input[BUFFER_SIZE];
  while(1){
    from_client = server_connect(sd);
    int f = fork();
    if(f == 0){
      while(read(from_client, input, sizeof(input))){
        int i;
        for(i=0; i<strlen(input); i++){
          if(input[i] >= 'A' && input[i] <= 'Z'){
            input[i] = input[i] + 32;
          }
        }
        input[strlen(input)-1] = '\0';
        write(from_client, input, sizeof(input));
      }
    }

  }
}
