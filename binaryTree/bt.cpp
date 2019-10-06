//Binary Tree insert using level order

#include <stdio.h>
#include <queue>
#include <stdlib.h>

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
    return newNode;
}

int preOrder(struct Node* rootPtr){
    if (rootPtr == NULL){
        return 0;
    } else {
        printf("%d ", rootPtr->data);
        preOrder(rootPtr->left);
        preOrder(rootPtr->right);
    }
}

void insert(struct Node** rootPtr, int data){
    std::queue<struct Node*> q;
    q.push(*rootPtr);

    while(!q.empty()){
        struct Node*  temp = q.front();
        q.pop();
        if(!temp->left){
            temp->left = getNewNode(data);
            break;
        } else {
            q.push(temp->left);
        }
        if(!temp->right){
            temp->right = getNewNode(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
}

void deletDeepest(struct Node* root, 
                  struct Node* d_node) 
{ 
    std::queue<struct Node*> q; 
    q.push(root); 
  
    // Do level order traversal until last node 
    struct Node* temp; 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp == d_node) { 
            temp = NULL; 
            delete (d_node); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == d_node) { 
                temp->right = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == d_node) { 
                temp->left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
} 
Node* deleteNode(Node* root, int data){
    if (root == NULL) 
        return NULL; 
  
    if (root->left == NULL && root->right == NULL) { 
        if (root->data == data) 
            return NULL; 
        else
            return root; 
    } 
  
    std::queue<struct Node*> q; 
    q.push(root); 
  
    struct Node* temp; 
    struct Node* key_node = NULL; 
  
    // Do level order traversal to find deepest 
    // node(temp) and node to be deleted (key_node) 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
  
        if (temp->data == data){
            printf("Found Key\n");
            key_node = temp; 
        }
        if (temp->left) 
            q.push(temp->left); 
  
        if (temp->right) 
            q.push(temp->right); 
    } 
    if (key_node != NULL) { 
        int x = temp->data; 
        deletDeepest(root, temp); 
        key_node->data = x; 
    } 
    return root; 
}
int main()
{
    struct Node* root = getNewNode(10);
    root->left = getNewNode(11); 
    root->left->left = getNewNode(7); 
    root->right = getNewNode(9); 
    root->right->left = getNewNode(15); 
    root->right->right = getNewNode(8);

    // Pre-order Traversal
    preOrder(root);
    printf("\n");
    insert(&root, 20);
    preOrder(root);
    printf("\n");
    deleteNode(root, 20);
    preOrder(root);
    printf("\n");
    return 0;
}