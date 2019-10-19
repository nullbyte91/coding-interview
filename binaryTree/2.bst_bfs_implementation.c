#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct elt{
    struct node* bstnode;
    struct elt* next;
};

struct queue{
    struct elt* head;
    struct elt* tail;
};

/* check is Queue empty */
int
isEmpty(struct queue* q){
    return (q->head == 0);
}

struct queue*
createEmptyQueue(){
    struct queue* q = malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void
enQueue(struct queue* q, struct node* rootPtr){
    struct elt* e = malloc(sizeof(struct elt));
    e->bstnode = rootPtr;
    e->next = NULL;
    
    if (q->head == NULL){
        q->head = e;
    } else {
        q->tail->next = e;
    }
    q->tail = e;
}

struct node*
deQueue(struct queue* q){
    struct elt* e;
    struct node* temp;
    /* check queue is empty*/
    if (isEmpty(q) == 1){
        return 0;
    }
    e = q->head;
    temp = e->bstnode;
    q->head = e->next;
    free(e);
    return temp;
}

int
isQueueEmpty(struct queue* q){
    return(q->head == NULL);
}

struct node* 
getNewnode(int data){   
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
}

 
struct node*
insert(struct node* rootPtr, int data){
    if (rootPtr == NULL){
        rootPtr = getNewnode(data);
    } else if (data <= rootPtr->data){
        rootPtr->left = insert(rootPtr->left, data);
    } else if (data >= rootPtr->data){
        rootPtr->right = insert(rootPtr->right, data);
    }
    return rootPtr;
}

void 
level_order(struct node* rootPtr){
    // Create a Empty queue
    struct queue* Queue = createEmptyQueue();
    struct node* current = rootPtr;
    //enQueue(Queue, rootPtr);
    while(current){
        printf("Data:%d ", current->data);

        // Enqueue left 
        if (current->left != NULL){
            enQueue(Queue, current->left);
        }
        // Enqueue right 
        if (current->right != NULL){
            enQueue(Queue, current->right);
        }
        current = deQueue(Queue);
    }
}

int 
main(int argc, char** argcv){
    struct node* rootPtr = NULL;

    // Insert Operation
    rootPtr = insert(rootPtr, 5);
    rootPtr = insert(rootPtr, 4);
    rootPtr = insert(rootPtr, 6);
    rootPtr = insert(rootPtr, 3);
    rootPtr = insert(rootPtr, 2);
    rootPtr = insert(rootPtr, 1);
    rootPtr = insert(rootPtr, 7);
    
    // Traversal 
    // 1. BFS ()
    level_order(rootPtr);
    return 0;
}
