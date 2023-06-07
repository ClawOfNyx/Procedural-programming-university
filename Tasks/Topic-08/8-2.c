#include <stdio.h>

long getFileSize(char *fileName);
char* getLargestFile(int size, char **fileNames);

int main(int argc, char *argv[]) {
    char *largest;

    if (argc > 1) {
        largest = getLargestFile((argc - 1), argv);
        printf("The largest file from parametres is %s", largest);
    } else {
        printf("No files given.");
    }

    return 0;
}


char* getLargestFile(int size, char **fileNames) {
    long max = getFileSize(fileNames[1]);
    int index = 1;

    for (int i = 2; i <= size; ++i) {
        if (getFileSize(fileNames[i]) > max) {
            max = getFileSize(fileNames[i]);
            index = i;
        }
    }

    return fileNames[index];
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