#include <stdio.h>


void 
insertionSort(int in[], int n){
    int i, key, current;
    for (i=1; i<n; i++){
        key = in[i];
        current = i - 1;
        while (current>=0 && in[current]>key){
            in[current+1] = in[current];
            current = current -1;
        }
        in[current+1] = key;
    }
}
#define N 10
int 
main(int argc, char** argcv){
    int a1[N];
    int i;
    for (i=0; i<N; i++){
        a1[i] = N - i - 1;
    }

    // Test Before sorting
    for (i=0; i<N; i++){
        printf("%d ", a1[i]);
    }

    putchar('\n');

    insertionSort(a1, N);

    // Test After sorting
    for (i=0; i<N; i++){
        printf("%d ", a1[i]);
    }

    return 0;
}