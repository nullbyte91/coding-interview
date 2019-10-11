// Simple Binary Tree 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* getNewNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left, newNode->right = NULL;
}
int main()
{
    struct Node* rootPtr = NULL;
    rootPtr = getNewNode(10);
    rootPtr->left = getNewNode(20);
    rootPtr->right = getNewNode(10);
    rootPtr->left->left = getNewNode(9);
    rootPtr->left->right = getNewNode(30);
    return 0;
}