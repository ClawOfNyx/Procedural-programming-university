#include <stdio.h>

int main() {
    int num;

    printf("Iveskite sveika skaiciu:");
    scanf("%d", &num);

    printf("Skaicius '%d' yra %s", num, (num % 2 == 0) ? ("lyginis") : ("nelyginis"));
    return 0;
}
