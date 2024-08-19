#include<stdio.h>
#include<math.h>
void main()
{
    //reading array
printf("Enter number of rows and culumns in array");
int r,c;
scanf("%d%d",&r,&c);
int arr[r][c];
int i,j;
//entering array values
int trace,norm1;
trace=0,norm1=0;
printf("Enter values");
for(i=0;i<r;i++)
{
    for(j=0;j<c;j++)
    {
        scanf("%d",&arr[i][j]);
        if(i==j)
        trace+=arr[i][j];
        norm1+=(arr[i][j]*arr[i][j]);
    }
}
int norm;
norm=sqrt(norm1);
printf("The array is:\n");
for(i=0;i<r;i++)
{
    for(j=0;j<c;j++)
    {
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}
printf("Trace=%d,Norm=%d\n",trace,norm);




}