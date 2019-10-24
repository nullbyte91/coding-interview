#include <stdio.h>
#define MAX_SIZE 5
#define EMPTY -1

int Queue[MAX_SIZE];
int front = EMPTY;
int rear = EMPTY;

int isQueueFull()
{
    return rear == MAX_SIZE - 1;
}

int isQueueEmpty()
{
    return front == rear;
}
void
enQueue(int num){

    if (isQueueFull()){
        printf("Queue is full\n");
        return;
    }

    if (front == EMPTY){
        ++front;
    }
    Queue[++rear] = num;
}

void
deQueue(){
    if (isQueueEmpty()){
        printf("Empty Queue\n");
        return;
    }
    if (front == rear){
        front = -1;
        rear = -1;
    }
    ++front;
}

void
display(){
    for (int i=front; i<=rear; i++){
        printf("Data:%d ", Queue[i]);
    }
    putchar('\n');
}

int
main(int argc, char** argcv){
    int option, num;
    while(1){
        printf("Enter the option\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the number\n");
                scanf("%d", &num);
                enQueue(num);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                return 0;
        }
    }

    return 0;
}