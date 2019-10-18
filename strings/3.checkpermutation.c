#include <stdio.h>

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
int partition(char a[], int start, int end){
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
quickSort(char a[], int start, int end){
    if (start < end){
        int index = partition(a, start, end);
        quickSort(a, start, index -1);
        quickSort(a, index+1, end);
    }
}

int
main(int argc, char** argcv){
    char a[] = "jegathesan";
    char a1[] = "jesan";
    int len = sizeof(a)/sizeof(a[0]);
    int len1 = sizeof(a1)/sizeof(a1[0]);
    quickSort(a, 0, len);
    for (int i=0; i<len1; i++){
        printf("%c ", a1[i]);
    }
    putchar('\n');
    quickSort(a1, 0, len1-1);
    for (int i=0; i<len1; i++){
        printf("%c ", a1[i]);
    }
    int ret = strcmp(a, a1);
    
    printf("%d ", ret);
    return 0;
}