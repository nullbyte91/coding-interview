#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isUnique(char inS[], int len){
    int i, val;
    if (len > 128){
        return false;
    }

    // created 1D bool table
    int *boolA = malloc(sizeof(int) * 128);
    memset(boolA, 0, sizeof(boolA));

    for (i=0; i<strlen(inS); i++){
        val = inS[i];
        if (boolA[val]){
            return false;
        }
        boolA[val] = 1; 
    }
    return true;
}

int
main(int argc, char** argcv){
    char inS[] = "jega";
    int len = strlen(inS);
    if (isUnique(inS, len)){
        printf("Unique\n");
    } else {
        printf("Not Unique\n");
    }
    return 0;
}