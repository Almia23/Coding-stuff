
#include <stdio.h>
#include <stdlib.h>
#define size 3
struct queue
{
	int data[size];
	int top;
	int rear;
};
int i;
typedef struct queue QUEUE;
void enqueue(QUEUE*);
void dequeue(QUEUE*);
void display(QUEUE*);
int main(){

    printf("\nProgram to implement cqueue\n");
    printf("Enter number of elements: \n");
    int n;
    scanf("%d",&n);
    QUEUE qu;
    qu.top=-1;
    qu.rear=-1;
	int c;
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
    if((q->rear==size-1&&q->top==0)||(q->top==q->rear+1)){
        printf("Queue is full, cannot enqueue.\n");
        return;
    }
    if(q->top==-1){
        q->top=0;
        q->rear=0;
    }
    else{
        if(q->rear==size-1)
            q->rear=0;
        else
            q->rear++;
    }
    printf("Enter item: \n");
    int n;
    scanf("%d",&n);
    q->data[q->rear]=n;
    printf("Element %d entered at %d\n",n,(q->rear)+1);
    return;
}
void dequeue(QUEUE *q){
    if(q->top==-1){
        printf("Queue is empty, cannot dequeue.\n");
        return;
    }
    printf("Element %d dequeued at %d\n",q->data[q->top],(q->top)+1);
    if(q->top==q->rear){
        q->top=-1;
        q->rear=-1;
    }
    else{
        if(q->top==size-1)
            q->top=0;
        else
            q->top++;
    }
    return;
}
void display(QUEUE *q){
    if(q->top==-1){
        printf("Queue is empty, cannot display.\n");
        return;
    }
    printf("Printing elements of queue:\n");
    if(q->top<=q->rear)
        for(i=q->top;i<=q->rear;i++)
            printf("%d ",q->data[i]);
    else
        for(i=q->top;i<=size-1;i++)
            printf("%d ",q->data[i]);
    return;
}
