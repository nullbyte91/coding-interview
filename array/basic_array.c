#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// 1D array creation on stack
void singleDimStack(){
    int A[10];
    int len = sizeof(A) / sizeof(A[0]);
    for(int i=0; i<len; i++){
        A[i] = i;
    }
    for(int i=0; i<len; i++){
        printf("%d ", A[i]);
    }
    printf("\n\n");
}

// 2D dim array creation on stack
void TwoDimStack(){
    int A[10][10];
    int len = sizeof(A) / sizeof(A[0]);
    
    for(int i=0; i<len; i++){
       for(int j=0; j<len; j++){
           A[i][j] = i+j;
       }
    }
    for(int i=0; i<len; i++){
       for(int j=0; j<len; j++){
           printf("%d ", A[i][j]);
       }
       printf("\n");
    }
    printf("\n\n");
}

// 1D Array on Heap
void singleDHeap(){
    int *p = (int*)malloc(sizeof(SIZE)/sizeof(int));
    for(int i=0; i<SIZE; i++){
        *(p+i) = i;
    }
    for(int i=0; i<SIZE; i++){
        printf("%d ", *(p+i));
    }   
    free(p);
    printf("\n");
}

// 2D Array on Heap with single Pointer
void TwoDHeap(){
    int *p = (int*)malloc((sizeof(SIZE) * sizeof(SIZE)) /sizeof(int));
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            *(p+ i*SIZE + j) = i+j;
        }
    }

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%d ", *(p+ i*SIZE + j));
        }
        printf("\n");
    }
    free(p);   
    printf("\n");
}

int main()
{
    singleDimStack();
    TwoDimStack();
    singleDHeap();
    TwoDHeap();
    return 0;
}