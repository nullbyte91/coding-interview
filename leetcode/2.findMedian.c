/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double median;
    int len = nums1Size + nums2Size;
    
    int *arr = (int*)malloc(len * sizeof(int));
    
    int nl = nums1Size;
    int nr = nums2Size;

    int i = 0, j=0, k =0;
    while(i < nl && j < nr){    //0<2 && 0<2 T, 1<2 && 0<2
        
        if(nums1[i] <= nums2[j]){ //1<=3 T, 2<=4
            arr[k] = nums1[i];    //arr[0]=1, arr[1]=2
            i +=1;                //i=1, i=2,
        } else {
            arr[k] = nums2[j];
            j +=1;
        }
        
        k +=1;                    //k = 1, k=2
    }
    for (int i=0; i<len; i++){
        printf("Data: %d", arr[i]);
    }
    
    while (i<nl)                    //2<2 F
    {
        arr[k] = nums1[i];
        i+=1;
        k+=1;
    }
    
    while (j<nr)                    
    {
        arr[k] = nums2[j];
        j+=1;
        k+=1;
    }
    
    int median_pos = -1;
    
    for (int i=0; i<len; i++){
        printf("Data: %d", arr[i]);
    }
    //check array has odd or even length
    if (len % 2){
        median_pos = len / 2;
        median = arr[median_pos];
    } else {
        median_pos = len / 2;
        printf("median_pos:%d ", median_pos);
        median = arr[median_pos] + arr[median_pos-1];
        median/=2;
        printf("median:%lf", median);
    }
    
    return median;
}

int main()
{
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    int nums1Size = sizeof(nums1)/sizeof(nums1[0]);
    int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
    findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    return 0;
}

