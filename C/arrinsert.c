#include<stdio.h>
void main(){
int array[50], position, i, n, value;
printf("Enter number of elements in the array\n");
scanf("%d", &n);
printf("Enter %d elements\n", n);
for (i = 0; i < n; i++)
scanf("%d", &array[i]);
printf("Please enter the location where you want to insert an new element \n");
scanf("%d", &position);
printf("Please enter the value \n");
scanf("%d", &value);
for(i=n;i>=position;i--)
{
    array[i]=array[i-1];
}

    array[position-1]= value;
printf("new array:\n");
for(i = 0; i <= n ; i++)
{
printf("%d", array[i]);
}
}