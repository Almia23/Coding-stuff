#include <stdio.h>
int main()
{
    int arr[100][100],i,j,a,b,flag=0;
    printf("Enter number of rows and columns: \n");
    scanf("%d %d",&a,&b);
    printf("Enter elements: \n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    /*for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    */
    for(i=0;i<a;i++)
    for(j=0;j<b;j++)
    {
        if(arr[i][j]!=arr[j][i])
        {
            flag=1;
            break;
        }
        if(flag==1)
        break;
    }
    if(flag==1)
    printf("Not symmetric");
    else
    printf("Symmentric");
    return 0;
}