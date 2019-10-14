#include <stdio.h>

void insertionSort(int a[], int len){
    int key = 0, current, i;
    printf("Before Sorting\n");
    for (i=0; i<len; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int start=1; start < len; start++){
        key = a[start];
        current = start - 1;
        while (current >=0 && a[current] > key){
            a[current+1] = a[current];
            current = current - 1; 
        }
        a[current+1] = key;
    }
    printf("After Sorting\n");
    for (i=0; i<len; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {5, 6, 2, 8, 10, 9};
    int len = sizeof(a)/sizeof(a[0]);
    insertionSort(a, len);
    return 0;
}