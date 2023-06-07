#include <stdio.h>
#include <stdbool.h>
#include <math.h>

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
    double d, x1, x2;

    printf("Iveskite skaiciu a:\n");
    a = validation('a');
    printf("Iveskite skaiciu b:\n");
    b = validation('b');
    printf("Iveskite skaiciu c:\n");
    c = validation('c');

    d = pow(b, 2) - (4 * a * c);

    if(d == 0) {
        printf("Lygtis turi viena sprendini.\n");
        x1 = - (b / (2 * a));
        printf("x = %lf\n", x1);
    } else
        if (d > 0) {
            printf("Lygtis turi du sprendinius.\n");
            x1 = (-b + sqrt(d))/ (2 * a);
            x2 = (-b - sqrt(d))/ (2 * a);
            printf("x1 = %lf; x2 = %lf\n", x1, x2);
        } else {
            printf("Lygtis neturi sprendiniu.\n");
        }

    return 0;
}
