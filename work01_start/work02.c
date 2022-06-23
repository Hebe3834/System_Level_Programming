#include <stdio.h>

int main() {

  printf("%s\n", "Hello World!");

  unsigned int usi = 5;
  printf("%d\n", usi);

  unsigned int usi0 = -5;
  printf("%d\n", usi0);

  char letter = 'r';
  printf("%c", letter);

  short badNum = 32772;
  printf("%d\n", badNum);

  maths(10, 1.5);

  return 0;
}

maths(int n, double d){
  printf("%lf", n/d);
}
