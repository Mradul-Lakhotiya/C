#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int rear;
    int front;
    int *arr;
};

typedef struct Queue *Queue;

void create(Queue que);
void enqueue(Queue que, int x);
int dequeue(Queue que);
void display(Queue que);

int main() {
    Queue que = (Queue)malloc(sizeof(struct Queue));
    create(que);

    int choice, element;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(que, element);
                break;
            case 2:
                dequeue(que);
                break;
            case 3:
                display(que);
                break;
            case 0:
                free(que->arr);
                free(que);
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void create(Queue que) {
    printf("Enter the Size of The Queue: ");
    scanf("%d", &que->size);

    que->front = -1;
    que->rear = -1;

    que->arr = (int *)malloc(que->size * sizeof(int));
}

void enqueue(Queue que, int x) {
    if (que->rear == que->size - 1) {
        printf("Queue is FULL\n");
    } else {
        que->rear++;
        que->arr[que->rear] = x;
        printf("Enqueued: %d\n", x);
    }
}

int dequeue(Queue que) {
    if (que->rear == que->front) {
        printf("Queue is EMPTY\n");
        return -1;
    } else {
        int dequeued = que->arr[++que->front];
        printf("Dequeued: %d\n", dequeued);
        return dequeued;
    }
}

void display(Queue que) {
    if (que->rear == que->front) {
        printf("Queue is EMPTY\n");
    } else {
        printf("Queue elements: [ ");
        for (int i = que->front + 1; i <= que->rear; i++) {
            printf("%d ", que->arr[i]);
        }
        printf("]\n");
    }
}
