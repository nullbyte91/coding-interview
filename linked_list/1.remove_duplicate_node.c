#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1000

struct node{
    int data;
    struct node* next;
};

typedef struct node *llnode;

void
removeDuplicate(const llnode* rootPtr){
    int hashTable[MAX_SIZE] = {0};
    llnode previous = *rootPtr;
    llnode temp = *rootPtr;
    while(temp != NULL){
        if (hashTable[temp->data] != 0){
            previous->next = temp->next;
            free(temp);
        } else {
            hashTable[temp->data] = 1;
            previous = temp;
        }
        temp = temp->next;
    }

}

void 
insertNode(llnode* rootPtr, int data){
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
show(const llnode* rootPtr){
    llnode temp = *rootPtr;
    while(temp != NULL){
        printf("Data: %d ", temp->data);
        temp = temp->next;
    }
    putchar('\n');
}

int 
main(int argc, char** argcv){
    llnode rootPtr = NULL;
    insertNode(&rootPtr, 10);
    insertNode(&rootPtr, 20);
    insertNode(&rootPtr, 40);
    insertNode(&rootPtr, 30);
    insertNode(&rootPtr, 40);
    show(&rootPtr);
    removeDuplicate(&rootPtr);
    show(&rootPtr);
    return 0;
}
