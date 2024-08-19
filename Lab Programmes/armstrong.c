#include <stdio.h>
#include <math.h>
int main()
{
    int n,i,j,n1=0,no;
    printf("Enter number: \n");
    scanf("%d",&n);
    no=n;
    for(j=0;j<10000;j++)
    {
        
        if (n==0)
            break;
        n=(int)n/10;
    }
    n=no;
    for(i=0;i<j;i++)
    {
        n1=n1+(pow((n%10),j));
        n=(int)n/10;
        if (n==0)
            break;
    }
    printf("%d",n1);
    if (no==n1)
        printf("Armstrong");
    else
        printf("Not armstrong");
    return 0;
}