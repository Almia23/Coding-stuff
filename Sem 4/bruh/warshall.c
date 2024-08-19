#include <stdio.h>
#include <stdlib.h>
int V, opcount = 0;

void printsol(int reach[][V])
{
    printf("Transitive closure: \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

void transitiveClosure(int graph[][V])
{
    int reach[V][V], i, j, k;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            reach[i][j] = graph[i][j];
        }
    }
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                opcount++;
            }
        }
    }
    printsol(reach);
}

int main()
{
    int n, i, j;
    printf("Enter number of nodes: \n");
    scanf("%d", &V);
    int graph[V][V];
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            int k = abs((rand() % 10));
            k = k < 8 ? 0 : 1;
            graph[i][j] = k;
        }
    }
    for (i = 0; i < V; i++)
    {
        graph[i][i] = 1;
    }
    printf("Adj Matrix: \n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    transitiveClosure(graph);
    return 0;
}