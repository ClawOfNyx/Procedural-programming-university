#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int validation();
void generateArray(int data[], int size, int low, int high);

int main() {
    srand (time(NULL));

    int size = -1, low, high;

    printf("Iveskite norimo masyvo elementu kieki: ");
    while (size <= 0) {
        size = validation("teigiama sveika skaiciu");
    }

    printf("Iveskite norimo intervalo pradzia: ");
    low = validation("sveika skaiciu");
    high = low - 1;
    
    printf("Iveskite norimo intervalo pabaiga: ");
    while (high < low) {
        high = validation("sveika skaiciu, kuris yra didesnis arba lygus intervalo pradziai");
    }

    int arr[size];

    generateArray(arr, (size + 1), low, high);

    printf("{");
    for (int i = 0; i < size; ++i) {
        if (i == (size - 1)) {
            printf("%d", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
    printf("}");

    return 0;
}

void generateArray(int data[], int size, int low, int high) {
    for(int i = 0; i < size; ++i) {
        data[i] = (rand() % (high - low + 1)) + low;
    }
}

int validation(char *n) {
    int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%d", &num) == 1) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\nNetinkama ivestis, iveskite %s:", n);
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}