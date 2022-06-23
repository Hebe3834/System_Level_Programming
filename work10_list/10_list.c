#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct animal{
  int num_legs;
  char name[20];
  struct animal *next;
};

void print_struct(struct animal *p){
  printf("The %s is an animal with %d legs\n", p->name, p->num_legs);
  return;
}

struct animal * make_struct(int l, char *n){
  struct animal *a = malloc(sizeof(struct animal));
  a->num_legs = l;
  strcpy(a->name, n);
  a->next = NULL;
  return a;
}

// takes a pointer to a node struct, prints out all of the data in the list
void print_list(struct animal *p){
  while(p){
    print_struct(p);
    p = p->next;
  }
  return;
}

// takes a pointer to the existing list and the data to be added, 
// create a new node and puts it at the beginning of the list.
// Returns a pointer to the beginning of the list.
struct animal * insert_front(struct animal *p, int l, char *n){
  struct animal *p1 = make_struct(l, n);
  p1->next = p;
  return p1;
}

// takes a pointer to a list as a parameter and then goes through 
// the entire list freeing each node and returns a pointer to the 
// beginning of the list
struct animal * free_list(struct animal *p){
  while(p){
    struct animal *tmp = p;
    p = p->next;
    free(tmp);
  }
  return p;
}

// Removes the first node containing data from the list pointed to by front
struct animal * remove_animal(struct animal *front, int data){
  struct animal *tmp = front;
  struct animal *first = front;
  if(front->num_legs == data){
    front = front->next;
    free(tmp);
    return front;
  }
  front = front->next;
  while(front){
    if(front->num_legs == data){
      tmp->next = front->next;
      free(front);
      return first;
    }
    front = front->next;
    tmp = tmp->next;
  }
  return first;
}
