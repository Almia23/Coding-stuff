#include <stdio.h>
int main()
{
    int a=30,b=10,c=5,d=15;
    printf("Expression 1= %d",((a+b)*c/d));
    printf("\nExpression 2= %d",(((a+b)*c)/d));
    printf("\nExpression 3= %d",(a+(b*c)/d));
    printf("\nExpression 4= %d",((a+b)*(c/d)));
    return 0;
}