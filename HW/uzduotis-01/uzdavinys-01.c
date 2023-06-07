/**
 * uzdavinys 01
 *
 * Brigita Bruskyte
 * 2022 Rugsejis
 *
 * Procedurinis programavimas
 *
 * Aprasymas:
 * Įvesti sveiką skaičių G. Įvesti sveikų skaičių seką, kurios pabaiga žymima skaičiumi G.
 * Išvesti visų įvestų narių skaičių, teigiamų narių skaičių ir neigiamų narių sumą bei
 * sandaugą (arba atitinkamą pranešimą, jeigu tokių nėra).
 * */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char validation[4];

    do {
        int g, num, positivesCount = 0, negativesSum = 0, negativesProduct = 1, count = 0;
        bool invalidInput = true;

        printf("\n\nIveskite sveika skaiciu G, kuriuo uzbaigsite programa: ");

        while (invalidInput) {
            if ((scanf("%d", &g) == 1) && (getchar() == '\n')) {
                invalidInput = false;
            } else {
                printf("\nNetinkama ivestis, iveskite sveika skaiciu G: ");
                while (getchar() != '\n')
                    ;

                invalidInput = true;
            }
        }

        if (g < 0) {
            negativesSum += g;
            negativesProduct *= g;
        } else if (g > 0) {
            positivesCount++;
        }
        count++;


        do {
            invalidInput = true;
            printf("\n\nIveskite sveika skaiciu: ");

            while (invalidInput) {
                if ((scanf("%d", &num) == 1) && (getchar() == '\n')) {

                    invalidInput = false;
                } else {
                    printf("\nNetinkama ivestis, iveskite sveika skaiciu");
                    while (getchar() != '\n');
                    invalidInput = true;
                }
            }

            if (num < 0) {
                negativesSum += num;
                negativesProduct *= num;
            } else if (num > 0) {
                positivesCount++;
            }
            count++;
        } while (num != g);

        printf("\n\nIvestu nariu skaicius: %d", count);
        printf("\nIvestu teigiamu nariu skaicius: %d", positivesCount);

        if (negativesSum != 0) {
            printf("\nIvestu neigiamu nariu suma yra %d, o sandauga: %d\n", negativesSum, negativesProduct);
        } else {
            printf("\nNeigiamu skaiciu ivesta nebuvo\n");
        }

        printf("\nNoredami testi iveskite 'taip', priesingu atveju iveskite bet ka: ");

        scanf(("%s", validation) != 1 && getchar() != '\n');
    } while (stricmp(validation, "Taip") == 0);

    return 0;
}

