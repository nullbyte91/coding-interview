#include <stdio.h>
#include <stdlib.h>
#include <stack>

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

void inOrder(struct Node* root){
    std::stack<struct Node*> s;
    struct Node* temp = root;
    while(temp != NULL || !s.empty()){
         while(temp!= NULL){
             s.push(temp);
             temp = temp->left;
         }
         temp = s.top();
         s.pop();
         printf("%d ", temp->data);
         temp = temp->right;       
    }
}

int main()
{
    struct Node* root = getNewNode(1);
    root->left = getNewNode(2);
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right = getNewNode(3);
    inOrder(root);
    return 0;
}