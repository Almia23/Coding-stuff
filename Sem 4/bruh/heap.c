#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void buildheap(int a[], int n)
{
    int start = (n / 2) - 1;
    for (int i = start; i >= 0; i--)
    {
        heapify(a, n, i);
    }
}

void heap_sort(int a[], int n)
{
    buildheap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main()
{
    int i, n;
    printf("Enter size of heap: \n");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
        a[i] = rand() % 100;
    printf("\nOriginal array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    buildheap(a, n);
    printf("\nHeapified array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    heap_sort(a, n);
    printf("\nHeapsort: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
