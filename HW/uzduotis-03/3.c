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

    int delInLine = 0, wordsInLine = 0;

    int i, j, words = 0, maxLen = 0;

    char fileError[] = "There needs to be 2 file names ending in '.txt' given at launch.\n1st has to exist for reading the data and 2nd to store the answer can be created by the program.\nPlease try again.";
    char **text;
    char *trash;
    char *string;

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
            for (i = 0; i <= words; ++i) {
                text[i] = malloc(maxLen * sizeof(char));
            }
            trash = malloc(maxLen * sizeof(char));

            i = 0;
            while (!feof(inFile)) {
                char line[255];
                /*fgets 255 characters (or less if encountered \n or EOF) from inFile into char line[255]*/ 
                fgets(line, 256, inFile);

                /* checks if there is \n character anywhere in line*/
                if (strchr(line, '\n') == NULL) {
                    /*if \n is not found fgets and deletes remaining data in file's line*/ 
                    fgets(trash, 1024, inFile); 
                    memset(trash, 0, sizeof(trash));
                } else {
                    line[strcspn(line, "\n")] = 0;  /*removes newline char from string line, if it is found*/ 
                }

                free(string);
                string = strtok(line, " ");  /*breaks line into a series of tokens using delimiter: " " (whitespace)*/ 

                while (string != NULL) {
                    text[i++] = string;
                    ++wordsInLine;
                    
                    if (!isMiddleDigits(text[i - 1])) {
                        fprintf(outFile, "%s ", text[i - 1]);
                        
                    } else {
                        ++delInLine;
                    }
                    
                    string = strtok(NULL, " ");
                }

                if(wordsInLine > delInLine) {
                    fputc('\n', outFile);
                }
                wordsInLine = 0;
                delInLine = 0;
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
        if ((word[mid] >= '0') && (word[mid] <= '9')) {
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