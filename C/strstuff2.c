#include <stdio.h>
int main()
{
    char word[10];
    printf("Enter a word: \n");
    gets(word);
    printf("\nYour word is : ");
    puts(word);
    return 0;
}