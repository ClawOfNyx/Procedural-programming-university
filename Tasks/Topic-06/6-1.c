/**
 * Parašykite programą, kuri paprašo įvesti vieną teigiamą skaičių,
 * ir suskaičiuoja jo faktorialą, kurį atspausinda ekrane ir taip pat
 * įrašo į rezultatų failą „out.txt“.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int validation();

long long int factorial(int num);

void output(long long int f, int num);

int main() {
    int x;
    long long int fact;
    char restart[4];


    printf("\nPrograma apskaiciuos ivesto sveiko teigiamo skaiciaus faktoriala bei ji atspauzdina ekrane ir 'out.txt' faile.");

    do {
        strcpy(restart, "n");
        printf("\nIveskite viena sveika teigiama skaiciu: ");
        x = validation();

        fact = factorial(x);

        if (x > 20) {
            printf("\nError! Jusu ivesto skaiciaus faktorialas yra perdidelis.\nNoredami bandyti su mazesniu skaiciu iveskite 'taip': ");
            scanf("%s", restart);
        } else {
            output(fact, x);
        }
    } while (stricmp(restart, "Taip") == 0);

    return 0;
}

void output(long long int f, int num) {
    FILE *outFile = fopen ("out.txt", "w");
    printf("\n%d! = %lld", num, f);
    fprintf(outFile, "%d! = %lld\n", num, f);

    fclose (outFile);
}

long long int factorial(int num) {
    if (num > 1) {
        return (num * factorial(num - 1));
    }
    else 
        if (num == 1) {
            return 1;
    }
}

int validation() {
    int num;
    bool invalidInput = true;

    while (invalidInput) {
        if ((scanf("%d", &num) == 1) && (num > 0) && (getchar() == '\n')) {
            printf("\nSekminga ivestas skaicius %d", num);
            invalidInput = false;
        }
        else {
            printf("\nNetinkama ivestis, iveskite sveika teigiama skaiciu: ");
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return num;
}