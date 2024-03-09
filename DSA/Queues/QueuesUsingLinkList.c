#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

typedef struct Queue * Queue;

Queue front = NULL, rear = NULL;

void enqueue(int x);
int dequeue();
void display();

int main() {
    int choice, element;

    do {
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
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                while (front != NULL) {
                    dequeue();
                }
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (1);

    return 0;
}


void enqueue(int x) {
    Queue newQue = (Queue)malloc(sizeof(struct Queue));

    if (newQue == NULL) {
        printf("The Queue is FULL");
        exit(EXIT_FAILURE);
    }
    else {
        newQue->data = x;
        newQue->next = NULL;

        if (front == NULL) {
            front = newQue;
            rear = newQue;
        }
        else {
            rear->next = newQue;
            rear = newQue;
        }
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is EMPTY");
        return -1;
    }
    else {
        int dequeued = front->data;
        Queue temp = front;
        front = front->next;
        free(temp);

        printf("Dequeued: %d\n", dequeued);
        return dequeued;
    }
}

void display() {
    printf("[ ");
    Queue current = front;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\b ]");
}