#include <stdio.h>

int main() {
    int x;

    // Prompt the user to enter a number
    printf("Enter a Number: ");
    scanf("%d", &x);

    // Check if the number is odd using the ternary conditional operator
    // If x % 2 is 1, it's odd; otherwise, it's even
    // Print the result accordingly
    printf("The number is %s\n", (x % 2 == 1) ? "Odd" : "Even");

    return 0;
}
