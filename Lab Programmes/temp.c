#include <stdio.h>
int main()
{
    float f,c;
    printf("Enter temperature in fahrenheit: ");
    scanf("%f",&f);
    c=(f-32)/1.8;
    printf("\nThe temperature in celcius is %f",c);
    return 0;
}
