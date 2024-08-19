#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 99999
int main()
{
    int i, j, k, n;
    printf("Enter number of jobs: \n");
    scanf("%d", &n);
    int minp[n];    // To store min cost of person for that job's index.
    int mincost[n]; // To store mincost for that job
    int data[n][n]; // Holds costs of jobs for persons

    for (i = 0; i < n; i++)
        minp[i] = mincost[i] = Max; // Initialize all persons so no NULL during check

    for (i = 0; i < n; i++)
    { // Input data into job costs
        printf("Enter costs for person %d\n", (i + 1));
        for (j = 0; j < n; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    { // iterate through jobs
        int temp = Max;
        int person = -1;
        for (j = 0; j < n; j++)
        { // iterate through people under 1 job
            if (data[j][i] < temp)
            {
                temp = data[j][i];
                person = j; // store data of new minimum temporarily
            }
        }
        int flag = 1;
        for (k = 0; k < n; k++)
        { // iterate through min cost array to check if person present
            if (minp[k] == person)
            {
                if (mincost[k] > temp)
                {          // if found, and min cost of that is higher
                    i = k; // go back to that job and iterate again
                    flag = 0;
                    break;
                }
                else
                {                     // if mincost of prev smaller
                    i = i - 1;        // iterate j again to find the second lowest
                    data[j][i] = Max; // set this one as high num
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        { // if not found, add it to the cost array
            minp[i] = person;
            mincost[i] = temp;
        }
    }
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += mincost[i]; // add all mincosts
    }
    printf("Minimum total cost= %d\n", sum);
    return 0;
}