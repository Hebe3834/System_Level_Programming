#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "10_list.h"

int main(){
  char n[20] = "Oshawott";
  char n1[20] = "Dewott";
  char n2[20] = "Samurott";
  struct animal *a = make_struct(2, n);
  print_list(a);
  printf("\n");

  a = insert_front(a, 2, n1);
  a = insert_front(a, 4, n2);
  print_list(a);
  printf("\n");

  a = remove_animal(a, 2);
  print_list(a);                                                          printf("\n");  

  a = free_list(a);
  print_list(a);

  return 0;
}

