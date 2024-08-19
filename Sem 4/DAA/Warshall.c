
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
int opcount = 0;
int V;

void printSolution(int reach[][V])
{
    printf("The transitive closure matrix is:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf("%d ", reach[i][j]);
        printf("\n");
    }
}

void transitiveClosure(int graph[][V])
{
    int reach[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

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

    printSolution(reach);
}

int main()
{

    clock_t start, end;
    double time;
    /* {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}*/

    printf("Enter size: \n");
    scanf("%d", &V);
    int graph[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            int k = abs((rand() % 10));
            k = k < 8 ? 0 : 1;
            graph[i][j] = k;
        }
    }
    for (int i = 0; i < V; i++)
    {
        graph[i][i] = 1;
    }
    // graph[1][3] = 0;
    // graph[1][2] = 1;
    // graph[2][1] = 0;
    // graph[2][3] = 1;

    printf("Adj Matrix: \n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    start = clock();
    transitiveClosure(graph);
    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time: %lf\n", time);
    printf("Opcount: %d", opcount);

    return 0;
}