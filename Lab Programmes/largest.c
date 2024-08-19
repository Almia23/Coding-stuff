#include <stdio.h>
int main()
{
    int a,b;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("\nEnter second number: ");
    scanf("%d",&b);
    if (a>b)
        printf("First number is bigger");
    else
        printf("Second number is bigger");
    return 0;
}

