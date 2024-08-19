#include <stdio.h>

void push();
void pop();
void display();
int stack[1],size,top = 0;

int main(void)
{
    int option = 0;
    printf("enter size of stack\n");
    scanf("%d", &size);
    stack[size] = 0;
    while(1){
        printf("1:push \t2:pop \t3:display \t4:exit\n");
        scanf("%d", &option);
        switch(option)
            {
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    return 0;
            }
    }
}

void push()
{
    if(top == size)
    {
        printf("overflow\n");
        return;
    }
    printf("enter element\n");
    scanf("%d", &stack[top]);
    top++;

}

void pop()
{
    if(top == 0)
    {
        printf("underflow\n");
        return;
    }
    printf("deleted element: %d\n", stack[top-1]);
    top--;
}

void display()
{
    if(top == 0)
    {
        printf("null stack\n");
        return;
    }
    for(int i = 0; i < top; i++)
    {
        printf("%d", stack[i]);
    }
    printf("\n");
}