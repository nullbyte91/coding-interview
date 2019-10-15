#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 
merge(int n1, const int a1[], int n2, const int a2[], int out[]){
	int i1, i2, iout;
	i1 = i2 = iout = 0;
    while(i1 < n1 || i2 < n2) {
        if(i2 >= n2 || ((i1 < n1) && (a1[i1] < a2[i2]))) {
            /* a1[i1] exists and is smaller */
        out[iout++] = a1[i1++];
        } else {
            /* a1[i1] doesn't exist, or is bigger than a2[i2] */
        out[iout++] = a2[i2++];
        }
    }
}

void 
mergeSort(int n, const int in[], int out[]){
	int *a1, *a2;
    // base contition
	if (n < 2){
		memcpy(out, in, sizeof(int)*n);
    } else {
        a1= malloc(sizeof(int)*n/2);
        a2= malloc(sizeof(int)*n-n/2);
        mergeSort(n/2, in, a1);
        mergeSort(n-n/2, in+n/2, a2);	

        merge(n/2, a1, n-n/2, a2, out);

        free(a1);
        free(a2);
    }
}

#define N 10

int
main(int argc, char** argcv){
	int a1[N];
	int a2[N];
	int i;
	for (i = 0; i < N; i++){
		a1[i] = N -i - 1;
    }

    // Test Array before merge
	for (i = 0; i < N; i++){
		printf("%d ", a1[i]);
    }

    putchar('\n');

    mergeSort(N, a1, a2);
    
    // Test Array after merge
	for (i = 0; i < N; i++){
		printf("%d ", a2[i]);
    }
    return 0;
}
