#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

void create(struct Stack *st);
void push(struct Stack *st, int data);

int pop(struct Stack *st);
int peek(struct Stack *st, int index);

bool isEmpty(struct Stack *st);
bool isFull(struct Stack *st);

int main() {
    struct Stack myStack;
    create(&myStack);

    int choice, data;

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
            push(&myStack, data);
            break;
        case 2:
            if (!isEmpty(&myStack)) {
                printf("Popped element: %d\n", pop(&myStack));
            } else {
                printf("Stack is empty. Cannot pop.\n");
            }
            break;
        case 3:
            int index;
            printf("Enter index to peek: ");
            scanf("%d", &index);

            int peekedValue = peek(&myStack, index);

            if (peekedValue != -1) {
                printf("Peeked element at index %d: %d\n", index, peekedValue);
            } 
            else {
                printf("Stack is empty or index is invalid.\n");
            }
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
    }
} while (choice != 0);


    return 0;
}

void create(struct Stack *st) {
    printf("Enter the size of arr: ");
    scanf("%d", &st->size);

    st->arr = (int *)malloc(st->size * sizeof(int));
    st->top = -1; 
}

void push(struct Stack *st, int data) {
    if (!isFull(st)) {
        st->top++;
        st->arr[st->top] = data;
        printf("Pushed %d onto the stack.\n", data);
    } else {
        printf("Stack is full. Cannot push.\n");
    }
}

int pop(struct Stack *st) {
    return isEmpty(st) ? -1 : st->arr[st->top--];
}

int peek(struct Stack *st, int index) {
    return isEmpty(st) ? -1 : st->arr[st->top - index + 1];
}

bool isEmpty(struct Stack *st) {
    return st->top == -1;
}

bool isFull(struct Stack *st) {
    return st->top == (st->size - 1);
}
