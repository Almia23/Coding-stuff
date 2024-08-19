#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent an element in the priority queue
typedef struct {
    int data;
    int priority;
} PriorityQueueElement;

// Structure to represent the priority queue
typedef struct {
    PriorityQueueElement elements[MAX_SIZE];
    int size;
} PriorityQueue;

// Function to initialize an empty priority queue
void initializePriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Function to check if the priority queue is empty
int isPriorityQueueEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Function to check if the priority queue is full
int isPriorityQueueFull(PriorityQueue *pq) {
    return pq->size == MAX_SIZE;
}

// Function to enqueue an element with a given priority
void enqueue(PriorityQueue *pq, int data, int priority) {
    if (isPriorityQueueFull(pq)) {
        printf("Priority queue is full. Cannot enqueue.\n");
        return;
    }

    int i = pq->size - 1;
    while (i >= 0 && priority < pq->elements[i].priority) {
        pq->elements[i + 1] = pq->elements[i];
        i--;
    }

    pq->elements[i + 1].data = data;
    pq->elements[i + 1].priority = priority;
    pq->size++;
}

// Function to dequeue the element with the highest priority
int dequeue(PriorityQueue *pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int data = pq->elements[0].data;
    int i;

    for (i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }

    pq->size--;
    return data;
}

int main() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    // Enqueue elements with priority
    enqueue(&pq, 30, 3);
    enqueue(&pq, 20, 2);
    enqueue(&pq, 10, 1);
    enqueue(&pq, 40, 4);

    // Dequeue and print elements
    while (!isPriorityQueueEmpty(&pq)) {
        printf("Dequeued: %d\n", dequeue(&pq));
    }

    return 0;
}
