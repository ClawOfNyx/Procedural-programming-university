/**
 * Parašyti funkciją, kuri iš duoto teksto išmeta žodžius,
 * kurių vidurinis simbolis yra skaitmuo (tarpų skaičius turi likti nepakitęs).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isTxtFile(char *filename);
void inputCounter(int *words, int *maxLen, FILE *file);
bool isMiddleDigits(char *word);

int main(int argc, char *argv[]) {
    FILE *inFile = NULL;
    FILE *outFile = NULL;

    bool lineLimit = false;

    int i, j, words = 0, maxLen = 0, line = 0;

    char fileError[] = "There needs to be 2 file names ending in '.txt' given at launch.\n1st has to exist for reading the data and 2nd to store the answer can be created by the program.\nPlease try again.";
    char **text;
    char *trash;
    char ch;

    // inFile = fopen("in.txt", "r");

    // text = malloc(256 * sizeof(char*));
    // for (int i = 0; i < 256; i++) {
    //     text[i] = malloc(256 * sizeof(char));
    // }

    // for (i = 0; (i < 256) && (getc(inFile) != EOF); ++i) {
    //     // for (j = 0; j < MaxLine; ++j) {
    //     //     text[i][j] = 
    //     // }

    //     fscanf(inFile, "%256s", text[i]);

    //     strlen(text[i]);

    //     printf("%d %s\n", strlen(text[i]);, text[i]);


    // }

    if (argc == 3) {
        inFile = fopen(argv[1], "r");
        outFile = fopen(argv[2], "w");

        if (isTxtFile(argv[1]) && isTxtFile(argv[2]) && inFile != NULL && outFile != NULL) {
            inputCounter(&words, &maxLen, inFile);
            printf("Total words      = %d\n", words);

            printf("maxlen=%d\n", maxLen);

            if (maxLen > 256) {
                maxLen = 256;
            }

            text = malloc(words * sizeof(char*));
            for (int i = 0; i <= words; ++i) {
                text[i] = malloc(maxLen * sizeof(char));
            }
            trash = malloc(maxLen * sizeof(char));

            for (i = 0; (i < words) && (getc(inFile) != EOF); ++i) {
                fseek(inFile, -1, ftell(inFile));

                //fscanf(inFile, "%255s", text[i]);

                if (i > 0 && strlen(text[i - 1]) == 255) {

                    fscanf(inFile, "%255s", trash);
                
                    // printf("t*%s\n", trash);
                    // printf("i+1=%d > %d\n", i+1, words);
                    // fscanf(inFile, "%255s", text[i + 1]);
                    // memset(text[i+1], 0, strlen(text[i+1]));
                } //else {
                    // printf("0 < i-2=%d > %d\n", i-2, words);
                    // if (i >= 2 && strlen(text[i - 2]) == 255) {
                    //     printf("i-1=%d > %d\n", i-1, words);
                    //     memset(text[i-1], 0, strlen(text[i-1]));
                    //     fscanf(inFile, "%255s", text[i-1]);
                    // }
                //     memset(text[i], 0, strlen(text[i]));
                //     fscanf(inFile, "%255s", text[i]);
                // }
                // memset(text[i], 0, strlen(text[i]));
                fscanf(inFile, "%255s%c", text[i], &ch);

                if (ch != '\n') {
                    line += strlen(text[i]);
                } else {
                    line = 0;
                }
            }

            for (i = 0; i < words; ++i) {
                printf("%s\n", text[i]);
            }

            for (i = 0; i < words; ++i) {
                if (!isMiddleDigits(text[i])) {
                    fprintf(outFile, "%s\n", text[i]);
                }
            }

        } else {
            printf("%s\n", fileError);
        }
    } else {
        printf("%s", fileError);
    }

    fclose(inFile);
    fclose(outFile);
    free(text);
    free(trash);
    return 0;
}

bool isMiddleDigits(char *word) {
    int mid = strlen(word) / 2;

    if (mid % 2 == 1){
        if ((word[mid] > 47) && (word[mid] < 58)) {
            return true;
        }
    } else 
        if (mid % 2 == 0) {
            if ((word[mid] > 47) && (word[mid] < 58) && (word[mid - 1] > 47) && (word[mid - 1] < 58)) {
                return true;
            } 
    }

    return false;    
}

void inputCounter(int *words, int *maxLen, FILE *file) {
    char ch;
    int chars = 0;
    char word[1000];
    int len = 0;
    
    while ((ch = fgetc(file)) != EOF){
        ++chars;
        word[len] = ch;

        if (ch != '\n' || ch != '\0' || ch != ' ' || ch != '\t') {
            ++len;
        }

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0') {
            ++*words;
            if(strlen(word) - 1 <= 0) {
                --*words;
            }

            // printf("* %s\n\n\n", word);
            memset(word, 0, strlen(word));

            if (*maxLen < len) {
            *maxLen = len;
            }
            len = 0;
        }
    }

    /* Increment words and lines for last word */
    if (chars > 0) {
        ++*words;

        if(strlen(word) <= 1) {
            --*words;
        }

        if (*maxLen < len) {
            *maxLen = len;
        }
        len = 0;
    }

    rewind(file);
}

bool isTxtFile(char *filename) {
    int i, countTXT = 0;

    for (i = strlen(filename); i > -1; --i) {
        if ((filename[i] == 't' || filename[i] == 'T') && (countTXT == 0 || countTXT == 2)) {
            ++countTXT;
        } else 
            if ((filename[i] == 'x' || filename[i] == 'X') && countTXT == 1) {
                ++countTXT;
        } else 
            if (filename[i] == '.' && countTXT == 3) {
                ++countTXT;
        }

        if (countTXT == 4) {
            return true;
        }
    }
    return false;
}