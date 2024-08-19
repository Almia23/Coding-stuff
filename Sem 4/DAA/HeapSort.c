#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int opcount = 0;
void heapify(int arr[], int n, int i)
{
    opcount += 2;
    int largest = i;
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void build_heap(int arr[], int n)
{
    // Index of the last non-leaf node
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heap_sort(int arr[], int n)
{
    build_heap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        opcount++;
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;
    int i, j, t;
    // Displaying original array
    printf("Original array: \n");
    printArray(arr, n);

    clock_t start = clock();
    heap_sort(arr, n);
    clock_t end = clock();

    // Displaying sorted array
    printf("Sorted array: \n");
    printArray(arr, n);

    // Calculating time taken for sorting
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    printf("Opcount: %d\n", opcount);

    return 0;
}
