#include <stdio.h>
#include <stdbool.h>
#include <math.h>

long long int validation() {
    long long int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%lld", &num) == 1) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\nNetinkama ivestis, iveskite teigiama skaiciu: ");
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}

int main() {
    long long int num;
    long long int maxLen;
    bool pos = true;

    printf("Iveskite skaiciu:\n");
    num = validation();
    maxLen = num;

    while (pos) {
        printf("Iveskite skaiciu:\n");
        num = validation();

        if (fabs(num) > fabs(maxLen)) {
            maxLen = num;
        }
        if(num <= 0) {
            pos = false;
        }
    }

    printf("Daugiausiai skaitmenu turi %lld:\n", maxLen);

    return 0;
}
