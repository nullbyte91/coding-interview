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

int search(struct Node* rootPtr, int searchData){
    //Base Case
    if (rootPtr == NULL){
        return 0;
    } else if (rootPtr->data == searchData){
        return 1;
    } else if(searchData <= rootPtr->data){
        return search(rootPtr->left, searchData);
    } else if(searchData >= rootPtr->data){
        return search(rootPtr->right, searchData);
    }
}

int findAheight(struct Node* rootPtr){
    if(rootPtr == NULL){
        return -1;
    } 
    while(rootPtr->left !=NULL){
        printf("%d ", rootPtr->data);
        rootPtr->left = rootPtr->left;
    }
}
struct Node* findMin(struct Node* rootPtr){
    if (rootPtr == NULL){
        return;
    }
    while(rootPtr->left != NULL){
        rootPtr = rootPtr->left;
    }
    printf("Min: %d ", rootPtr->data);
}

struct Node* findMax(struct Node* rootPtr){
    if (rootPtr == NULL){
        return 0;
    }
    while(rootPtr->right != NULL){
        rootPtr = rootPtr->right;
    }
    printf("Max: %d ", rootPtr->data);
}

int findHeight(struct Node* rootPtr){
   if (rootPtr==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = findHeight(rootPtr->left); 
       int rDepth = findHeight(rootPtr->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}

int main(){
    struct Node* rootPtr = NULL;
    rootPtr = insert(rootPtr, 20);
    rootPtr = insert(rootPtr, 25);
    rootPtr = insert(rootPtr, 15);
    rootPtr = insert(rootPtr, 30);
    rootPtr = insert(rootPtr, 10);
    rootPtr = insert(rootPtr, 5);
    rootPtr = insert(rootPtr, 8);
    if(search(rootPtr, 10)){
        printf("Found the key\n");
    } else {
        printf("Key not found\n");
    }
    findMin(rootPtr);
    findMax(rootPtr);
    int height = findHeight(rootPtr);
    printf("Height:%d", height);
    return 0;    
}