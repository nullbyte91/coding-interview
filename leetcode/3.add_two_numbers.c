/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void insert(struct ListNode** rootPtr, int data){
    struct ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    temp->val = data;
    temp->next = NULL;
    if (*rootPtr == NULL){
        *(rootPtr) = temp;
        return;
    }
    struct ListNode* travel = *(rootPtr);
    while (travel->next != NULL){
        travel = travel->next;   
    }
    travel->next = temp;
}

void show(struct ListNode* rootPtr){
    while(rootPtr != NULL){
        printf("Data: %d", rootPtr->val);
        rootPtr = rootPtr->next;
    }   
    printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l1_rootPtr = l1;
    struct ListNode* l2_rootPtr = l2;
    struct ListNode* rootPtr = NULL;
    int sum, reminder = 0; 
    while (l1_rootPtr != NULL || l2_rootPtr != NULL){
        if (l1_rootPtr!= NULL && l2_rootPtr!= NULL){
     
            sum = l1_rootPtr->val + l2_rootPtr->val;
            
            l1_rootPtr = l1_rootPtr->next;
            l2_rootPtr = l2_rootPtr->next;
        } 
        else if (l1_rootPtr != NULL)
        {
            sum = l1_rootPtr->val;
            l1_rootPtr = l1_rootPtr->next;
        } 
        else 
        {
            sum = l2_rootPtr->val;
            l2_rootPtr = l2_rootPtr->next;
        }
        if (reminder){
            sum += reminder;
            reminder = 0;
        }
        // check the sum greater than 10
        if (sum >= 10){
            reminder = sum / 10;
            sum = sum % 10;
        }
        insert(&rootPtr, sum);
    }
    if (reminder){
        insert(&rootPtr, reminder);
    }
    
//     while(rootPtr != NULL){
//         printf("Data: %d", rootPtr->val);
//         rootPtr = rootPtr->next;
//     }   
//     printf("\n");
    
    //Test function to check the return linked list
    //show(rootPtr);
    return rootPtr;
}

