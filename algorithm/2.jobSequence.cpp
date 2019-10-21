#include <stdio.h>
#include<iostream>
#include <algorithm>

struct Job{
    char id;
    int ded, profit;
};

bool compare(Job a, Job b){
    return a.profit > b.profit;
}

void
jobScheduling(Job arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i].profit);
    }
    putchar('\n');
    std::sort(arr, arr+n, compare);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i].profit);
    }
    putchar('\n');

    int result[n];
    bool slot[n];
    
    for (int i=0; i<n; i++){
        slot[i] = false;
    }

    for (int i=0; i<n; i++) 
    { 
       // Find a free slot for this job (Note that we start 
       // from the last possible slot) 
       for (int j=std::min(n, arr[i].ded)-1; j>=0; j--) 
       { 
          // Free slot found 
          if (slot[j]==false) 
          { 
             result[j] = i;  // Add this job to result 
             slot[j] = true; // Make this slot occupied 
             break; 
          } 
       } 
    } 
    // Print the result 
    for (int i=0; i<n; i++){ 
       if (slot[i]) {
         printf("%c ", arr[result[i]].id);
        }
    }
}

int 
main(int argc, char** argcv)
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    jobScheduling(arr, n);
}
