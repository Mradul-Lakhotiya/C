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

int main() {
    struct Stack *top = NULL;

    int choice, data, index;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                printf("Popped element: %d\n", pop(&top));
                break;
            case 3:
                printf("Enter index to peek: ");
                scanf("%d", &index);
                printf("Peeked element at index %d: %d\n", index, peek(top, index));
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    while (top != NULL) {
        pop(&top);
    }

    return 0;
}
