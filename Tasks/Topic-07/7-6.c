#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int showMenu(int menuSize, char *menuTitle, char menuOptions[menuSize][MAX], char *inputMsg);

int main() {
    char title[] = "Editor";
    char options[][MAX] = {
        "Find",
        "Replace",
        "Cut",
        "Copy",
        "Paste",
        "Hide"
    };

    int size = sizeof(options)/sizeof(options[0]);
    char message[] = "Norint pasirinkti, iveskite skaiciu atitinkanti meniu pasirinkima: ";
    int choice;

    choice = showMenu(size, title, options, message);
    printf("Sekmingai pasirinkote '%d. %s'", choice, options[choice - 1]);

    return 0;
}

int showMenu(int menuSize, char *menuTitle, char menuOptions[menuSize][MAX], char *inputMsg) {
    int num;
    bool invalidInput = true;
    
    printf("%s:", menuTitle);
    for (int i = 0; i < menuSize; ++i) {
        printf("\n%5d. %s", (i + 1), menuOptions[i]);
    }

    printf("\n%s", inputMsg);
    while (invalidInput) {
        if ((scanf("%d", &num) == 1) && ((num > 0) && (num <= menuSize)) && (getchar() == '\n')) {
            invalidInput = false;
        } else {
            printf("\n%s", inputMsg);
            while (getchar() != '\n')
                ;
            invalidInput = true;
        }
    }

    return  num;
}