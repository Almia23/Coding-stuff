#include <stdio.h>
int main()
{
    int i;
    float c;
    printf("Enter inches: ");
    scanf("%d",&i);
    c=i*2.54;
    printf("\nThe distance in cm= %f",c);
    return 0;
}
