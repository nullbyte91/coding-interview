#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 26

void naiveS(char *str){
    for(char c='a'; c<='z'; c++){
        int frq = 0;
        for (int i=0; i<strlen(str); i++){
            if (c == str[i]){
                frq +=1;
            }
        }
        printf("%c = %d", c, frq);
        printf("\n");
    }
}

int hashFun(char key){
    return (key - 'a');
}

void hashMap(char *str){
    int index;
    int *arr = (int*)malloc(MAX_SIZE * sizeof(int));
    for (int i=0; i<MAX_SIZE; i++){
        *(arr+i) = 0;
    }
    for(int i=0; i<strlen(str); i++){
        index = hashFun(str[i]);
        *(arr+index) +=1;
    }
    int i=0;
    for (char c='a'; c<='z'; c++){
        printf("%c = %d ", c, *(arr+i));
        i++;
        printf("\n");
    }
}

int main()
{
    char *str = "ababcd";
    naiveS(str); // naive solution
    hashMap(str); //hash Map solution
    return 0;
}