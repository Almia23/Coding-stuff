#include <stdio.h>
int main()
{
    char para[10];
    printf("Enter a paragraph, enter # to end: \n");
    scanf("%[^#]",para);
    printf("\nYour para is : ");
    puts(para);
    return 0;
}