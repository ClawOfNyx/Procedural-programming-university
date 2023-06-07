#include <stdio.h>
#include <stdbool.h>

int validation();
long long int getFactorial(int num);
long long int factorial(int num);

int main() {
    int num;

    printf("Iveskite skaiciu faktorialui apskaiciuoti: ");
    num = validation();

    if ((factorial(num) == 0) || num > 20) {
        printf("skaiciaus %d faktorialo negalima apskaiciupti arba jis per didelis", num);
    } else {
        printf("%d! = %lld", num, getFactorial(num));
    }

    return 0;
}

long long int factorial(int num) {
    if (num > 0) {
        long long int fact = 1;
        for (int i = 2; i <= num; ++i) {
            fact *= i;
        }

        return fact;
    } else {
        return 0;
    }
}

long long int getFactorial(int num) {
    if (num <= 0) {
        return 0;
    } else
        if (num > 1) {
            return (num * factorial(num - 1));
    } else 
        if (num == 1) {
            return 1;
    }
}

int validation() {
    int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%d", &num) == 1) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\nNetinkama ivestis, iveskite sveika skaiciu:");
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}