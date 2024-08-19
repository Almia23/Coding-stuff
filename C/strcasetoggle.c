#include<stdio.h>
#include<math.h>
#include<string.h>
#include <ctype.h>

void main()
{


char str[1000];
int n=1000;
printf("Enter string");
gets(str);
for(int i=0;i<n;i++)
{int a=str[i];
if(isalpha(str[i]))
{
if(a>=97){
a=(a-32);
str[i]=(char)(a);

}
else 
a=(a+32);
str[i]=(char)(a);
}

}
printf("New string:");
puts(str);
}