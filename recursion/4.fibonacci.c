// Algo for fibonacci using recursion
#include <stdio.h>
int sum =0;
int fib_sum(int num){
    //Base case
    if (num <= 1){
        return num;
    } else { //recursive case
        return fib_sum(num-1) + fib_sum(num-2);
    }   

}

int main(){
    int num;
    printf("Enter the number\n");
    scanf("%d", &num);
    printf("%d", fib_sum(num));
    return 0;
}