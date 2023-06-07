#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double validation(char letter) {
    double num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%lf", &num) == 1) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\nNetinkama ivestis, iveskite realu skaiciu %c: ", letter);
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}

int main() {
    double x, y, z, a, b;

    printf("\nIveskite sveika skaiciu x: ");
    x = validation('x');

    printf("\nIveskite sveika skaiciu y:");
    y = validation('y');

    printf("\nIveskite sveika skaiciu z:");
    z = validation('z');

    a = x + (4 * y) + pow(z, 3);

    b = (x + sqrt(y)) * (pow(z, 4) - fabs(z) + 46.3);

    printf("a) x + 4y + z^3 = %.3lf\n", a);
    printf("b) (x + sqrt(y))(z^4 - |z| + 46.3) = %.3lf", b);

    return 0;
}
