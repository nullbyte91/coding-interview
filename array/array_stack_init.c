/* C program to create a array on static/stacks memory */

#include <stdio.h>

#define size 10

int
main(int argc, char* argv[])
{
    /* Array definition */
    int array_1D[size];
    int array_2D[size][size];

    int i, j;
    
    /* Array declaration - 1D*/
    for (i = 0; i < size; i++)
        array_1D[i] = i;
    
    /* Array declaration - 2D*/
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            array_2D[i][j] = i + j;
        }
    }

    /* Print on console - 1D */
    printf("1D Array:\n");
    for ( i = 0; i < size; i++)
        printf("Value %d at Index:[%d]\n", array_1D[i], i);

    printf("\n");
    printf("2D Array:\n");
    /* Print on console - 2D */
    for ( i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            printf("Value %d at Index:[%d][%d]\n", array_2D[i][j], i, j);
        }
        printf("\n");
    }
    return 0;
}