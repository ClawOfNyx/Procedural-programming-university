#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createArray(int **arr, int n, int low, int high);

int main() {
    srand(time(0));
    
    int *arr;
    int n = 5, low = 0, high = 10;
    
    createArray(&arr, n, low, high);

    printf("\nCreated array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}


void createArray(int **arr, int n, int low, int high) {
    *arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        (*arr)[i] = (rand() % (high - low + 1)) + low;
    }
}