#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    clock_t start, end;
    double tot;
    char s[2000], w[100];
    printf("Enter string sentence: \n");
    scanf("%2000[^\n]", &s);
    printf("Enter word: \n");
    scanf("%s", &w);
    int i, j, flag = 0;
    start = clock();
    for (i = 0; i < strlen(s) - strlen(w) + 1; i++)
    {
        for (j = 0; j < strlen(w); j++)
        {
            if (s[i + j] != w[j])
                break;
            if (j == strlen(w) - 1)
            {
                flag = 1;
                break;
            }
        }
    }
    end = clock();
    if (flag)
    {
        printf("Found");
    }
    else
    {
        printf("Not found");
    }
    tot = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTotal time taken= %e", tot);
    return 0;
}