#include <stdio.h>
int main()
{
    int rev=0,rd=0,n;
    printf("Enter a number \n");
    scanf("%d",&n);
    while(n>0)
    {
        rev = n%10;
        rd = (rd*10)+rev;
        n=(int) n/10;
        printf("%d\n",rd);
    }
    printf("the reversed digits is %d",rd);
    return 0;
}