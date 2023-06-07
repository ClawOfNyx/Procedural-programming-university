/**
 * Parašyti funkciją, kuri iš duoto teksto išmeta žodžius,
 * kurių vidurinis simbolis yra skaitmuo (tarpų skaičius turi likti nepakitęs).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ID_LEN 5

bool checkMiddleSymbol(char* c);


int main() {
    char* arr = {   "aaaa",
                    "aaa",
                    "aa5a",
                    "a4aa",
                    "a66a"
                    };
    FILE *inFile = NULL;           
    char **line;
    int variableNumberOfElements = 5;


    line = malloc(variableNumberOfElements * sizeof(char*));
    for (int i = 0; i < variableNumberOfElements; i++) {
        line[i] = malloc((ID_LEN+1) * sizeof(char)); // yeah, I know sizeof(char) is 1, but to make it clear...
    }

    fgets(line, 256, inFile);
    //printf("%d", checkMiddleSymbol(arr));

    return 0;
}

bool checkMiddleSymbol(char* c) {
    bool hasDigit = false;
    int i;
    int length;

    length = sizeof(c)/sizeof(c[0]);
    printf("%d\n", length);

    if ((c[length / 2] > 47) && (c[length / 2] < 58)) {
        hasDigit = true;
    }

    return hasDigit;
}