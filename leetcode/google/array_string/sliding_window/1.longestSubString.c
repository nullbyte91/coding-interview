#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s){
    int i, startWindow = 0, endWindow, gMaxSubString = 0, lMaxSubString = 0;
    int len = strlen(s);
    int* hashT = malloc(len * sizeof(int));
    for (i=0; i<len; i++){
        hashT[i] = -1;   
    }
    
    for (endWindow=0; endWindow <len; endWindow++){
        int gindex;
        gindex = s[endWindow] - 'a';
        printf("index:%d", gindex);
        printf("%d ", gindex);
        if (hashT[gindex] != 0){
            hashT[gindex] += 1;
            lMaxSubString = endWindow+1 - startWindow;
            printf("%d ", lMaxSubString);
            if (lMaxSubString > gMaxSubString){
                gMaxSubString = lMaxSubString;
            }
            continue;
        }
        
        while(startWindow < endWindow -1){
            int lindex = s[startWindow] - 'a';
            if (hashT[lindex] != hashT[gindex]){
                hashT[lindex] = 0;
                startWindow++;
            } else {
                startWindow++;
                break;
            }
        }
        
    }
    return gMaxSubString;
}

int 
main(int argc, char** argcv){
    char s[] = ""   "";

    printf("%d ", lengthOfLongestSubstring(s));
    return 0;
}