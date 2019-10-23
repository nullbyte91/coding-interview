#include <stdio.h>
#include <limits.h>

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
   _a > _b ? _a : _b; })

int findMax(int arr[], int len, int k){
    int maxValue = INT_MIN;
    int currentRunningSum = 0;

    for (int i=0; i<len; i++){
        currentRunningSum += arr[i];
        
        if (i >= k-1){
            maxValue = max(maxValue, currentRunningSum);
            currentRunningSum -= arr[i - (k - 1)];
        }
    }
    return maxValue;
}

int 
main(int argc, char** argcv){
    int a[] = {4, 2, 1, 7, 8, 1, 2, 8, 1, 0};
    int len = sizeof(a)/sizeof(a[0]);
    int r = findMax(a, len, 3);
    printf("%d", r);
    return 0;
}