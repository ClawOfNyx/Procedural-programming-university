#include <stdio.h>
#include <stdbool.h>

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
    int x, y, z;

    printf("\nIveskite sveika skaiciu x: ");
    x = validation('x');

    printf("\nIveskite sveika skaiciu y:");
    y = validation('y');

    printf("\nIveskite sveika skaiciu z:");
    z = validation('z');

    printf("Is skaiciu %d, %d, %d; maksimali reiksme yra %d, minimali yra %d ", x, y, z,
           ((x > y) ? ((x > z) ? x : z) : (y > z) ? y : z), (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z));
    return 0;
}
