#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define EMPTY_STACK (0)

struct elt
{
    struct elt *next;
    int value;
};

typedef struct elt *Stack;

void 
stackPush(Stack *s, int val){
    Stack e;
    e = malloc(sizeof(Stack));
    assert(e);
    e->value = val;
    e->next = *s;
    *s = e;    
}

void
stackPrint(const Stack *s){
    Stack e;
    while(e != 0){
        printf("val: %d ", e->value);
        e = e->next;
    }
    printf("\n");
}

int
stackPop(Stack *s){
    Stack e;
    int ret;
    e = *s;
    ret = e->value;
    *s = e->next;
    free(e);
    return ret;
}

int 
stackEmpty(const Stack *s){
    return(*s == 0);
}

int 
main(int argc, char** argcv){
    Stack s;
    s = EMPTY_STACK;
    int i;
    
    for(i=0; i<5; i++){
        stackPush(&s, i);
        stackPrint(&s);
    }

    while(!stackEmpty(&s)){
        printf("Pop:%d ", stackPop(&s));
        //stackPrint(&s);
    }
    putchar('\n');
    return 0;
}