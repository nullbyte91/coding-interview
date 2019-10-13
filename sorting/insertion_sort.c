// Pseudocode
/*
     1  2  3  4  5  6           1 2   3  4 5   6
A = [5, 2, 4, 6, 1, 3]          2, 5, 4, 6, 1, 3      
for j=2 to A.length
    key = A[j]                  //key = 2, 4
    // Insert A[j] inti the sorted seq A[1....j-1]
    i = j - 1                   // i = 1  2  
    while i> 0 and A[i] > key   // 1>0 True && 5>2 0>1 False 2>0 True && 5>4
    A[i+1] = A[i]               // A[2] = 5                 A[3] = 5
    i = i - 1                   // i = 0                    i = 1

#include <>    A[i+1] = key                // A[1] = 2                 A[2] = 44543e`
*/

#include <stdio.h>

void insertionSort(int a[], int len){
    int key, start;
    for (int i = 0; i<len; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int current=1; current < len; current++){ 
        key = a[current];
        start = current - 1;
        while(current >0 && a[start] > key){
            a[start+1] = a[start];
            // start = start - 1;
            a[start] =key;
        }
    }
    for (int i = 0; i<len; i++){
        printf("%d ", a[i]);
    }

    
}

int main(){
    int a[] = {31, 41, 59, 26, 41, 58};
    int len = sizeof(a)/ sizeof(a[0]);
    insertionSort(a, len);
    return 0;
}
