#include <stdio.h>
#include <stdbool.h>

long long int validation(char letter) {
    long long int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%lld", &num) == 1) && (num >= 0) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\nNetinkama ivestis, iveskite sveika neneigiama skaiciu %c: ", letter);
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}

int main() {
    long long int a, b, c;

    printf("Iveskite skaiciu a:\n");
    a = validation('a');

    printf("Iveskite skaiciu b:\n");
    b = validation('b');

    printf("Iveskite skaiciu c:\n");
    c = validation('c');

    long long int fib[c + 1];
    fib[0] = a;
    fib[1] = b;

    for(int i = 2; i <= c; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("%lld-asis fibonacci sekos skaicius, kai 0 ir 1 skaiciai %lld, %lld, yra %lld", c, a, b, fib[c]);

    return 0;
}
