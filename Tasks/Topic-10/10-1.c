#include <stdio.h>
#include <assert.h>

int length(char s[]);

int main()
{
    char s[] = "help";
    assert(length(s) == 4);
    return 0;
}

int length(char s[]) 
{
    int l = 0;

    while(s[l] != '\0') {
        ++l;
    }

    return l;
}