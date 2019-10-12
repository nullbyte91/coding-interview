#include <stdio.h>

#define MAX 100
#define NIL -1

int lookup[MAX];

void _initilization(){
    for (int i=0; i<MAX; i++){
        lookup[i] = NIL;
    }
}

int recursive(int num){
    if (num <= 1){
        return num;
    } else {
        return recursive(num - 1) + recursive(num - 2);
    }
}

int memoization(int num){
    if (lookup[num] == NIL){
        if (num <=1){
            return num;
        } else {
            lookup[num] = memoization(num-1) + memoization(num-2);
        }
    }
    return lookup[num];
}

int tabulation(int num){
    int t[num+1];
    t[0] = 0; 
    t[1] = 1;
    for (int i=2; i<=num; i++){
        t[i] = t[i-1] + t[i-2];
    }
    return t[num];
}

int main()
{
    int num;
    printf("Enter the number\n");
    scanf("%d", &num);
    int fib_val = recursive(num);
    printf("%d\n", fib_val);
    
    _initilization();
    fib_val = memoization(num);
    printf("%d\n", fib_val);

    fib_val = tabulation(num);
    printf("%d\n", fib_val);
    return 0;
}