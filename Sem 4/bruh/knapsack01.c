#include <stdio.h>
#include <stdlib.h>

int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int selected[n + 1][W + 1];
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
                selected[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                int include = val[i - 1] + K[i - 1][w - wt[i - 1]];
                int exclude = K[i - 1][w];
                if (include > exclude)
                {
                    K[i][w] = include;
                    selected[i][w] = 1;
                }
                else
                {
                    K[i][w] = exclude;
                    selected[i][w] = 0;
                }
            }
            else
            {
                K[i][w] = K[i - 1][w];
                selected[i][w] = 0;
            }
        }
    }
    int j = W;
    printf("Items included in knapsack: \n");
    for (i = n; i > 0 && j > 0; i--)
    {
        if (selected[i][j])
        {
            printf("Item:%d Value:%d Weight:%d\n", i, val[i - 1], wt[i - 1]);
            j -= wt[i - 1];
        }
    }
    return K[n][W];
}

int main()
{
    int n, W;
    printf("Enter number of items: \n");
    scanf("%d", &n);
    int w[n], v[n];
    printf("Enter items weights and their values: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }
    printf("Enter capacity of knapsack: \n");
    scanf("%d", &W);
    int k = knapsack(W, w, v, n);
    printf("Best value: %d", k);
    return 0;
}