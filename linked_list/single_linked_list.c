#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

struct node{
    int data;
    struct node* next;
};

struct node* getNode(int val)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL){
        printf("Failed to create a memory for Node:%d", errno);
        exit(EXIT_FAILURE);
    }
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void prePand(struct node ** head, int val)
{   
    struct node * temp = getNode(val);

    if (*(head) == NULL){
        *(head) == temp;
    }
    temp->next = *(head);
    *(head) = temp; 
}

void postPand(struct Node ** head, int val)
{
    struct node * temp = getNode(val);

    if (*(head) == NULL){
        *(head) = temp;
    }
    
    struct node * traversal = *(head);
    while (traversal->next != NULL)
        traversal = traversal->next;
    
    traversal->next = temp;
}

void appendAtIndex(struct node ** head, int val, int position)
{
    struct node * temp = getNode(val);

    if (*(head) == NULL){
        *(head) = temp;
    }
    struct node * next = *head;
    for (int i = 1; i < position - 1; i++){ 
        next = next->next;
    }
    temp->next = next->next;
    next->next = temp;
}

void access(struct node * head)
{
    while (head != NULL){
        printf("%d ", (head->data));
        head = head->next;
    }
    printf("\n");
}

void pop(struct node ** head)
{
    struct node * temp = *(head);
    if ((temp) == NULL){
        printf("List is empty\n");
    } else if (temp->next == NULL){
        free(head);
    } else {
        struct node *prev = *(head);
        while (temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void popFirst(struct node ** head)
{
    struct node * temp = *(head);
    if ((temp) == NULL){
        printf("List is empty\n");
    } else {
        *(head) = temp->next;
        free(temp);
    }
}

void popAtIndex(struct node ** head, int position)
{
    struct node * temp = *(head);
    if ((temp) == NULL){
        printf("List is empty\n");
    } else {
        struct node * prev = *(head);
        for (int i = 1; i < position; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

int
main(int argc, char** argv[]){
    struct node * head = NULL;
    /* Add element at beg */
    prePand(&head, 4);
    prePand(&head, 3);
    prePand(&head, 2);
    prePand(&head, 1);
    access(head);

    /* Add element at End */
    postPand(&head, 7);
    postPand(&head, 8);
    access(head);

    /* Add element at Nth Index */
    appendAtIndex(&head, 5, 5);
    appendAtIndex(&head, 6, 6);
    access(head);

    /* Delete note at the End */
    pop(&head);
    pop(&head);
    access(head);

    /* Delete node at the beg */
    popFirst(&head);
    access(head);
    popFirst(&head);
    access(head);

    /* Delete node at Nth Index */
    popAtIndex(&head, 2);
    access(head);
    return 0;
}