#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int i,j;
void swap(char* str1, char *str2)
{
    char temp[100];
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
    return;
}
void ssort(char* strings[], int n)
{
    for(i=0;i<n-1;i++)
    for(j=0; j<n-i-1; j++)
    if(strcmp(strings[j],strings[j+1])>0)
    swap(strings[j],strings[j+1]);
    return;
}
int main()
{
    printf("Enter number of names: ");
    int n;
    scanf("%d",&n);
    char *strings[n];
    for(i=0;i<n;i++)
    {
        printf("Enter string %d: \n",(i+1));
        strings[i]=calloc(100,sizeof(char));
        scanf("%s",strings[i]);
    }
    ssort(strings,n);
    printf("Sorted strings: \n");
    for(i=0;i<n;i++)
    {
        printf("%s\n",strings[i]);
        free(strings[i]);
    }
    return 0;
}