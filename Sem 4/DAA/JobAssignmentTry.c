#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int c[100][100], optimal = 99999;

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
        if (sum1 < optimal)
            optimal = sum1;
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
    int n, v[100], p[100], i, j;
    printf("Enter number of jobs and people: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        v[i] = i + 1;
        p[i] = i + 1;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            c[i][j] = rand() % 10;
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

    printf("\n");
    assignment(v, p, n, 0);
    printf("Optimal solution= %d", optimal);

    return 0;
}