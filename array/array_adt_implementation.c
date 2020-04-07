/* C program for array ADT implementation */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

int *array;
int arr_size;
int index;

bool isFull()
{
    if ((index + 1) == arr_size)
        return true;
    return false;
}

bool isEmpty()
{
    if ((index + 1) == 1)
        return true;
    return false;
}

void createArray(void)
{
    printf("Enter the array size:\n");
    scanf("%d", &arr_size);
    array = (int *)malloc(arr_size * sizeof(int));
    if (array == NULL){
        printf("Failed to init - %d", errno);
        free(array);
        exit(EXIT_FAILURE);
    }

}

void getValueAt(void)
{
    int position;
    printf("Enter the position\n");
    scanf("%d", &position);

    if (isEmpty() == true)
        printf("Array is Empty\n");
    else
        printf("Value %d at Index[%d]", *(array + position), position);
}

void insert(void)
{
    if (isFull() == true){
        printf("Array is full\n");
    } else {
        int num;
        printf("Enter the num to insert\n");
        scanf("%d", &num);
        *(array + index) = num;
        index++; 
    }
}

void delete()
{
    if (isEmpty() == true){
        printf("Array is Empty");
    } else {
        *(array + index) = -1;
        index--;
    }
}

void size()
{
    printf("size of the array", sizeof(array));
}

void display()
{
    int i;

    for (i = 0; i <= index; i++)
        printf("Value %d at Index[%d]", *(array+i), i);
}


int
main(int argc, char* argv[]){
    int option = 0;
    while (1){
        printf("Array ADT:\n");
        printf("Select an options\n");
        printf("1. Create\n");
        printf("2. Position At\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Size\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        scanf("%d", &option);
        
        switch (option){
            case 1:
                createArray();
                break;
            case 2:
                getValueAt();
                break;
            case 3:
                insert();
                break;
            case 4:
                delete();
                break;
            case 5:
                size();
                break;
            case 6:
                display();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid Option\n");
                break;
        }

    }
    return 0;
}