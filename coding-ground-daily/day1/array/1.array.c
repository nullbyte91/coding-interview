/* static array implementation with below operation 
    1. Insert   - O(n)
    2. Delete   - O(n)
    3. Search   - O(n)
    4. Access   - O(1)
*/

#include <stdio.h>
#define MAX_SIZE 100

void insert(int a[], int num){
    int i=0;
    while(a[i] != 0){
        i++;
        printf("%d", a[i]);
    }
    a[i] = num;
}

void access(int a[]){
    int i =0;
    while(a[i] != 0){
        printf("%d ", a[i++]);
    }
    printf("\n");
}

void delete(int a[], int num){
    int pos = search(a, num);
    if (pos == -1){
        printf("Not found\n");
        return;
    }
    else {
        for (int i = pos; a[i] != 0; i++){
            a[i] = a[i+1];
        }
    }
    return;
}

int search(int a[], int num){
    int i =0;
    while(a[i] != 0){
        if(num == a[i]){
            return i;
        } else {
            i++;
        }
    }
    return -1;
}

int main()
{
    int a[MAX_SIZE] = {0}; 
    int option, num, pos;
    while(1){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Access\n");
        printf("5. Exit\n");

        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter the number to insert\n");
                scanf("%d", &num);
                insert(a, num);
                break;
            case 2:
                printf("Enter the num to delete\n");
                scanf("%d", &num);
                delete(a, num);
                break;
            case 3:
                printf("Enter the num to search\n");
                scanf("%d", &num);
                pos = search(a, num);
                printf("Search Element %d pos %d \n", num, pos);
                break;
            case 4:
                access(a);
                break;
            case 5:
                return 0;
            default:
                printf("I couldn't understand\n");
                return 0;
        }
    }
    return 0;
}
