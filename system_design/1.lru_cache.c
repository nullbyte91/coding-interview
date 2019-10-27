#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct QNode{
    int pageNumber;
    struct Qnode *prev, *next; 
} Qnode;

typedef struct Queue{
    int count;
    int max_frames;
    Qnode *front, *rear;
} Queue;

typedef struct Hash{
    int capacity;
    Qnode** array;
}Hash;

Queue*
craeteQueue(int max_frames){
    Queue* queue = malloc(sizeof(Queue));
    assert(queue);

    queue->max_frames = max_frames;
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

Hash* 
createHash(int capacity){
    Hash* hash = malloc(sizeof(Hash));
    hash->capacity = capacity;
    hash->array = malloc(sizeof(Qnode*) * capacity);
    assert(hash->array);

    for (int i=0; i<capacity; i++){
        hash->array[i] = NULL;
    }
    return hash;
}

bool
isQueueFull(Queue* q){
    if (q->count == q->max_frames){
        return true;
    }
    return false;
}

bool
isQueueEmpty(Queue* q){
    if (q->count == 0){
        return true;
    }
    return false;
}

Qnode* getNewNode(int pageNumber){
        
    Qnode* newNode = (Qnode*)malloc(sizeof(Qnode));
    assert(newNode);

    newNode->pageNumber = pageNumber;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void
deQueue(Queue* q){
    Qnode* deleteNode = q->rear;
}

void
enQueue(Queue* q, Hash* h, int pageNumber){
    // isQueue Full / isQueue Empty
    if (isQueueFull(q)){
        h->array[q->rear->pageNumber] = NULL;
        deQueue(q);
    }

    Qnode* newNode = getNewNode(pageNumber);
    newNode->next = q->front;
    if (isQueueEmpty(q)){
        printf("Queue empty\n");
        q->front = newNode;
        q->rear = newNode;
    } else {
        printf("Queue not empty\n");
        q->front->prev = newNode;
        q->front = newNode;

    }
    q->count++;
    h->array[pageNumber] = newNode;
}

void
referencePage(Queue* q, Hash* h, int page_number){
    Qnode* reqPage = h->array[page_number];

    if (reqPage == NULL){
        enQueue(q, h, page_number);
    }
}

int
main(int argc, char** argcv){
    Queue* queue = craeteQueue(4);
    Hash* hash = createHash(10);

    referencePage(queue, hash, 0);
    referencePage(queue, hash, 1);
    referencePage(queue, hash, 2);
    referencePage(queue, hash, 3);
    referencePage(queue, hash, 4);
    return 0;
}