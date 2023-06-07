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
    int a, b, c;

    printf("Iveskite skaiciu a:\n");
    a = validation('a');

    b = a - 1;
    while (b < a) {
        printf("Iveskite skaiciu b, kuris didesnis uz skaiciu a:\n");
        b = validation('b');
    }

    printf("Iveskite skaiciu c:\n");
    c = validation('c');

    for (int i = a + 1; i <= b; ++i) {
        if (i > 0 && (i % c == 1)) {
            printf("%d; ", i);
        }
    }

    return 0;
}
