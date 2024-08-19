#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int data[3];
	int top;
    int rear;
};

typedef struct queue QUEUE;
void enqueue(QUEUE*);
void dequeue(QUEUE*);
void display(QUEUE*);
int main(){
    printf("\nProgram to implement queue\n");
    printf("Enter number of elements: \n");
    int n;
    scanf("%d",&n);
    QUEUE qu;
	int c;
	qu.top = 0;
    qu.rear=-1;
	while(1)
	{
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Please enter the choice\t");

		scanf("%d", &c);
		printf("\n");

		switch(c)
		{
			case 1:	enqueue(&qu);
				break;
			case 2:	dequeue(&qu);
				break;
			case 3:	display(&qu);
				break;
			case 4: exit(0);
			default:	printf("Invalid selection\nPlease re-enter\n");
		}
	}
    return 0;
}
void enqueue(QUEUE *q){
    if(q->rear==2){
        printf("Queue is full, cannot enqueue.\n");
        return;
    }
    printf("Enter item: \n");
    int n;
    scanf("%d",&n);
    q->rear++;
    q->data[q->rear]=n;
    printf("Element %d entered at %d\n",n,(q->rear)+1);
    return;
}
void dequeue(QUEUE *q){
    if(q->rear==-1||q->top>q->rear){
        printf("Queue is empty, cannot dequeue.\n");
        return;
    }
    printf("Element %d dequeued at %d\n",q->data[q->top],(q->top)+1);
    q->top++;
    return;
}
void display(QUEUE *q){
    if(q->rear==-1||q->top>q->rear){
        printf("Queue is empty, cannot dequeue.\n");
        return;
    }
    int i;
    printf("Printing elements of queue:\n");
    for(i=q->top;i<=q->rear;i++)
        printf("%d\n",q->data[i]);
    return;
}
