#include <stdio.h>
#include <string.h>

#define MAX 500

int shifttable[256];
int comparisons = 0, opcount = 0;

void shift_table(char pattern[], int patternlength)
{
    int i, j;
    for (i = 0; i < 250; i++)
        shifttable[i] = patternlength;
    for (i = 0; i < patternlength - 1; i++)
        shifttable[pattern[i]] = patternlength - 1 - i;
}

int horspool(char text[], char pattern[])
{
    int textlength = strlen(text);
    int patternlength = strlen(pattern);
    int i = patternlength - 1;
    int j;

    while (i < textlength)
    {
        comparisons++;
        j = patternlength - 1;
        while (j >= 0 && pattern[j] == text[i - patternlength + 1 + j])
        {
            j--;
        }
        if (j == -1)
        {
            return i - patternlength + 1;
        }
        else
        {
            i += shifttable[text[i]];
        }
    }
    return -1;
}

void main()
{
    char text[MAX], pattern[MAX];
    int successful, unsuccessful, position;

    printf("\nenter text: ");
    gets(text);
    printf("\nenter pattern: ");
    gets(pattern);

    shift_table(pattern, strlen(pattern));

    position = horspool(text, pattern);

    if (position != -1)
    {
        printf("\npattern found at: %d", position);
    }
    else
    {
        printf("\npattern not found in the text");
    }

    printf("\nnumber of comparisons: %d", comparisons);
}
