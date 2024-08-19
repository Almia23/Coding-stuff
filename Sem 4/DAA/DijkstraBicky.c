#include <stdio.h>
#include <stdlib.h>

void dijkstra(int cost[][25], int dist[], int s, int size)
{
    int visited[size];
    for (int i = 0; i < size; i++)
    {
        dist[i] = cost[s][i];
        visited[i] = 0;
    }
    visited[s] = 1;
    dist[s] = 0;
    int count = 0;
    int v, min;
    while (count < size - 1)
    {
        min = 999;
        for (int i = 0; i < size; i++)
        {
            if (dist[i] < min && !visited[i])
            {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;
        count++;
        for (int i = 0; i < size; i++)
        {
            if (dist[i] > dist[v] + cost[v][i])
                dist[i] = dist[v] + cost[v][i];
        }
    }
}

int main()
{
    int size;
    printf("Enter the number of vertices: ");
    scanf("%d", &size);

    int cost[size][size];
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    int dist[size];
    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(cost, dist, source, size);

    printf("Shortest distances from vertex %d:\n", source);
    for (int i = 0; i < size; i++)
    {
        printf("%d - %d = %d\n", source, i, dist[i]);
    }

    return 0;
}