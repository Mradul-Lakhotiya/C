#include <stdio.h>

int main() {
    int x1, x2;

    printf("Enter the Number From which the sum is required: ");
    scanf("%d", &x1);

    printf("Enter the Number To which the sum is required: ");
    scanf("%d", &x2);

    printf("The sum of all the numbers from %d to %d is %d", x1, x2, - x1 * (x1 + 1) / 2 + x2 * (x2 + 1) / 2);

    return 0;
}
