#include <stdio.h>
int main()
{
    int n,i,no=0,r,s,j,st=0;
    printf("Enter number: \n");
    scanf("%d",&n);
    no=n;
    for(i=0;i<10000;i++)
    {
        s=1;
        r=n%10;
        for(j=1;j<=r;j++)
            s=s*j;
        st=st+s;
        n=(int)n/10;
        if (n==0)
            break;
    }
    if (st==no)
        printf("Strong");
    else
        printf("Not strong");
    return 0;
}