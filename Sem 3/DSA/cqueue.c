#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent the circular queue
typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

// Function to initialize an empty circular queue
void initializeQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(CircularQueue *queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

// Function to add an element to the rear of the queue
void enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->items[queue->rear] = value;
    }
}

// Function to remove an element from the front of the queue
int dequeue(CircularQueue *queue) {
    int removedItem;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        removedItem = queue->items[queue->front];
        if (queue->front == queue->rear) {
            // If there was only one element in the queue
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return removedItem;
    }
}

// Function to display the elements of the queue
void display(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        int i = queue->front;
        printf("Queue elements: ");
        do {
            printf("%d ", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);
    int c;
	while(1)
	{
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Please enter the choice\t");

		scanf("%d", &c);
		printf("\n");

		switch(c)
		{
			case 1:	
            {
                int item;
                printf("Item: ");
                scanf("%d",&item);
                enqueue(&queue, item);
				break;
            }
			case 2:	printf("Dequeued: %d\n", dequeue(&queue));
				break;
			case 3:	display(&queue);
				break;
			case 4: exit(0);
			default:	printf("Invalid selection\nPlease re-enter\n");
		}
	}
    return 0;
}
