#include <stdio.h>

int main () {
    int num1, num2, temp; // Variables for num1, num2, and a temporary variable (temp)

    num1 = 1;
    num2 = 7;

    printf ("\nBefore Swapping: First Number = %d and Second Number = %d\n", num1, num2);

    // Swap the values using a temporary variable
    temp = num1;
    num1 = num2;
    num2 = temp;

    printf ("\nAfter Swapping: First Number = %d and Second Number = %d\n\n", num1, num2);

    return 0;
}
