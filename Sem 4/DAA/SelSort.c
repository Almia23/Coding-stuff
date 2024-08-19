#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000
int opcount = 0;

int main()
{
    clock_t start, end;
    double tot;
    int i, j, t, max = 0;
    int a[SIZE];
    for (i = 0; i < SIZE; i++)
    {
        a[i] = abs(rand());
    }
    start = clock();
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            opcount++;
            if (a[j] > a[max])
            {
                max = j;
            }
        }
        t = a[max];
        a[max] = a[SIZE - i];
        a[SIZE - i] = t;
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