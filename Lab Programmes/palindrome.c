#include <stdio.h>
int main()
{
    int n,i=0,n1=0,no;
    printf("Enter number: \n");
    scanf("%d",&n);
    no=n;
    for(i=0;i<10000;i++)
    {
        n1=(n1*10)+(n%10);
        n=(int)n/10;
        if (n==0)
            break;
    }
    printf("Reversed= %d\n",n1);
    if (no==n1)
        printf("Palindrome");
    else
        printf("Not palindrome");
    return 0;
}