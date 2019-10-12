// Algo to print a array using recursion

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool coreFun(char *str, int start, int end){
    if (start == end){
        return true;
    }

    if (*(str+start)  != *(str+end)){
        return false;
    }
    
    if (start < end +1){
        return coreFun(str, start+1, end-1);
    }

    return true;
}
bool isPalindrome(char *str){
    if (strlen(str) == 0){
        return false;
    } else {
        return coreFun(str, 0, strlen(str)-1);
    }
    
}

int main()
{
    char str[] = "ABCDCCBA";
    if (isPalindrome(str))
    {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}