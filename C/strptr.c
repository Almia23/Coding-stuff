#include <stdio.h>
int main()
{
    char name[20];
    char *cptr=&name;
    int c=0;
    printf("Enter word: \n");
    scanf("%s",name);
    while(*cptr!= '\0')
    {
        cptr++;
        c++;
    }
    cptr++;
    printf("Length= %d",c);
    return 0;
}