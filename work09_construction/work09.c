#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct animal{
  int num_legs;
  char name[10];
};

void print_struct(struct animal *p){
  printf("This %s is an animal with %d legs\n", p->name, p->num_legs);
  return;
}

struct animal * make_struct(int l, char *n){
  struct animal *a = malloc(sizeof(struct animal));
  a->num_legs = l;
  strcpy(a->name, n);
  return a;
}

int main(){
  srand(time(NULL));
  int i;
  for(i=0; i<10; i++){
    int l = rand();
    char n[10] =  "Alien";
    struct animal *a = make_struct(l, n);
    print_struct(a);
    free(a);
  }
  return 0;
}
