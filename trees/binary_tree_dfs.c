#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node *
getNode(int val)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *
insertNode(struct node * rootPtr, int data)
{
    if (rootPtr == NULL)
        rootPtr = getNode(data);
    else if (data <= rootPtr->data)
        rootPtr->left = insertNode(rootPtr->left, data);
    else 
        rootPtr->right = insertNode(rootPtr->right, data);

    return rootPtr;    
}

/* root, left, right */
int
preorder(struct node * rootPtr){
    /* Base condition */
    if (rootPtr == NULL){
        return 0;
    } else {
        printf("Data:%d\n", rootPtr->data);
        preorder(rootPtr->left);
        preorder(rootPtr->right);
    }
}

/* left, root, right */
int
inorder(struct node * rootPtr){
    /* Base condition */
    if (rootPtr == NULL){
        return 0;
    } else {
        preorder(rootPtr->left);
        printf("Data:%d\n", rootPtr->data);
        preorder(rootPtr->right);
    }
}

/* left, right, root */
int
postorder(struct node * rootPtr){
    /* Base condition */
    if (rootPtr == NULL){
        return 0;
    } else {
        preorder(rootPtr->left);
        preorder(rootPtr->right);
        printf("Data:%d\n", rootPtr->data);
    }
}

int
main(int argc, char ** argv[])
{
    struct node * rootPtr = NULL;
    rootPtr = insertNode(rootPtr, 6);
    rootPtr = insertNode(rootPtr, 3);
    rootPtr = insertNode(rootPtr, 4);
    rootPtr = insertNode(rootPtr, 8);
    rootPtr = insertNode(rootPtr, 9);

    /* Pre-Order */
    printf("Processing preorder\n");
    preorder(rootPtr);

    /* In-oder */
    printf("Processing inorder\n");
    inorder(rootPtr);

    /* Post order */
    printf("Processing postorder\n");
    postorder(rootPtr);

    return 0;
}