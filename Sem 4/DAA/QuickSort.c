// QUICK SORT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcount = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{

    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        opcount++;
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    clock_t start, end;
    double totaltime;
    int n;
    printf("Enter num of elements: ");
    scanf("%d", &n);
    int arr[n];

    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }

    printf("Original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    totaltime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("No. of operations : %d \n", opcount);
    printf("Time taken: %e\n", totaltime);

    return 0;
}