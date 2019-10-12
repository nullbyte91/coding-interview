#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void naiveS(int a[], int b[], int sum){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if ((a[i] + b[j]) == sum){
                printf("{a:%d b:%d}", a[i], b[j]);
            }
        }
    }
}

void recursive(int a[], int b[], int sum){
    //Base contition
    if ((a+b) == sum){
        printf("{a:%d b:%d}", a, b);
        return 0;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int lenA = sizeof(a)/sizeof(a[0]);
    int lenB = sizeof(b)/sizeof(b[0]);
    int sum = 10;
    naiveS(a, b, sum);
    recursive(a, b, sum);
    return 0;
}