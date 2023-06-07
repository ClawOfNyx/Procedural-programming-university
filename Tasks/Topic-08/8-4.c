#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void splitData(int *arr, int n, int partSize, int **ptr1, int **ptr2);

int main() {
    srand(time(0));

    int *arr, *ptr1, *ptr2;
    int n = 7, partS = 2;

    arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        arr[i] = (rand() % (9 - 0 + 1)) + 0;
    }

    if (arr != NULL) {
        printf("\nInitial array:\n");
        for (int i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }

        if (partS >= 0) {
            splitData(arr, n, partS, &ptr1, &ptr2);

            printf("\nFirst array:\n");
            for (int i = 0; i < partS; ++i) {
                printf("%d ", ptr1[i]);
            }

            printf("\nSecond array:\n");
            for (int i = 0; i < (n - partS); ++i) {
                printf("%d ", ptr2[i]);
            }
        }
        else {
        printf("\nBad parametres for partition size!\n");
    }
    } else {
        printf("\nBad parametres for initial array!\n");
    }

    free(arr);
    free(ptr1);
    free(ptr2);
    return 0;
}

void splitData(int *arr, int n, int partSize, int **ptr1, int **ptr2) {
    *ptr1 = (int*) malloc(partSize * sizeof(int));
    *ptr2 = (int*) malloc((n - partSize) * sizeof(int));
    int j = 0, k = 0;
    
    for (int i = 0; i < n; ++i) {
        if (i < partSize) {
            (*ptr1)[j] = arr[i];
            ++j;
        } else {
            (*ptr2)[k] = arr[i]; 
            ++k;
        }
    }
}