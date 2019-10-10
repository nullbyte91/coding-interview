#include <stdio.h>
#include <stdlib.h>
#include <queue>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* getNewNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

void preOrder(struct Node* root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node* root){
    if (root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node* root){
    if (root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// Depth Wise travel
int depthWise(struct Node* root){
    if (root == NULL){
        return -1;
    }
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
}

// Level Order
void levelOrder(struct Node* root){
    if (root == NULL){
        return;
    }
    std::queue<struct Node*>  q;
    q.push(root);
    while(!q.empty()){
        struct Node* temp = q.front();
        q.pop();
        
        printf("%d ", temp->data);
        if (temp->left){
            q.push(temp->left);   
        }
        if (temp->right){
            q.push(temp->right);
        }
    }
}

int main(){
    struct Node* root = getNewNode(1);
    root->left = getNewNode(2);
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right = getNewNode(3);
    depthWise(root);
    levelOrder(root);
    return 0;
}