#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  int sd = client_connect();

  char input[BUFFER_SIZE];
  while (1) {
    printf("Input: ");
    fgets(input, BUFFER_SIZE, stdin);
    if(write(sd, input, sizeof(input)) == -1){
      printf("Error: %s", strerror(errno));
    }
    if(read(sd, input, sizeof(input)) == -1){
      printf("Error: %s", strerror(errno));
    }
    printf("Output: %s\n", input);
  }
}
