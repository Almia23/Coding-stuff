// MERGE SORT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int opcount = 0;
int i, j, k;
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        opcount++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        opcount++;
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        opcount++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    clock_t start, end;
    double totaltime;
    int n;
    printf("Enter num of elements: ");
    scanf("%d", &n);
    int arr[n];
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
    mergeSort(arr, 0, n - 1);

    printf("\nSorted array is \n");
    printArray(arr, n);

    end = clock();

    totaltime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %lf\n", totaltime);
    printf("Opcount: %d", opcount);

    return 0;
}