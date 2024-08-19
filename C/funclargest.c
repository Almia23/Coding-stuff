#include <stdio.h>
int Largest(int list[],int k)
{
    int i,l=0;
    for(i=0;i<k;i++)
    if(l<list[i])
    l=list[i];
    return(l);
}
int main()
{
    int n,i;
    printf("Enter number of terms in list: \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements: \n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("The largest is %d",Largest(a,n));
    return 0;
}