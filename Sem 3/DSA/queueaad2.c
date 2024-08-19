#include <stdio.h>

void enq();
void deq();
void display();
int queue[10], size, front = 0, rear = 0;

int main(void)
{
    int option=0;

    printf("enter size of queue\n");
    scanf("%d", &size);

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
    if(rear == size)
    {
        printf("queue is full\n");
        return;
    }
    printf("enter element:\n");
    scanf("%d",&queue[rear]);
    rear++;
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
        front = rear = 0;
    }
    return;
}

void display()
{
    if(front == rear)
    {
        printf("empty queue");
    }

    for(int i = front; i < rear; i++)
    {
        printf("%d", queue[i]);
    }
    printf("\n");
}