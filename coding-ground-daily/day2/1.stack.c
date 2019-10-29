#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_STACK 0

typedef struct Stack{
    int val;
    struct Stack *next;
}*Stack;

void 
push(Stack *s, int val){
    Stack stack_node = malloc(sizeof(Stack));
    stack_node->val = val;
    stack_node->next = *s;
    *s = stack_node;
}

void
printStack(Stack* s){
    Stack e = *s;
    while (e != NULL){
        printf("%d ", e->val);
        e = e->next;
    }
    putchar('\n');
}

void 
pop(Stack* s){
    Stack e = *s;
    printf("Pop: %d \n", e->val);
    *s = e->next;
    free(e);
}

int
peek(Stack* s){
    Stack e = *s;
    return e->val;
}

bool
isEmpty(Stack* s){

}

int
main(int argc,char** argcv){
    Stack s = EMPTY_STACK;

    for (int i=0; i<5; i++){
        push(&s, i);
    }
    printStack(&s);
    printf("Peek: %d\n", peek(&s));
    for (int i=0; i<5; i++){
        pop(&s);
    }

}