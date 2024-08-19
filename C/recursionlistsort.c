#include <stdio.h>
int listsort(int a[], int l)
{
    if(l==1)
    return(0);
    else
    {
        int max=0,t;
        for(int i=0;i<l;i++)
        {
            if(a[i]>a[max])
            max=i;
        }
        t=a[max];
        a[max]=a[l-1];
        a[l-1]=t;
        return(listsort(&a,(l-1)));
    }
}
int main()
{
    int a[]={3,2,1};
    listsort(a,3);
    printf("Sorted list: \n");
    for(int i=0;i<3;i++)
    printf("%d ",a[i]);
    return 0;
}