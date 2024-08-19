#include <stdio.h>
int main()
{
    int a,*p;
    p=&a; //setting address of a as pointer address
    *p=30; //giving pointer address value 30, dereferencing variable
    printf("%d",a);
    return 0;
}