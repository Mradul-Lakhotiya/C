#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef struct {
    int front;
    int arr[size];
    int rear;
} Queue;

void enQueues(Queue **que, int data) {
    if (((*que)->rear + 1) % size == (*que)->front) {
        printf("Queue is full\n");
    }
    else {
        (*que)->arr[((*que)->rear) % size] = data;
        (*que)->rear = ((*que)->rear + 1) % size;
    }
}

void printQueue(Queue *que) {
    for (int i = que->front; i != que->rear; i = (i + 1) % size) {
        printf("%d ", que->arr[i]);
    }
    printf("\n");
}

int deQueue(Queue **que) {
    if ((*que)->front == (*que)->rear) {
        printf("Queue is empty\n");
    }
    else {
        (*que)->front = ((*que)->front + 1) % size;
        int data = (*que)->arr[(*que)->front];
    }
}

int main(void) {
    Queue* que = (Queue *)malloc(sizeof(Queue));
    que->front = 0;
    que->rear = 0;
    enQueues(&que, 10);
    enQueues(&que, 20);
    enQueues(&que, 30);
    enQueues(&que, 40);
    enQueues(&que, 50);
    enQueues(&que, 60);
    enQueues(&que, 70);
    enQueues(&que, 80);
    enQueues(&que, 90);
    enQueues(&que, 100);
    
    printQueue(que);

    deQueue(&que);
    deQueue(&que);

    printQueue(que);

    enQueues(&que, 110);
    enQueues(&que, 120);    

    printQueue(que);
}