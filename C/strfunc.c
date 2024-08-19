#include <stdio.h>
#include <string.h>
int main()
{
    char w1[100],w2[100];
    printf("Enter sentence: (# to end)");
    scanf("%[^#]",w1);
    printf("\nLength is %lu",(strlen(w1)));
    strcpy(w2,w1);
    printf("\n%d\n",strcmp(w1,w2));
    strcat(w1,w2);
    puts(w1);
    return 0;
}