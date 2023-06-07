#include <stdio.h>
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
    double n;

    printf("Iveskite skaiciu n:\n");
    n = validation('n');

    double min, max, sum = 0;
    double avg;
    double num;

    printf("Iveskite skaiciu:\n");
    num = validation(' ');
    sum += num;
    max = num;
    min = num;

    for (int i = 1; i < n; ++i) {
        printf("Iveskite skaiciu:\n");
        num = validation(' ');

        sum += num;

        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }

    avg = sum / n;

    printf("Suma: %lf\nVidurkis: %lf\nMaziausia reiksme: %lf\nDidziausia reiskme: %lf\n", sum, avg, min, max);


    return 0;
}
