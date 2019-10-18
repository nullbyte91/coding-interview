#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int* getFreqT(char inS[], int len){
    int val;
    int* hashCount = malloc(sizeof(int) * 26);
    memset(hashCount, 0, sizeof(hashCount));

    for (int i=0; i<len-1; i++){
        val = inS[i] - 'a';
        if (val != -65){
            hashCount[val]++;
        }
    }
    return hashCount;
}

bool isPermutationPalindrome(char inS[], int len){
    int* freqT = getFreqT(inS, len);
    bool oddFound = false;
    for (int i=0; i<26; i++){
        if (freqT[i]%2 == 1){
            if (oddFound){
                return false;
            }
            oddFound = true;
        }
    }

    return true;
}

int 
main(int argc, char** argcv){
    char inS[] = "tac at";
    int len = sizeof(inS)/sizeof(inS[0]);
    bool result = isPermutationPalindrome(inS, len);
    if (result == true){
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}