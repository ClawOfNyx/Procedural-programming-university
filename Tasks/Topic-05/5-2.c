#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int validation(char letter) {
    int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%d", &num) == 1) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\nNetinkama ivestis, iveskite sveika skaiciu %c: ", letter);
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}

int main() {
    int arr[1000];
    int a, b, c;

    printf("\nIveskite skaiciu a: ");
    a = validation('a');

    b = a - 1;
    while (b < a) {
        printf("\nIveskite skaiciu b, kuris didesnis uz skaiciu a: ");
        b = validation('b');
    }

    c = 1001;
    while(c >= 1000) {
        printf("\nIveskite skaiciu c, kuris yra nedidesnes uz 1000: ");
        c = validation('c');
    }

    for (int i = 0; i < c; ++i) {
        arr[i] = (rand() % (b - a + 1)) + a;
    }

    printf("\nSugeneruotas array: [");
    
    for (int i = 0; i < c; ++i) {
        if (i != c - 1) {
            printf("%d, ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }

    printf("]");

}