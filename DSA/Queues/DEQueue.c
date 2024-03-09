#include <stdio.h>
#include <stdlib.h>

struct DEQueue {
    struct DEQueue *prev;
    struct DEQueue *next;
    int data;
};

typedef struct DEQueue *DEQueue;

DEQueue front = NULL, rear = NULL;

void enqueueFront(int x);
void enqueueRear(int x);
void display();
int dequeueFront();
int dequeueRear();

int main() {
    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue at the front: ");
                scanf("%d", &element);
                enqueueFront(element);
                break;
            case 2:
                printf("Enter element to enqueue at the rear: ");
                scanf("%d", &element);
                enqueueRear(element);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 0:
                // Clean up and exit
                while (front != NULL) {
                    dequeueFront();
                }
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (1);

    return 0;
}

void enqueueFront(int x) {
    DEQueue newQue = (DEQueue)malloc(sizeof(struct DEQueue));

    if (newQue == NULL) {
        printf("Queue is FULL\n");
        exit(EXIT_FAILURE);
    } else {
        newQue->data = x;
        newQue->next = NULL;
        newQue->prev = NULL;

        if (front == NULL) {
            front = newQue;
            rear = newQue;
        } else {
            newQue->next = front;
            front->prev = newQue;
            front = newQue;
        }
    }
}

void enqueueRear(int x) {
    DEQueue newQue = (DEQueue)malloc(sizeof(struct DEQueue));

    if (newQue == NULL) {
        printf("Queue is FULL\n");
        exit(EXIT_FAILURE);
    } else {
        newQue->data = x;
        newQue->next = NULL;
        newQue->prev = NULL;

        if (front == NULL) {
            front = newQue;
            rear = newQue;
        } else {
            newQue->prev = rear;
            rear->next = newQue;
            rear = newQue;
        }
    }
}

int dequeueFront() {
    if (front == NULL) {
        printf("Queue is EMPTY\n");
        return -1;
    } else {
        int dequeued = front->data;
        DEQueue temp = front;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;
        }
        free(temp);

        printf("Dequeued from Front: %d\n", dequeued);
        return dequeued;
    }
}

int dequeueRear() {
    if (front == NULL) {
        printf("Queue is EMPTY\n");
        return -1;
    } else {
        int dequeued = rear->data;
        DEQueue temp = rear;
        rear = rear->prev;
        if (rear != NULL) {
            rear->next = NULL;
        }
        free(temp);

        printf("Dequeued from Rear: %d\n", dequeued);
        return dequeued;
    }
}

void display() {
    DEQueue current = front;
    printf("DEQueue elements: [ ");
    while (current != NULL) {
        printf(" %d,", current->data);
        current = current->next;
    }
    printf("\b ]\n");
}
