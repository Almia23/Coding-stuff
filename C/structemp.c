#include <stdio.h>
#include<math.h>
struct employee{
    int empno;
    char name[25];
    int age;
    int year;
    float salary;
} s[3];
int main()
{
    int i,c,flag=1;
    float temp;
    printf("Input values (Empno, Name, Age, Year of join, Salary): \n");
    for(i=0;i<3;i++)
    {
        scanf("%d %s %d %d %f",&s[i].empno,s[i].name,&s[i].age,&s[i].year,&s[i].salary);
    }
    for(i=0;i<3;i++) //to sort avg values
    {int years_rem=(55-s[i].age);
    int year_ret=s[i].year+years_rem;
    printf("Year of reitrement:%d\n",year_ret);
    int salary_new=s[i].salary*(pow(1.2,years_rem));
    printf("Salary at retirment:Rs.%d\n",salary_new);
        
    }
        
    
    return 0;
}