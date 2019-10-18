#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node* llnode;

void
insert(llnode* rootPtr, int data){
    llnode temp = malloc(sizeof(llnode));
    temp->data = data;
    temp->next = NULL;

    if (rootPtr == NULL){
        *(rootPtr) = temp;
    }

    temp->next = *(rootPtr);
    *(rootPtr) = temp;
}

void
show(llnode* rootPtr){
    llnode temp = *rootPtr;
    while(temp != NULL){
        printf("Data:%d ", temp->data);
        temp = temp->next;
    }
}

void
detectLoop(llnode* rootPtr){
    llnode fast = *rootPtr;
    llnode slow = *rootPtr;
    while (fast != NULL && fast->next != NULL){
        if(fast == slow){
            printf("Hit the conditon\n");
            break;
        }
        fast = fast->next;
        slow = slow->next;
    }

    if (fast == NULL || fast->next == NULL){
        return;
    }

    slow = *(rootPtr);
    while ( slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    printf("%d", fast->data);
}

int
main(int argc, char** argcv){
    llnode rootPtr = NULL;
    insert(&rootPtr, 10);
    insert(&rootPtr, 20);
    insert(&rootPtr, 30);
    insert(&rootPtr, 40);
    insert(&rootPtr, 50);
    insert(&rootPtr, 60);

    //create a loop
    rootPtr->next->next->next->next->next->next = rootPtr->next->next;

    //show(&rootPtr);
    detectLoop(&rootPtr);
    return 0;
}