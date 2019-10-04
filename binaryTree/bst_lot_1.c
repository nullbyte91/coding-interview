// Recursive C program for level order traversal of Binary Tree 
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
}

void printLevelOrder(struct Node* rootPtr){
    int h = findHeight(rootPtr);
    for(int i=1; i<=h; i++){
        subprintLevelOrder(rootPtr, i);
    }
}

void subprintLevelOrder(struct Node* rootPtr, int level){
    if (rootPtr == NULL){
        return 0;
    }
    if (level == 1){
        printf("Data:%d \n", rootPtr->data);
    } else {
        subprintLevelOrder(rootPtr->left, level-1);
        subprintLevelOrder(rootPtr->right, level-1);
    }
}

int findHeight(struct Node* rootPtr){
    // Base case
    if (rootPtr == NULL){
        return 0;
    } else {
        int hleft = findHeight(rootPtr->left);
        int hright = findHeight(rootPtr->right);

        if(hleft > hright){
            return hleft+1;
        } else {
            return hright+1;
        }
    }
}

int main(){
    struct Node* rootPtr = NULL;
    rootPtr = insert(rootPtr, 5);
    rootPtr = insert(rootPtr, 4);
    rootPtr = insert(rootPtr, 6);
    rootPtr = insert(rootPtr, 3);
    rootPtr = insert(rootPtr, 7);
    printLevelOrder(rootPtr);
    return 0;    
}