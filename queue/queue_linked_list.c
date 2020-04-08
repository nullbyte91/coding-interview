#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct elt{
    int data;
    struct elt* next;
};

struct queue{
    struct elt* head; /* dequeue */
    struct elt* tail; /* enqueue */
};

/* create a new empty queue */
struct queue*
createQueue(){
    struct queue* q = malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
}

/* Add value to queue */
void
enQueue(struct queue* q, int data){
    struct elt* e = malloc(sizeof(struct elt));
    e->data = data;
    e->next = NULL;

    if (q->head == NULL){
        q->head = e;
    } else {
        q->tail->next = e;
    }
    q->tail = e;
}

/* check is Queue empty */
int
isEmpty(struct queue* q){
    return (q->head == 0);
}

/* function to travel queue */
void
traversal(struct queue* q){
    struct elt* e;

    assert(!isEmpty(q));

    for(e=q->head; e!=0; e = e->next){
        printf("Data:%d ", e->data);
    }
}

/* delete the value from head pointer */
int
deQueue(struct queue* q){
    struct elt *e;
    int deQueue_val;

    /* check queue is empty*/
    assert(!isEmpty(q));

    deQueue_val = q->head->data;
    e = q->head;
    q->head = e->next;
    free(e);
    return deQueue_val;   
}

/* main */
int 
main(int agrc, char** argcv){
    struct queue* Queue = createQueue();  
    
    enQueue(Queue, 10);
    enQueue(Queue, 20);
    enQueue(Queue, 30);
    enQueue(Queue, 40);
    enQueue(Queue, 50);
    enQueue(Queue, 60);
    enQueue(Queue, 70);

    // traversal 
    traversal(Queue);

    printf("%d ", deQueue(Queue));
    return 0;
}