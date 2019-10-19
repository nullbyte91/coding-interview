#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

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
pre_order(struct node* rootPtr){
    if (rootPtr == NULL){
        return;
    }
    printf("Data:%d ", rootPtr->data);
    pre_order(rootPtr->left);
    pre_order(rootPtr->right);
}

void
in_order(struct node* rootPtr){
    if (rootPtr == NULL){
        return;
    }
    pre_order(rootPtr->left);
    printf("Data:%d ", rootPtr->data);
    pre_order(rootPtr->right);
}

void
post_order(struct node* rootPtr){
    if (rootPtr == NULL){
        return;
    }
    pre_order(rootPtr->left);
    pre_order(rootPtr->right);
    printf("Data:%d ", rootPtr->data);

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
    // 1. DFS ()
    // a. pre-order  - <root><left><right>
    // b. in-order   - <left><root><right>
    // c. post-order - <left><right><root>
    pre_order(rootPtr);
    putchar('\n');
    in_order(rootPtr);
    putchar('\n');
    post_order(rootPtr);
    return 0;
}
