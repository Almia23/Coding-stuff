#include <stdio.h>
struct student{
    char name[25];
    int rollno;
    int m1;
    int m2;
    int m3;
    float avg;
    int pos;
} s[3];
int main()
{
    int i,c,flag=1;
    float l[3],temp;
    printf("Input values (Name, Roll.no, Marks 1,2,3): \n");
    for(i=0;i<3;i++)
    {
        scanf("%s %d %d %d %d",&s[i].name,&s[i].rollno,&s[i].m1,&s[i].m2,&s[i].m3);
        s[i].avg=(s[i].m1+s[i].m2+s[i].m3)/3;
        l[i]=s[i].avg;
        s[i].pos=i;
    }
    for(i=0;i<2;i++) //to sort avg values
    {
        if(s[i].avg<s[i+1].avg)
        {
            int temp;
            temp=s[i].pos;
            s[i].pos=s[i+1].pos;
            s[i+1].pos=temp;
        }
    }int j;
    for(i=0;i<3;i++) //passes through struct 3 times
    {for(j=0;j<3;j++){
      if(s[j].pos==i)
      {
        printf("Name: %s, Avg marks: %f\n",s[j].name,s[j].avg);
        break;
      } }
        
    }
    return 0;
}
