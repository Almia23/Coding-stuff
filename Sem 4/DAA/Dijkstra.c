#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int opcount = 0;
int V;
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    int i;
    for (i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    int i;
    for (i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    int count, v;
    for (count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (v = 0; v < V; v++)
        {
            opcount++;
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);
}

int main()
{
    clock_t start, end;
    double tot;

    printf("Enter number of vertices:");
    scanf("%d", &V);
    int i, j;
    int graph[V][V];
    for (i = 1; i < V; i++)
    {
        for (j = 0; j < i; j++)
        {
            graph[i][j] = rand() % 10;
            graph[j][i] = graph[i][j];
        }
    }
    for (i = 0; i < V; i++)
    {
        graph[i][i] = 0;
    }
    printf("Distance matrix: \n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("Enter source: ");
    int s;
    scanf("%d", &s);

    start = clock();
    dijkstra(graph, s);
    end = clock();

    tot = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time Taken: %lfs  ", tot);
    printf("Opcount: %d", opcount);
    return 0;
}
