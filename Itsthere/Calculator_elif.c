#include <stdio.h>

int main() {
    int firstNumber, secondNumber;
    char operation;

    // Prompt and input for the first number
    printf("Enter the first number: ");
    scanf("%d", &firstNumber);

    // Prompt and input for the second number
    printf("Enter the second number: ");
    scanf("%d", &secondNumber);

    // Prompt and input for the desired operation
    printf("Enter the function you want to perform:\n");
    printf("addition = a\nsubtraction = s\nmultiplication = m\ndivide = d\n");
    scanf(" %c", &operation);

    // Perform the selected operation based on the user's choice
    if (operation == 'a') {
        printf("The addition of %d and %d is %d\n", firstNumber, secondNumber, firstNumber + secondNumber);
    }
    else if (operation == 's') {
        printf("The subtraction of %d and %d is %d\n", firstNumber, secondNumber, firstNumber - secondNumber);
    } 
    else if (operation == 'm') {
        printf("The multiplication of %d and %d is %d\n", firstNumber, secondNumber, firstNumber * secondNumber);
    } 
    else if (operation == 'd') {
        if (secondNumber != 0) {
            printf("The division of %d and %d is %.2f\n", firstNumber, secondNumber, (float)firstNumber / secondNumber);
        } 
        else {
            printf("The division is not possible as the denominator is 0\n");
        }
    } 
    else {
        printf("Please enter a valid operation.\n");
    }
    
    return 0;
}
