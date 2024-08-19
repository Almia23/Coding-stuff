#include <stdio.h>

int main() {
  char str[100];
  int count = 0, i;

  printf("Enter a sentence: ");
  fgets(str, sizeof str, stdin);

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      count++;
    }
  }
    if(count!=0)
    count++;
  printf("The sentence contains %d words.\n", count);

  return 0;
}