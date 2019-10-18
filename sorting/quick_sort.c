#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int start, int end){
    int pivot, index, i, temp;
    pivot = a[end];
    index = start;
    for (i=start; i<end; i++){
        if (a[i] <= pivot){
            swap(&a[i], &a[index]);
            index +=1;
        }
    }
    swap(&a[index], &a[end]);
    return index;
}

void
quickSort(int a[], int start, int end){
    if (start < end){
        int index = partition(a, start, end);
        quickSort(a, start, index -1);
        quickSort(a, index+1, end);
    }
}

int
main(int argc, char** argcv){
    int a[] = {7, 9, 1, 0, 5, 8, 4};
    int len = sizeof(a)/sizeof(a[0]);
    for (int i=0; i<len; i++){
        printf("%d ", a[i]);
    }
    putchar('\n');
    quickSort(a, 0, len-1);
    for (int i=0; i<len; i++){
        printf("%d ", a[i]);
    }
    putchar('\n');
    return 0;
}