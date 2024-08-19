#include <stdio.h>
int main()
{
    int a,b,c,d;
    double dis;
    printf("Enter point 1: ");
    scanf("%d%d",&a,&b);
    printf("Enter point 2: ");
    scanf("%d%d",&c,&d);
    dis=(pow((pow((a-c),2)+pow((b-d),2)),0.5));
    printf("The distance is %g",dis);
    return 0;
}
