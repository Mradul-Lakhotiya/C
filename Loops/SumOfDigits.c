#include <stdio.h>

// Function to count the number of digits in a number
int countNumderOfDigits(int x) {
    int count = 0;
    while (x > 0) {
        count++;
        x /= 10;
    }

    return count;
}

int main() {
    int x, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &x);

    while (1) {
        // Check if the number has only one digit
        if (countNumderOfDigits(x) == 1) {
            printf("%d", sum);
            return 0;
        } else {
            sum = 0;
            int temp = x;

            // Sum the digits of the current number
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
        }
        x = sum;
    }
}
