#include <stdio.h>
#include <stdlib.h>

struct Intervals{
    int start, end;  
};

static int cmprow(const void *a, const void *b)
{
    const int * const ia = a, * const ib = b;
    return ia[0] < ib[0] ? -1 : ia[0] > ib[0];
}

int 
main(int argc, char** argcv){
    struct Intervals arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before swap:\n");
    for (int i=0; i<n; i++){
        printf("S:%d ", arr[i].start);
        printf("S:%d\n", arr[i].end);
    } 
    qsort(arr, n, sizeof *arr, cmprow);
    printf("After swap:\n");
    for (int i=0; i<n; i++){
        printf("S:%d ", arr[i].start);
        printf("S:%d\n", arr[i].end);
    }
    return 0;
}