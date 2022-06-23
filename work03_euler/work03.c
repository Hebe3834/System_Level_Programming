
#include <stdio.h>

int problem1(int lim);
int problem5(int n);
int problem6(int n);

int main(){
  int p1ex = problem1(10);
  printf("%d\n", p1ex);
  int p1 = problem1(1000);
  printf("%d\n", p1);

  int p5ex = problem5(10);
  printf("%d\n", p5ex);
  int p5 = problem5(20);
  printf("%d\n", p5);

  int p6ex = problem6(10);
  printf("%d\n", p6ex);
  int p6 = problem6(20);
  printf("%d\n", p6);

}

int problem1(int lim){
  int x = 1;
  int sum = 0;
  for(x = 1; x < lim; x++){
    if(x % 3 == 0){
      sum += x;
    }
    else if(x % 5 == 0){
      sum += x;
    }
  }
  return sum;
}

int problem5(int n){
  int try = n;
  int i = 1;
  int continu = 1;
  while(1){
    for(i = 1; i <= n; i++){
      if(try % i != 0){
	break;
      }
      else if(i == n){
	return try;
      }
    }
    try += n;
  }
}

int problem6(int n){
  int sum_squares = 0;
  int square_sums = 0;
  int i = 1;
  for(i=1; i<=n; i++){
    sum_squares += (i*i);
  }
  i = 1;
  for(i=1; i<=n; i++){
    square_sums += i;
  }
  square_sums *= square_sums;
  return square_sums - sum_squares;
}
