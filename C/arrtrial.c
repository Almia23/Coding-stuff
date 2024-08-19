#include <stdio.h>
int main()
{
    int n,i,arr[50];
    printf("Enter number of elements: \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    printf("\n%d",arr[i]);
    return(0);
}