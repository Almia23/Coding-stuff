#include <stdio.h>

void prims(int cost[][100], int n)
{
    int mincost = 0;
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[0] = 1;
    printf("The spanning tree vertices are:\n");
    int ne = 0, u, v;
    while (ne < n - 1)
    {
        int min = 999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min && visited[i] == 1 && visited[j] == 0)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        printf("%d edge (%d,%d)=%d\n", ne++, u, v, cost[u][v]);
        mincost += min;
        printf("mincost=%d\n", mincost);
        visited[v] = 1;
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int cost[100][100];

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    prims(cost, n);
    return 0;
}