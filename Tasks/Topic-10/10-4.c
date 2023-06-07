#include <stdio.h>
#include <assert.h>

int length(char s[]);
char* find(char s[], char c);

int main()
{
    char s[] = "Hello world!!!";
    assert(find(s, '?') == NULL);
    assert(find(s, 'd') == (s + sizeof(char) * 10));
    assert(find(s, ' ') == (s + sizeof(char) * 5));

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

char* find(char s[], char c)
{
    int l = length(s);

    for(int i = 0; i < l; ++i)
    {
        if(s[i] == c)
        {
            return (s + i * sizeof(char));
        }
    }

    return NULL;
}