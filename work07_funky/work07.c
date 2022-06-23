#include <stdio.h>

    
//Write a function that takes an array of int values as a parameter and prints it out.
void printNums(int *arr, int len){
    printf("%c ", '[');
    int i;
    for(i=0; i<len; i++){
        printf("%d ", *(arr+i));
    }
    printf("%c\n", ']');
}

//Write a function that takes an array of int values as a parameter and returns the average of those values.
double findAvg(int *arr, int len){
    int i;
    double sum = 0;
    for(i=0; i<len; i++){
        sum += *(arr+i);
    }
    return sum/len;
}

//Write a function that takes 2 arrays of equal size as paramters. it should copy the values of the first array into the second
void copyArr(int *arr1, int *arr2, int len){
    int i;
    for(i=0; i<len; i++){
        *(arr2+i) = *(arr1+i);
    }
}

int main(){
    // Testing
    int arr[7] = {0, 1, 2, 3, 4, 5, 6};
    printNums(arr, 7);
    printf("%f\n", findAvg(arr, 7));

    int arr1[5] = {11, 12, 13, 14, 15};
    int arr2[5];
    copyArr(arr1, arr2, 5);
    printNums(arr2, 5);

    return 0;
}
