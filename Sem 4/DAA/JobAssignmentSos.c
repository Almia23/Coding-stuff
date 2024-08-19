#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int c[100][100], ver;
int optimum = 999, sum;

void swap(int v[], int i, int j)
{
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void assignment(int v[], int p[], int n, int i)
{
    int j, sum1, k;
    if (i == n)
    {
        sum1 = 0;
        for (k = 0; k < n; k++)
        {
            sum1 = sum1 + c[v[k]][p[k]];
        }
        if (sum1 < optimum)
            optimum = sum1;
    }
    else
    {
        for (j = i; j < n; j++)
        {
            swap(v, i, j);
            for (k = i; k < n; k++)
            {
                swap(p, i, k);
                assignment(v, p, n, i + 1);
                swap(p, i, k);
            }
            swap(v, i, j);
        }
    }
}
int main()
{
    int ver, v[100], p[100], i, j;
    printf("\nEnter no of jobs and people: ");
    scanf("%d", &ver);
    for (i = 0; i < ver; i++)
    {
        v[i] = i + 1;
        p[i] = i + 1;
    }
    for (i = 1; i <= ver; i++)
    {
        for (j = 1; j <= ver; j++)
        {
            c[i][j] = rand() % 10;
        }
    }
    for (i = 1; i <= ver; i++)
    {
        for (j = 1; j <= ver; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    assignment(v, p, ver, 0);
    printf("\nOptimum solution with brute force technique is=%d\n", optimum);
    return 0;
}