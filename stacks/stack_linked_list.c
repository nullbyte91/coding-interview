#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

struct elt{
    int data;
    struct elt * next;
};

struct elt* getElt(int val){
    struct elt * temp = (struct elt*)malloc(sizeof(struct elt));
    temp->data = val;
    temp->next = NULL; 
}

void push(struct elt ** peek, int val)
{
    struct elt * temp = getElt(val);
    temp->next = *(peek);   
    *(peek) = temp;
}

void pop(struct elt ** peek)
{
    struct elt * temp = *(peek);
    printf("Poping up value:%d\n", temp->data);
    *(peek) = temp->next;
    free(temp);
}

void print(struct elt * peek)
{
    while (peek != NULL){
        printf("Data:%d\n", peek->data);
        peek = peek->next;
    }
}

int
main(int argc, char** argv[])
{
    struct elt * peek = NULL;
    int i;
    for (i = 0; i < 5; i++){
        push(&peek, i);
    }
    print(peek);

    while (peek != NULL){
        pop(&peek);
        print(peek);
    }
    return 0;
}