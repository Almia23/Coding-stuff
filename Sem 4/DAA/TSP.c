#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_N 10 // Maximum number of cities

int N;                   // Number of cities
int graph[MAX_N][MAX_N]; // Graph representing distances between cities

int minCost = INT_MAX;
int optimalPath[MAX_N];
int visited[MAX_N] = {0};

void tsp(int currentCity, int depth, int path[], int cost)
{
    if (depth == N)
    {
        if (cost + graph[currentCity][0] < minCost)
        {
            minCost = cost + graph[currentCity][0];
            for (int i = 0; i < N; i++)
            {
                optimalPath[i] = path[i];
            }
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            path[depth] = i;
            tsp(i, depth + 1, path, cost + graph[currentCity][i]);
            visited[i] = 0;
        }
    }
}

int main()
{
    printf("Enter the number of cities (maximum %d): ", MAX_N);
    scanf("%d", &N);

    printf("Enter the distances between cities:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("Distance from city %d to city %d: ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }

    int path[MAX_N] = {0};
    clock_t start = clock();
    tsp(0, 1, path, 0);
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nOptimal Path: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", optimalPath[i] + 1); // Add 1 to convert back to 1-based indexing
    }
    printf("\nMinimum Cost: %d\n", minCost);
    printf("Time taken: %lf seconds\n", time_spent);

    return 0;
}