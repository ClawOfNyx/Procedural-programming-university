#include <stdio.h>
#include <stdbool.h>

int validation(char letter);
int isInRange(int number, int low, int high);


int main() {
    int num, low, high;

    printf("Iveskite norima skaiciu N: ");
    num = validation('N');

    printf("Iveskite skaiciu L zyminti norimo intervalo pradzia: ");
    low = validation('L');

    printf("Iveskite skaiciu H zyminti norimo intervalo pabaiga: ");
    high = validation('H');

    if (isInRange(num, low, high)) {
        printf("\nSkaicius %d priklauso intervalui [%d; %d].", num, low, high);
    } else {
        if (low > high) {
            printf("\nIntervalas [%d; %d] nera legalus.", low, high);
        } else {
            printf("\nSkaicius %d nepriklauso intervalui [%d; %d].", num, low, high);
        }
    }

    return 0;
}

int isInRange(int number, int low, int high) {
    if (low > high) {
        return 0;
    } else 
        if ((number <= high) && (number >= low)) {
            return 1;
    }
}

int validation(char letter) {
    int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%d", &num) == 1) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\nNetinkama ivestis, iveskite sveika skaiciu %c:", letter);
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}