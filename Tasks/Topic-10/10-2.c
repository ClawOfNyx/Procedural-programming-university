#include <stdio.h>
#include <assert.h>

int length(char s[]);
int compare(char* s1, char* s2);

int main()
{
    char s1[] = "HELP", s2[] = "help", s3[] = "HELPING";

    assert(compare(s1, s2) == -1);
    assert(compare(s1, s3) == -1);
    assert(compare(s1, s1) == 0);
    assert(compare(s2, s1) == 1);

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

int compare(char* s1, char* s2)
{
    int l1 = length(s1);
    int l2 = length(s2);

    if(l1 > l2)
    {
        return 1;
    }

    else if (l1 < l2)
    {
        return -1;
    }

    for(int i = 0; i < l1; ++i) 
    {
        if(s1[i] > s2[i])
        {
            return 1;
        }

        else if(s1[i] < s2[i])
        {
            return -1;
        }
    }

    return 0;
}