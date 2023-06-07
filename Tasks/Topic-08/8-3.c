#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int a = 5, b = 9;

    printf("\nSwapped from a=%d, b=%d to:\n", a, b);
    swap(&a, &b);
    printf("a=%d, b=%d", a, b);

    return 0;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}