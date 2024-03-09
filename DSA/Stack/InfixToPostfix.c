#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    char ch;
    struct Stack *prev;
}*top;

char pop() {
    if (top == NULL) {
        printf("The Stack is Empty\n");
        return -1;
    }
    char ch = top->ch;
    struct Stack *temp = top;
    top = top->prev;
    free(temp);

    return ch;
}

void push(char ch) {
    struct Stack *newt = (struct Stack *)malloc(sizeof(struct Stack));

    if (newt == NULL) {
        printf("Memory allocation failed // Stack is Full");
        return;
    }

    newt->ch = ch;
    newt->prev = top;
    top = newt;
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

int isOperand(char ch) {
    if ((ch >= 'a' && ch <='z') || (ch >= 'A' && ch <='Z')) {
        return 1;
    }
    else {
        return 0;
    }
} 

char *infixToPostfix(char *infix) {
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc((len + 1) * sizeof(char));

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        }
        else {
            if (precedence(infix[i]) > precedence(top->ch)) {
                push(infix[i++]);
            }
            else {
                postfix[j++] = pop();
            }
        }
    }

    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return postfix;
}

int main() {
    char *infix = "a+b+c-d*a*c";
    push('#');
    char *postfix = infixToPostfix(infix);
    printf("%s", postfix);

    free(postfix);
}