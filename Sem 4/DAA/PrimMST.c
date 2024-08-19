
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int V, i, j, v, count, opcount = 0;

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    int i;
    for (i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i,
               graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (i = 0; i < V; i++)
        key[i] = INT_MAX;
    mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (v = 0; v < V; v++)
        {
            opcount++;
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }
    printMST(parent, graph);
}

int main()
{
    clock_t start, end;
    double tot;
    printf("Enter number of vertices:");
    scanf("%d", &V);
    int graph[V][V];
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            // scanf("%d", &graph[i][j]);
            graph[i][j] = rand() % 10;
        }
    }
    for (i = 0; i < V; i++)
    {
        graph[i][i] = 0;
    }
    printf("Distance matrix is: \n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("MST Edges and weights are: \n");
    start = clock();
    primMST(graph);
    end = clock();
    tot = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time: %lf\n", tot);
    printf("Opcount: %d\n", opcount);

    return 0;
}
