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
    int s, n = -1, num = -1;


    printf("\nIveskite skaiciu s: ");
    s = validation('s');

    while (n < 0) {
        printf("\nIveskite skaiciu n, kuris didesnis arba lygus 0: ");
        n = validation('n');
    }

    int arr[n];

    for (int i = 0; i < n; ++i) {
        while (num <= 0) {
            printf("\nIveskite teigiama skaiciu: ");
            num = validation(' ');
        }
        arr[i] = num;
        num = -1;
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((arr[i] * arr[j]) == s) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

}