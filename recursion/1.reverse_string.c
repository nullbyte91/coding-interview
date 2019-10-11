// Algo to reverse a string using recursion

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void reverse(char *string) 
{
    // Base Case 
    if (strlen(string) == 0){
        return;
    } 
    else 
    { 
        reverse(string+1); // Recursive 
        printf("%c", *string); //backtracking
    } 
}
int main()
{
    char string[MAX_SIZE];
    printf("Enter the string:\n");
    scanf("%s", string);
    reverse(string);
    return 0;
}