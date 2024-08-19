#include <stdio.h>

int main() {
  int a,b, i, j, count = 0, key;

  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &a, &b);

  int arr[a][b];

  printf("Enter the elements of the matrix: ");
  for (i = 0; i < a; i++) {
    for (j = 0; j < b; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  printf("Enter the element to search for: ");
  scanf("%d", &key);

  for (i = 0; i < a; i++) {
    for (j = 0; j < b; j++) {
      if (arr[i][j] == key) {
        count++;
      }
    }
  }

  printf("The element %d occurs %d times in the matrix.\n", key, count);

  return 0;
}