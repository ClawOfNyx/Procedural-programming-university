/**
 * Parašykite programą, kuri paprašo duomenų faile „in.txt“ pateikti realų skaičių, ne mažesnį už 10 ir nedidesnį už 1000, 
 * su ne daugiau kaip 3 skaičiais po kablelio. Laikykite, kad įvestyje trupmeninę dalį nuo sveikosios skiria kablelis.
 * Programa turi atspausdinti įvesto skaičiaus ilgį. Jei duomenys pateikti nekorektiškai, programa turi prašyti įvesti
 * (tikėtina, kito) duomenų failo vardą, su galimai jau korektiškais duomenimis.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char file[256];
    char filename[252];
    FILE *inFile = NULL;

    char c;
    char wholeNum[4];
    int countWhole = 0, countDecimal = 0, countChars = 0;
    double dec = 0, num = 0;
    bool decimal = false, invalidInput = false, restart = true;

    printf("\nPrograma apskaiciuos '.txt' faile ivesto realaus skaiciaus ilgi.");
    
    printf("\nFaile 'in.txt', irasykite realu skaiciu priklausanti intervalui [10; 1000], su nedaugiau kaip 3 skaiciais po kalbelelio.\n");
    printf("Sveikoji ir realioji skaiciaus dalys turi buti atskirtos kableliu. Tai padarius paspauskite Enter klavisa.\n");
    getchar();

    inFile = fopen("in.txt", "r");

    while(inFile == NULL) {
        printf("Failas nerastas, sukurkite 'in.txt' faila ir irasykite realu skaiciu priklausanti intervalui [10; 1000], su nedaugiau kaip 3 skaiciais po kalbelelio. \n");
        printf("Sveikoji ir realioji skaiciaus dalys turi buti atskirtos kableliu. Tai padarius paspauskite Enter klavisa.\n");
        getchar();

        inFile = fopen("in.txt", "r");
    }

    while (restart) {
        while (((c = getc(inFile)) != EOF) && (!invalidInput)) {
            if (isdigit(c)) {
                if(decimal) {
                    if (countDecimal < 3) {
                        ++countDecimal;
                        dec += ((int)c - 48) / pow(10, countDecimal); 
                    } else 
                        invalidInput = true;
                } else 
                    if (countWhole < 4) {
                        wholeNum[countWhole] = c;
                        ++countWhole;
                } else {
                    invalidInput = true;
                }   
            } else 
                if((c == ',') && (countChars == 0)) {
                    decimal = true;
                    ++countChars;
            } else {
                invalidInput = true;
            }
        }

        if (!invalidInput) {
            for (int i = 0; i < countWhole; ++i) {
                num += ((int)wholeNum[i] - 48) * pow(10, (countWhole - i - 1));
            }
        }

        if(((num+dec) < 10.0) || ((num+dec) > 1000.0)) {
            invalidInput = true;
        }

        if (!invalidInput) {
            printf("\nIvesto skaiciaus ilgis yra %d\n", (countDecimal + countWhole));
            restart = false;
        } else {
            fclose(inFile);
            inFile = NULL;

            while(inFile == NULL) {
                memset(filename, 0, sizeof(filename));
                printf("Bloga ivestis, faile reikia irasyti realu skaiciu priklausanti intervalui [10; 1000], su nedaugiau kaip 3 skaiciais po kalbelelio.\n");
                printf("Sveikoji ir realioji skaiciaus dalys turi buti atskirtos kableliu.\nSukurkite nauja '.txt' faila, kuriame pataisysite ivesti ir parasykite jo pavadinima: \n");
                scanf("%s", &filename);

                if (stricmp(filename, "in") != 0) {
                    snprintf(file, sizeof(file), "%s.txt", filename);
                    inFile = fopen(file, "r");
                }
            }

            countWhole = 0, countDecimal = 0, countChars = 0;
            dec = 0, num = 0;
            decimal = false, invalidInput = false;
        }
    }

    fclose(inFile);
    return 0;
}