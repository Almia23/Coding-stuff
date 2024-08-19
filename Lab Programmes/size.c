#include <stdio.h>
int main()
{
    char c;
    int a;
    float f;
    double d;
    long int li;
    long double ld;
    printf("The size of int is %lu\n",sizeof(a));
    printf("The size of char is %lu\n",sizeof(c));
    printf("The size of float is %lu\n",sizeof(f));
    printf("The size of double is %lu\n",sizeof(d));
    printf("The size of long int is %lu\n",sizeof(li));
    printf("The size of long double is %lu\n",sizeof(ld));
    return 0;
}
