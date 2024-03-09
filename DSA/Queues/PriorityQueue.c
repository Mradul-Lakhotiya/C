#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

typedef struct Node* PriorityQueue;

void enqueue(PriorityQueue* front, int data, int priority);
int dequeue(PriorityQueue* front);
void display(PriorityQueue front);

int main() {
    PriorityQueue front = NULL;

    enqueue(&front, 10, 2);
    enqueue(&front, 20, 1);
    enqueue(&front, 30, 3);

    printf("Priority Queue: ");
    display(front);

    int removed = dequeue(&front);
    printf("\nDequeued: %d\n", removed);

    printf("Updated Priority Queue: ");
    display(front);

    return 0;
}

void enqueue(PriorityQueue* front, int data, int priority) {
    struct Node* newElement = (struct Node*)malloc(sizeof(struct Node));
    if (newElement == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newElement->data = data;
    newElement->priority = priority;
    newElement->next = NULL;

    if (*front == NULL || priority < (*front)->priority) {
        newElement->next = *front;
        *front = newElement;
    } else {
        struct Node* temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }

        newElement->next = temp->next;
        temp->next = newElement;
    }
}

int dequeue(PriorityQueue* front) {
    if (*front == NULL) {
        printf("Priority Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    int removedData = (*front)->data;
    struct Node* temp = *front;
    *front = (*front)->next;
    free(temp);

    return removedData;
}

void display(PriorityQueue front) {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}
