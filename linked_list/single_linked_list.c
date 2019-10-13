//1. Insert at the end
//2. Insert at the beg
//3. Insert n the position 
//4. Delete at the end
//5. Delete at the beg
//6. Delete n the position
//7. Reverse the order
//8. Reverse the linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_end(struct Node **head, int data){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL){
        (*head) = temp;
        return;
    }
    struct Node* travel = *head;
    while(travel->next !=NULL){
        travel = travel->next;
    }
    travel->next = temp;
}

void insert_beg(struct Node **head, int data){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL){
        (*head) = temp;
        return;
    }
    struct Node* temp1 = *head;
    temp->next = temp1;
    (*head) = temp;
}

void insert_nth(struct Node **head, int data, int position){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL){
        (*head) = temp;
        return;
    }
    struct Node* temp1 = *head;
    for(int i=0; i<position -2;i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void printList(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printReverse(struct Node* head){
    //base case
    if(head == NULL){
        return;
    } else{
        printReverse(head->next);
        printf("%d ", head->data);
    }
}

void reverseLinkedList(struct Node* head)
{
    //base case
    if(head == NULL){
        head->next = NULL;
        return;
    } else{
        printReverse(head->next);
        struct Node* temp = head->next;
        temp->next = head;
        head->next = NULL;
    }

}

int main()
{ 
    struct Node *head = NULL;
    insert_beg(&head, 7);
    insert_end(&head, 17);
    insert_end(&head, 27);
    insert_end(&head, 37);
    insert_beg(&head, 47);
    insert_nth(&head, 200, 3);
    printList(head);
    printReverse(head);
    reverseLinkedList(head);
    return 0;
}