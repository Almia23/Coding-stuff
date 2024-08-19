#include <stdio.h>
#include <stdlib.h>
//USING ARRAY
int a[5],top=-1;

void push()
{
    if(top==5)
        printf("Overflow\n");
    else
    {
        top+=1;
        printf("Enter value: ");
        scanf("%d",&a[top]);
    }
    return;
}
void pop(void)
{
    if(top<0)
        printf("Underflow\n");
    else
    {
        printf("The popped value is: %d\n",a[top]);
        top-=1;
    }
    return;
}
void display(void)
{
    printf("Printing values: \n");
    int i;
    if(top>-1)
        for(i=0;i<=top;i++)
            printf("%d\n",a[i]);
    return;
}
int main()
{
    int ch;
    do
    {
        int ch;
        printf("Enter 1:Push, 2:Pop, 3:Display, 4:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case(1):
        {
            push();
            break;
        }

        case(2):
        pop();
        break;
        case(3):
        display();
        break;
        case(4):
            printf("Exiting");
            exit(0);
            break;
        default:
            printf("Enter valid choice\n");
            break;
        }
    }while(ch!=4);
    return 0;
}
