// Recursive C program for Depth order traversal of Binary Tree 
#include <stdio.h> 
#include <stdlib.h> 
  
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* getNewNode(struct Node* rootPtr, int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* rootPtr, int data){
    if (rootPtr == NULL){
        rootPtr = getNewNode(rootPtr, data);
    } else if(data <= rootPtr->data){
        rootPtr->left = insert(rootPtr->left, data);
    } else if(data >= rootPtr->data){
        rootPtr->right = insert(rootPtr->right, data);
    }
    return rootPtr;

void preOrder(struct Node* rootPtr){
    if (rootPtr == NULL){
        return 0;
    }
    printf("Data:%d ", rootPtr->data);
    preOrder(rootPtr->left);
    preOrder(rootPtr->right);
}

void inOrder(struct Node* rootPtr){
    if (rootPtr == NULL){
        return 0;
    }
    inOrder(rootPtr->left);
    printf("Data:%d ", rootPtr->data);
    inOrder(rootPtr->right);
}

void postOrder(struct Node* rootPtr){
    if (rootPtr == NULL){
        return 0;
    }
    postOrder(rootPtr->left);
    postOrder(rootPtr->right);
    printf("Data:%d ", rootPtr->data);
}


int main(){
    struct Node* rootPtr = NULL;
    rootPtr = insert(rootPtr, 5);
    rootPtr = insert(rootPtr, 4);
    rootPtr = insert(rootPtr, 6);
    rootPtr = insert(rootPtr, 3);
    rootPtr = insert(rootPtr, 7);
    preOrder(rootPtr);
    printf("\n");
    inOrder(rootPtr);
    printf("\n");
    postOrder(rootPtr);
    printf("\n");
    return 0;    
}