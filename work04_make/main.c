#include <stdio.h>
#include "euler.h"

int main(){
  int p1ex = problem1(10);
  printf("Problem 1 example: %d\n", p1ex);
  int p1 = problem1(1000);
  printf("Problem 1 solution: %d\n", p1);

  int p5ex = problem5(10);
  printf("Problem 5 example: %d\n", p5ex);
  int p5 = problem5(20);
  printf("Problem 5 solution: %d\n", p5);

  int p6ex = problem6(10);
  printf("Problem 6 example: %d\n", p6ex);
  int p6 = problem6(20);
  printf("Problem 6 solution: %d\n", p6);

}
