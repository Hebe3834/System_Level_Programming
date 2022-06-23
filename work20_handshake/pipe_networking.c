#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client
  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.
  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  if(mkfifo(WKP, 0644)){
    printf("Error creating wkp\n"); // 1) server creates wkp fifo
  }
  int from_client = open(WKP, O_RDONLY);

  char clientMsg[HANDSHAKE_BUFFER_SIZE];
  read(from_client, clientMsg, HANDSHAKE_BUFFER_SIZE); // 4) read client msg
  remove(WKP); // 4) remove wkp

  *to_client = open(clientMsg, O_WRONLY); // 5) connect to client fifo
  if(*to_client == -1){
    printf("Error opening priv fifo\n");
  }
  srand(time(NULL));
  char acknlgmt[5];
  sprintf(acknlgmt, "%d", rand()%10);
  if(write(*to_client, acknlgmt, sizeof(acknlgmt)) == -1){ // 5) send initial acknowledgement msg
    printf("Error writing to priv fifo\n");
  }
  
  char acknlgmt2[5];
  if(read(from_client, acknlgmt2, sizeof(acknlgmt2)) == -1){ // 8) read msg from client 
    printf("Error reading from wkp\n");
  }

  printf("%s\n", acknlgmt);
  printf("%s\n", acknlgmt2);

  return from_client;
}


/*=========================
  client_handshake
  args: int * to_server
  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.
  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  int from_server;
  char pid[5];
  sprintf(pid, "%d", getpid()); // secret fifo name is pid
  if(mkfifo(pid, 0644) == -1){  // 2) private fifo
    printf("Error making private pipe\n");
  } 

  *to_server = open(WKP, O_WRONLY); // 3) open wkp
  if(*to_server == -1){
    printf("Error openning wkp\n");
  }
  if(write(*to_server, pid, HANDSHAKE_BUFFER_SIZE) == -1){ // 3) send private fifo name
    printf("Error writing to wkp\n");
  }

  from_server = open(pid, O_RDONLY);
  char acknlgmt3[5];
  if(read(from_server, acknlgmt3, sizeof(acknlgmt3)) == -1){
    printf("Error reading from priv fifo: %s\n", strerror(errno)); // 6) receive server acknowldgement
  }
  remove(pid); // 6) remove private fifo

  if(write(*to_server, acknlgmt3, sizeof(acknlgmt3)) == -1){ // 7) client sends response to server
    printf("Error writing to wkp\n");
  }

  return from_server;
}
