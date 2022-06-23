#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  
  char input[BUFFER_SIZE];
  while (1) {
      printf("Input: ");
      fgets(input, BUFFER_SIZE, stdin);
      if(write(to_server, input, sizeof(input)) == -1){
        printf("Error: %s", strerror(errno));
      }
      if(read(from_server, input, sizeof(input)) == -1){
        printf("Error: %s", strerror(errno));
      }
      printf("Output: %s\n", input); 
  }
}
