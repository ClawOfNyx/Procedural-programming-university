#include <stdio.h>
#include <stdbool.h>

int getPositiveNumber(char *msg);

int main() {
    int num;
    char msg[] = "Iveskite viena sveika teigiama skaiciu: ";

    num = getPositiveNumber(msg);

    printf("Ivestas skaicius: %d", num);

    return 0;
}

int getPositiveNumber(char *msg) {
    int num;
    bool invalidInput = true;

    printf("%s", msg);

    while (invalidInput) {
        if ((scanf("%d", &num) == 1) && (num > 0) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\n%s", msg);
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}