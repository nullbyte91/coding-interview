#include <stdbool.h>
#include <limits.h>

#define max(a, b) \
({  __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? a: b;})

#define min(a, b) \
({  __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? a: b;})

int
maxArea(int* A, int len){
    int l = 0; 
    int r = len -1; 
    int area = 0; 
      
    while (l < r) 
    { 
        area = max(area, min(A[l], 
                        A[r]) * (r - l));             
        if (A[l] < A[r]){
            l += 1; 
        } else {
            r -= 1;
        }
    } 
    return area; 
}