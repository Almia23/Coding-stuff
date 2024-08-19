#include <stdio.h>
#include <math.h>
int main()
{
    int bi,dec=0,i=0,r;
    printf("Enter the binary number: \n");
    scanf("%d",&bi);
    while(bi>0)
    {
        r=bi%10;
        bi=(int)bi/10;
        dec=dec+(pow(2,i)*r);
        i++;
    }
    printf("\nDecimal: %d",dec);
    return 0;
}