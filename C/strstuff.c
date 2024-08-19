#include <stdio.h>
int main()
{
    char word[10]={'w','o','a','h','\0'};
    char word2[6]="Yay";
    char kiminonawa[10];
    printf("Enter name: \n");
    scanf("%s",&kiminonawa);
    printf("%s %s your name is %s",word2,word,kiminonawa);
    return 0;

}