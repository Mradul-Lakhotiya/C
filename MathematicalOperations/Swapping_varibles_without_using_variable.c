#include <stdio.h>

int main () {
    int num1, num2;

    num1 = 1;
    num2 = 7;

    printf ("\nBefore Swapping: First Number = %d and Second Number = %d\n", num1, num2);

    // Swap the values without using a third variable
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    printf ("\nAfter Swapping: First Number = %d and Second Number = %d\n\n", num1, num2);

    return 0;
}
