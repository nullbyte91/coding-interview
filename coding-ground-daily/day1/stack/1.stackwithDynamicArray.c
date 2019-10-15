#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3

//Global top to track the peek/top
int top = -1;

// To maintain for grow array
int len = 0;

// Global pointer 
int* a;

int* 
createNew(int a[]){
    int i;
    int* newA = (int*)malloc(sizeof(int) * MAX+len);
    for(i = 0; i<=top; i++){
        newA[i] = a[i];
    }
    len+=MAX;
    return newA;
}

void 
insert(int a[], int num){

    if (top == len-1){
        a = createNew(a);
    }
    top+=1;
    a[top] = num;
    printf("Data:%d ", a[top]);
}

void 
pop(){
    return;
}

int
peek(){
    return 0; 
}

void 
show(int a[])
{
    int i;
    for(i=0; i<=len-1; i++){
        printf("Data:%d ", a[i]);
    }
    printf("\n");
}

int
main(int argc, char** argcv){
    int option, num;
    a = (int*) malloc (sizeof(int) * MAX);
    len+=MAX;
    while(1){
        printf("Enter the option\n");
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Peek/top \n");
        printf("4.Show \n");
        printf("5.Exit\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter the number\n");
                scanf("%d", &num);
                insert(a, num);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                show(a);
                break;
            case 5:
                return 0;
            default:
                printf("I didn't understand the option\n");
                return 0;
        }
    }
    return 0;
}