#include <stdio.h>
#include <stdbool.h>

long long int validation(char letter) {
    long long int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%lld", &num) == 1) && (num > 0) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\nNetinkama ivestis, iveskite naturalu skaiciu %c: ", letter);
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}

int main() {
    long long int a, b, c, gcd, lcm, max;

    printf("Iveskite skaiciu a:\n");
    a = validation('a');

    printf("Iveskite skaiciu b:\n");
    b = validation('b');

    printf("Iveskite skaiciu c:\n");
    c = validation('c');

    for (int i = 1; i <= a && i <= b && i <= c; ++i) {
        if ((a % i == 0) && (b % i == 0) && (c % i == 0)) {
            gcd = i;
        }
    }

    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else
        if (b > c) {
            max = b;
        } else {
            max = c;
        }

    for (int j = max; j <= (a * b * c); ++j) {
        if ((j % a == 0) && (j % b == 0) && (j % c == 0)) {
            lcm = j;
            break;
        }
    }

    printf("Didziausias bendras daliklis: %lld\n", gcd);
    printf("Maziausias bendras kartotinis: %lld\n", lcm);

    return 0;
}
