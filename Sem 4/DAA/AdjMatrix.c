#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j;
    printf("Enter num of nodes:\n");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter adjacency matrix: \n");

    for (i = 0; i < n; i++)
    {
        printf("Values for node %d:\n", i);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int c;
    do
    {
        printf("Enter 2 nodes to check adjacency: \n");
        int m, n;
        scanf("%d%d", &m, &n);
        if (a[m][n] > 0)
        {
            printf("Edge exists\n");
        }
        else
        {
            printf("No edge\n");
        }
        printf("Enter 1 to continue: \n");
        scanf("%d", &c);
    } while (c == 1);

    return 0;
}