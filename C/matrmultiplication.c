#include <stdio.h>
int main()
{
    int arr[100][100],brr[100][100],crr[100][100];
    int i,j,p,q,r,s,a,b,flag=0;
    printf("Enter number of rows and columns for first: \n");
    scanf("%d %d",&p,&q);
    printf("Enter elements of first: \n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    printf("Enter number of rows and columns of second: \n");
    scanf("%d %d",&r,&s);
    printf("Enter elements of second: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<s;j++)
        {
            scanf("%d",&brr[i][j]);
        }
        
    }
    
    for(i=0;i<p;i++)
    {
        for(j=0;j<s;j++)
            {
                if(q!=r)
                {
                    flag=1;
                    break;
                }
                crr[i][j]=0;
                
                for(a=0,b=0;(a<r)&&(b<q);a++,b++)
                {
                    crr[i][j]=crr[i][j]+(arr[i][b]*brr[a][j]);
                    
                }
            }
        if(flag==1)
        {
            printf("Multiplication not possible");
            break;
        }
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<s;j++)
        {
            printf("%d ",crr[i][j]);
        }
        printf("\n");
        
    }
    return 0;
}