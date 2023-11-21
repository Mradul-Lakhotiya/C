#include <stdio.h>

int main() {
    int x1, x2;          // Variables to store input numbers
    char operator;       // Variable to store the chosen operator

    // Prompt and input for the first number
    printf("Please enter the first number: ");
    scanf("%d", &x1);

    // Prompt and input for the second number
    printf("Please enter the second number: ");
    scanf("%d", &x2);

    // Prompt and input for the chosen operation
    printf("Enter the operation you want to conduct (+, -, *, /): ");
    scanf(" %c", &operator);  // The space before %c is used to consume any leading whitespace characters

    switch (operator) {
        case '+':
            printf("The sum of %d and %d is %d\n", x1, x2, x1 + x2);
            break;

        case '-':
            printf("The difference of %d and %d is %d\n", x1, x2, x1 - x2);
            break;

        case '*':
            printf("The product of %d and %d is %d\n", x1, x2, x1 * x2);
            break;

        case '/':
            if (x2 != 0) {
                printf("The division of %d by %d is %.2f\n", x1, x2, (float)x1 / x2);
            } else {
                printf("Division by zero is not allowed\n");
            }
            break;

        default:
            printf("Please enter a valid operation (+, -, *, /)\n");
    }

    printf("Thanks for using this calculator\n");
    return 0;
}
