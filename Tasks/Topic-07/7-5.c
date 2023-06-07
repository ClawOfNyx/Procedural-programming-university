#include <stdio.h>

long getFileSize(char *fileName);

int main() {
    char fileName[256];
    long size;

    printf("Iveskite failo, kurio dydi norite suzinoti pavadinima: \n");
    scanf("%s", fileName);

    size = getFileSize(fileName);

    if (size != -1) {
        printf("Failo dydis baitais yra %ld", size);
    }


    return 0;
}

long getFileSize(char *fileName) {
    FILE* fp = fopen(fileName, "r");
  
    if (fp == NULL) {
        printf("Failas nerastas\n");
        return -1;
    }
  
    fseek(fp, 0L, SEEK_END);
    long int res = ftell(fp);
    fclose(fp);

    return res;
}