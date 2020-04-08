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
getNewNode(int val)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *
insertNode(struct node * rootPtr, int val)
{
    if (rootPtr == NULL){
        rootPtr = getNewNode(val);
    } else if (val >= rootPtr->data){
        rootPtr->left = insertNode(rootPtr->left, val);
    } else {
        rootPtr->right = insertNode(rootPtr->right, val);
    }
    return rootPtr;
}

int traversal(struct node * root_Ptr){
    /* Base condition */
    if (root_Ptr == NULL){
        return 0;
    } else {
        printf("Data:%d\n", root_Ptr->data);
        traversal(root_Ptr->left);
        traversal(root_Ptr->right);
    }
}

int
main(int argc, char** argv[])
{
    struct node * rootPtr = NULL;
    rootPtr = insertNode(rootPtr, 6);
    rootPtr = insertNode(rootPtr, 4);
    rootPtr = insertNode(rootPtr, 7);

    /* Tree traversal using dfs pre-order */
    traversal(rootPtr);
    return 0;
}