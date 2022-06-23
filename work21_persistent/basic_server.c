#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  
  char input[BUFFER_SIZE];
  while(1){
    from_client = server_handshake( &to_client );
    while(1){
      read(from_client, input, sizeof(input));
      int i;
      for(i=0; i<strlen(input); i++){
	if(input[i] >= 'A' && input[i] <= 'Z'){
	  input[i] = input[i] + 32;
	}
      }
      input[strlen(input)-1] = '\0';
      write(to_client, input, sizeof(input));
    } 

  }
}
