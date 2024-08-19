#include <stdio.h>
int main()
{
    int r;
    float a;
    printf("Enter radius of the circle: ");
    scanf("%d",&r);
    a=3.14*r*r;
    printf("\nThe area of the circle is %f",a);
    return 0;
}
