#include <stdio.h>
int main()
{
    int i=0,j,n,min,max,temp=0;
    int a[1000];
    printf("Enter amount of numbers to be sorted: \n");
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%d",&a[i]);
        i++;
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}