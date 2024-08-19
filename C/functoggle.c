#include <stdio.h>
#include <string.h>

void toggleCase(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);
    printf("String before toggling case: %s\n", str);
    toggleCase(str);
    printf("String after toggling case: %s\n", str);
    return 0;
}
