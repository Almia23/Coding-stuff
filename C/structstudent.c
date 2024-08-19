#include <stdio.h>
struct student{
    char name[25];
    int rollno;
    int m1;
    int m2;
    int m3;
    float avg;
} s[3];
int main()
{
    int i,j,c,flag=1;
    float l[3],temp;
    printf("Input values (Name, Roll.no, Marks 1,2,3): \n");
    for(i=0;i<3;i++)
    {
        scanf("%s %d %d %d %d",&s[i].name,&s[i].rollno,&s[i].m1,&s[i].m2,&s[i].m3);
        s[i].avg=(s[i].m1+s[i].m2+s[i].m3)/3;
        l[i]=s[i].avg;
    }
    for(i=0;i<3;i++)
    printf("%f ",l[i]);

    for(i=0;i<2;i++) //to sort avg values
    {
        for(j=0;j<2-i;j++)
        {
            if(l[j]>l[j+1])
                {
                    temp=l[i];
                    l[i]=l[i+1];
                    l[i+1]=temp;
                }
        }
    }
    printf("\n");
    for(i=0;i<3;i++)
    printf("%f ",l[i]);
    /*
    for(i=0;i<3;i++) //passes through struct 3 times
    {
        c=0;
        while(flag==1)
        {
            if(s[c].avg==l[i])
            {
                printf("Name: %s, Avg marks: %f\n",s[i].name,s[i].avg);
                break;
            }
            c++;
        }
    }
    */
    return 0;
}
