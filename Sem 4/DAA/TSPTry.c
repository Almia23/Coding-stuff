#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int s, optimal = 99999, c[100][100];

void swap(int v[], int i, int j)
{
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void travelling(int v[], int n, int i)
{
    int j, k;
    if (i == n)
    {
        if (v[0] == s)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d ", v[j]);
            }
            int sum1 = 0;
            for (k = 0; k < n - 1; k++)
            {
                sum1 = sum1 + c[v[k]][v[k + 1]];
            }
            sum1 = sum1 + c[v[n - 1]][s];
            printf(" Sum = %d\n", sum1);
            if (sum1 < optimal)
                optimal = sum1;
        }
    }
    else
    {
        for (j = i; j < n; j++)
        {
            swap(v, i, j);
            travelling(v, n, i + 1);
            swap(v, i, j);
        }
    }
}

int main()
{
    int n, v[100], i, j;

    printf("Enter number of cities: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            int num = rand() % 10;
            c[i][j] = c[j][i] = num;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("Enter source: \n");
    scanf("%d", &s);
    travelling(v, n, 0);
    printf("Optimal solution: %d", optimal);
    return 0;
}