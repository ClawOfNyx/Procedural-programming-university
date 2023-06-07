#include <stdio.h>
#include <string.h>
#include <assert.h>

void set(char s[], char c, int n);

int main() 
{
    char s[] = "This is a trial";

    set(s, '#', 7);
    assert(strcmp(s, "####### a trial") == 0);

    set(s, '*', 0);
    assert(strcmp(s, "####### a trial") == 0);

    return 0;
}

void set(char s[], char c, int n)
{
    for(int i = 0; i < n; ++i) 
    {
        s[i] = c;
    }
}