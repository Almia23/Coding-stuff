#include <stdio.h>
//Somehow inputs infinitely idek

void enq();
void deq();
void display();
int queue[1], size, front = -1, rear = -1;

int main(void)
{
    int option=0;

    printf("enter size of queue\n");
    scanf("%d", &size);
    queue[size] = 0;

    while(1)
    {
        printf("1:enqueue\t2:dequeue\t3:display\t4:exit\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}

void enq()
{
    if(rear == size -1)
    {
        printf("queue is full\n");
        return;
    }
    printf("enter element:\n");
    rear++;
    scanf("%d",&queue[rear]);
}

void deq()
{
    if(front == rear)
    {
        printf("empty queue\n");
        return;
    }
    printf("deleted element is: %d\n", queue[front]);
    front++;

    if(front == rear)
    {
        front = rear = -1;
    }
    return;
}

void display()
{
    if(front == rear)
    {
        printf("empty queue\n");
    }

    for(int i = front+1; i <= rear; i++)
    {
        printf("%d", queue[i]);
    }
    printf("\n");
}