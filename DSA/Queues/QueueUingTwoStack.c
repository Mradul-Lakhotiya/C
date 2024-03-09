#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack *prev;
};

void push(struct Stack **top, int data) {
    struct Stack *newT = (struct Stack *)malloc(sizeof(struct Stack));

    if (newT == NULL) {
        printf("Stack Is Full\n");
        return;
    }

    newT->data = data;
    newT->prev = *top;
    *top = newT;
}

int pop(struct Stack **top) {
    if (*top == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }

    struct Stack *temp = *top;
    int x = temp->data;
    *top = (*top)->prev;

    free(temp);
    return x;
}

int peek(struct Stack *top, int index) {
    int currentPosition = 0;

    while (top != NULL && currentPosition < index) {
        top = top->prev;
        currentPosition++;
    }

    if (top != NULL) {
        return top->data;
    } else {
        return -1;
    }
}

void enqueue(struct Stack **s, int data) {
    push(s, data);
}

int dequeue(struct Stack **s1, struct Stack **s2) {
    if (*s2 == NULL) {
        while (*s1 != NULL) {
            push(s2, pop(s1));
        }
    }

    return pop(s2);
}

int main() {
    struct Stack *s1 = NULL;
    struct Stack *s2 = NULL;

    enqueue(&s1, 1);
    enqueue(&s1, 2);
    enqueue(&s1, 3);

    printf("Queue elements: ");
    display(s1);

    int dequeued = dequeue(&s1, &s2);
    printf("\nDequeued element: %d\n", dequeued);

    printf("Updated Queue elements: ");
    display(s1);

    return 0;
}
