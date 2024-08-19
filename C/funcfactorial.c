#include <stdio.h>
int fact(int k)
{
    int i,f=1;
    for(i=1;i<=k;i++)
    f*=i;
    return(f);
}
int main()
{
    int n;
    printf("Enter number: \n");
    scanf("%d",&n);
    if((n==0)||(n==1))
    printf("The factorial is 1");
    else
    printf("The factorial is %d",fact(n));
    return 0;
}
