#define max(a, b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
   a > b ? a : b ; })

#define min(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
   a < b ? a : b ; })

int findarea(int A[], int left, int len){
    int l = 0; 
    int r = len -1; 
    int area = 0; 
      
    while (l < r) 
    { 
        // Calculating the max area 
        area = max(area, min(A[l], 
                        A[r]) * (r - l)); 
                          
            if (A[l] < A[r]) 
                l += 1; 
                  
            else
                r -= 1; 
    } 
    return area; 
}

int maxArea(int* height, int heightSize){
    return findarea(height, 0, heightSize);
}

