#include <stdio.h>
#include <time.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Array to store whether an item is selected or not
    int selected[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                K[i][w] = 0;
                selected[i][w] = 0; // No items selected
            }
            else if (wt[i - 1] <= w)
            {
                // Including the current item
                int include = val[i - 1] + K[i - 1][w - wt[i - 1]];
                // Excluding the current item
                int exclude = K[i - 1][w];

                if (include > exclude)
                {
                    K[i][w] = include;
                    selected[i][w] = 1; // Mark current item as selected
                }
                else
                {
                    K[i][w] = exclude;
                    selected[i][w] = 0; // Mark current item as not selected
                }
            }
            else
            {
                K[i][w] = K[i - 1][w];
                selected[i][w] = 0; // Mark current item as not selected
            }
        }
    }

    // Printing the selected items
    printf("Items included in the knapsack:\n");
    int j = W;
    for (i = n; i > 0 && j > 0; i--)
    {
        if (selected[i][j])
        {
            printf("Item %d (Value: %d, Weight: %d)\n", i, val[i - 1], wt[i - 1]);
            j -= wt[i - 1]; // Reduce capacity by the weight of selected item
        }
    }

    return K[n][W];
}

int main()
{
    int n, W;
    clock_t start, end;
    double tot;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &val[i], &wt[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    start = clock();
    printf("Maximum value that can be obtained is %d\n", knapSack(W, wt, val, n));
    end = clock();
    tot = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %lf", tot);
    return 0;
}
