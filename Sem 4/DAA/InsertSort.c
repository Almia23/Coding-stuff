// INSERT SORT
#include <stdio.h>
#include <time.h>
void insertionSort(int arr[], int n)
{
    int i, key, j, opcount = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (++opcount && j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("No of operations : %d\n", opcount);
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    printf("Sorted Array : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
    clock_t start, end;
    double totaltime;
    int n;
    printf("Enter num of elements: ");
    scanf("%d", &n);
    int arr[n];

    int i;
    printf("Enter elements: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    start = clock();
    insertionSort(arr, n);
    end = clock();

    printArray(arr, n);

    totaltime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %lf\n", totaltime);

    return 0;
}