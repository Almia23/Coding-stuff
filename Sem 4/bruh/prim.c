#include <stdio.h>
#include <stdlib.h>

void prims(int cost[][100], int n)
{
    int mincost = 0;
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    visited[0] = 1;

    printf("Spanning tree vertices are: \n");
    int ne = 0, u, v;
    while (ne < n - 1)
    {
        int min = 9999;
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
        printf("Edge %d: (%d-%d) Weight:%d\n", (++ne), u, v, cost[u][v]);
        mincost += min;
        visited[v] = 1;
    }
    printf("Mincost: %d", mincost);
}
int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int cost[n][n];

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