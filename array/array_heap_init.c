/* C program to create a array on dynamic/heap memory */

#include <stdio.h>
#include <stdlib.h>

#define size 2

int i, j;

void array_1D(void){
    /* Array declaration */
    int *array = (int *)malloc(size * sizeof(int));

    /* Array definition */
    for (i = 0; i < size; i++)
        *(array + i) = i;

    /* Display */
    for (i = 0; i < size; i++)
        printf("Value %d at Index[%d]\n", *(array+i), i);
}

void array_2D(void)
{
    /* Array declaration */
    int *array = (int *)malloc(size * size * sizeof(int));
    /* Array definition */
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            *(array + i * size + j) = i + j;
        }
    }

    /* Display */
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            printf("Value %d at Index[%d][%d]\n", *(array + i * size + j), i, j);
        }
    }
}

int
main(int argc, char** argv[])
{    
    array_1D();
    array_2D();

    return 0;
}
