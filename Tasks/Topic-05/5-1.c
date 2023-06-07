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
    //----a----
    int a[10] = {0};
    int length = 10;

    //----b----
    printf("Array: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", a[i]);
    }

    printf("\n");

    //----c----
    a[0] = 1;
    a[3] = 2;
    a[9] = 3;

    //----d----
    for (int i = 2; i < length - 1; ++i) {
        a[i] = a[i + 1];
    }

    --length;

    //----e----
    for (int i = length; i > 7; --i) {
        a[i] = a[i - 1];
    }

    a[6] = 4;
    ++length;

    //----f----
    printf("Edited array: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", a[i]);
    }

    printf("\n");

    //----g----
    int x = 0, y = 0;

    printf("\nIveskite skaiciu x:");
    x = validation('x');

    printf("\nIveskite skaiciu y:");
    y = validation('y');

    a[x] = y;

    //----h----
    printf("\nIveskite skaiciu x:");
    x = validation('x');

    for (int i = x; i < length - 1; ++i) {
        a[i] = a[i + 1];
    }

    --length;

    //----į----
    printf("\nIveskite skaiciu x:");
    x = validation('x');

    printf("\nIveskite skaiciu y:");
    y = validation('y');

    for (int i = length; i > x + 1; --i) {
        a[i] = a[i - 1];
    }

    a[x] = y;
    ++length;

    //----j----
    printf("Newly edited array: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", a[i]);
    }

    printf("\n");
}