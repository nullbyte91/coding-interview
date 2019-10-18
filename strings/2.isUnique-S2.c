#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isUnique(char inS[], int len){
    int i, val, checker=0;
    if (len > 128){
        return false;
    }
    for (i=0; i<len; i++){
        val = inS[i] - 'a';

        if ((checker & (1 << val))){
            return false;
        }
        checker |= (1 << val);
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