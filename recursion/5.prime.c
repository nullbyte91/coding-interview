#include <stdio.h>

//Navive algo
void nPrime(int num){
    printf("%d %d ", 2, 3);
    for (int i=5; i <=num; i++){
        if (i % 2 == 0 || i % 3 == 0){
            continue;
        } else {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    int num = 0;
    printf("Enter the number\n");
    scanf("%d", &num);
    nPrime(num);
    return 0;
}