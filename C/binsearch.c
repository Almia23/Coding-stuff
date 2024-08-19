#include <stdio.h>
int main()
{
    int a=0,b=12,c,i,key;
    int L[]={2,4,5,7,8,9,10,11,12,13,14,15,16};
    printf("Enter the key to be searched: \n");
    scanf("%d",&key);
    c=(a+b)/2;
    while((a!=b)&&(key!=L[c]))
    {
        c=(a+b)/2;
        if(key<L[c])
            b=c;
        else
            a=c;
    }
    if(key==L[c])
        {
            printf("Key found at position %d",(c+1));
        }
    else
        printf("Key not found");
    return 0;
}