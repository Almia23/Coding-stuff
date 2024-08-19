#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 500
int shifttable[256];
int comparisions = 0;

void shift_table(char pattern[], int patternlength)
{
    int i, j;
    for (i = 0; i < 250; i++)
        shifttable[i] = patternlength;
    for (i = 0; i < patternlength - 1; i++)
        shifttable[pattern[i]] = patternlength - i - 1;
}
int horspool(char text[], char pattern[])
{
    int tlen = strlen(text);
    int plen = strlen(pattern);
    int j, i = plen - 1;
    while (i < tlen)
    {
        comparisions++;
        j = plen - 1;
        while (j >= 0 && pattern[j] == text[i - plen + 1 + j])
            j--;
        if (j == -1)
            return i - plen + 1;
        else
            i += shifttable[text[i]];
    }
    return -1;
}
int main()
{
    char text[max], pattern[max];
    int s, p;
    printf("Enter text: \n");
    gets(text);
    printf("Enter pattern: \n");
    gets(pattern);
    shift_table(pattern, strlen(pattern));
    p = horspool(text, pattern);
    if (p == -1)
        printf("\nPattern not found");
    else
        printf("\nPattern found at index %d", p);
    printf("\nNumber of comparisions: %d", comparisions);
    return 0;
}
