#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int minCost = 99999; // Variable to store the minimum cost

// Function to calculate the cost of assignment
int calculateCost(int matrix[N][N], int assignment[N])
{
    int cost = 0;
    for (int i = 0; i < N; i++)
    {
        cost += matrix[i][assignment[i]];
    }
    return cost;
}

// Function to check if a task can be assigned to a worker
int isSafe(int task, int worker, int assignment[N])
{
    for (int i = 0; i < task; i++)
    {
        if (assignment[i] == worker)
        {
            return 0; // Worker is already assigned a task
        }
    }
    return 1;
}

// Recursive function to explore all possible assignments using branch and bound
void assignTasks(int matrix[N][N], int assignment[N], int task, int costSoFar)
{
    if (task == N)
    {
        // All tasks are assigned, update the minimum cost
        if (costSoFar < minCost)
        {
            minCost = costSoFar;
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        // Check if task can be assigned to worker i
        if (isSafe(task, i, assignment))
        {
            assignment[task] = i;
            // Update costSoFar with the cost of the current assignment
            int currentCost = costSoFar + matrix[task][i];

            // Prune the branch if the current cost exceeds the minimum cost
            if (currentCost < minCost)
            {
                // Recursively explore the next task
                assignTasks(matrix, assignment, task + 1, currentCost);
            }
        }
    }
}

int main()
{
    int matrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}};

    int assignment[N]; // Array to store the assignment of tasks to workers

    // Initialize assignment array
    for (int i = 0; i < N; i++)
    {
        assignment[i] = -1;
    }

    clock_t start = clock(); // Start measuring time

    assignTasks(matrix, assignment, 0, 0);

    clock_t end = clock(); // End measuring time

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Minimum cost: %d\n", minCost);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}