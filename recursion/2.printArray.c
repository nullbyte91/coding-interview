// Algo to print a array using recursion

#include <stdio.h>
#define MAX_SIZE 100

void printA(int a[], int len){
    //base case
    if (len<=0){
        printf("\n");
        return;
    } else {
        printf("%d ", *(a+0));
        printA(a+1, len-1); // Recursive 
        printf("%d ", *(a+0)); //backtracking
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    printA(arr, len);
    return 0;
}
