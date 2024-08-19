#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000
int opcount = 0;
int main()
{
    clock_t start, end;
    double tot;
    int a[SIZE];
    int i, j, t;
    for (i = 0; i < SIZE; i++)
    {
        a[i] = rand();
    }

    start = clock();
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                opcount++;
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    end = clock();

    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
    tot = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTotal time taken= %e", tot);
    printf("\nOpcountn= %d", opcount);

    return 0;
}