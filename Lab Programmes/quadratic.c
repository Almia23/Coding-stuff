#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c,r;
    float d,root1,root2,im;
    printf("enter a,b,c in ax^2+bx+c\n");
    scanf("%d%d%d",&a,&b,&c);
    d=pow(b,2)-(4*a*c);
    if (d<0)
        r=1;
    else
    {
        if (d==0)
            r=2;
        else
            r=3;
    }
    switch(r)
    {
    case(1):
        {
            root1=-b/(2*a);
            im=sqrt(-(d))/(2*a);
            printf("The roots are imaginary, and values are %f + %f i and %f - %f i",root1,im,root1,im);
            break;
        }
    case(2):
        {
            root1=-b/(2*a);
            printf("Roots are equal, and value= %f",root1);
            break;
        }
    case(3):
        {
            root1=(-b+sqrt(d))/(2*a);
            root2=(-b-sqrt(d))/(2*a);
            printf("The roots are distinct, and values are %f and %f",root1,root2);
            break;
        }
    default:
        printf("Invalid");
    }
    return 0;
}
