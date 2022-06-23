#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  // 1. Create an array large enough to store 10 ints.
  int randints[10];

  // 2. Set the first value in the array to 0. 3`. Populate the array with random values
  randints[0] = 0;
  //rand values
  int i;
  srand(time(NULL));
  for(i=1; i<=10; i++){
    randints[i] = rand();
  }
    
  // 3. Print out the values in this array
  for(i=0; i<10; i++){
    printf("%d, ", randints[i]);
  }

  // 4. Create a separate array large enough to store 10 ints.
  int revints[10];

  // 5. Create pointer variables that will point to each array.
  int *randp = randints;
  int *revp = revints;

  // 6. Populate the second array with the values in the first but in reverse order
  int n;
  for(n=10; n>0; n--){
    *(revp+10 - n) = *(randp+n-1);
  }

  // Print out the values in the second array. Try this using both [] and *.
  printf("\n");
  for(n=0; n<10; n++){
    printf("%d, ", revints[n]);
  }
  printf("\n");
  for(n=0; n<10; n++){
    printf("%d, ", *(revp+n));
  }
  printf("\n");
  
  return 0;
}
