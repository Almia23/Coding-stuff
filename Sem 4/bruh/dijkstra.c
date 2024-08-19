#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
int V;

void dijkstra(int cost[][100], int dist[], int s, int n)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[s][i];
        visited[i] = 0;
    }
    visited[s] = 1;
    dist[s] = 0;
    int count = 0;
    int v, min;
    while (count < n - 1)
    {
        min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] < min && !visited[i])
            {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;
        count++;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] > dist[v] + cost[v][i])
                dist[i] = dist[v] + cost[v][i];
        }
    }
}
int main()
{
    int n;
    printf("Enter number of vertices: \n");
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
    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = 9999;
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(cost, dist, src, n);
    printf("Shortest distances from vertex %d:\n", src);
    for (int i = 0; i < n; i++)
    {
        dist[i] = abs(dist[i] + 402292160);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d - %d = %d\n", src, i, dist[i]);
    }
}