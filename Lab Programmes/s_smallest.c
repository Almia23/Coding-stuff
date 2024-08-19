#include <stdio.h>
int main()
{
    int a,b,c,big;
    printf("Enter three numbers: \n");
    scanf("%d%d%d",&a,&b,&c);
    big=(a>b?a:b);
    big=(big>c?big:c);
    printf("Biggest= %d",big);
    return 0;
}