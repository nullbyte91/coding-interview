#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int search(int X, int **arr) 
{ 
    if (X >= 0) { 
        if (arr[X][0] == 1) 
            return 1; 
        else
            return 0; 
    } 
  
    // if X is negative take the absolute  
    // value of X. 
    X = abs(X); 
    if (arr[X][1] == 1) 
        return 1; 
  
    return 0; 
} 

void insert(int a[], int **arr, int n) 
{ 
    for (int i = 0; i < n; i++) { 
        if (a[i] >= 0)  
            arr[a[i]][0] = 1; 
       else
            arr[abs(a[i])][1] = 1; 
    } 
}
int main(){
    int a[] = { -1, 9, -5, -8, -5, -2 }; 
    int n = sizeof(a)/sizeof(a[0]); 
    int **arr = (int **)malloc(MAX * sizeof(int *)); 
    for (int i=0; i<MAX; i++) 
         arr[i] = (int *)malloc(2 * sizeof(int)); 
    insert(a, arr, n);
    int X = -1; 
    if (search(X, arr) == 1) 
        printf("Present\n");  
    else
       printf("Not Present\n"); 
    free(arr);
    return 0;
}