// Question 2.
// Program to Check if a number is prime or Not?
// A prime number is a number that is divisible by 1 and itself only.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool isPrime(int n)
{
    if (n < 1)
    {
        return false;
    }

    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    // Write Your Code Here

    return true;
}

int main()
{
    // Test Case 1
    printf("Test Case 1: %s\n", isPrime(7) ? "true" : "false");

    // Test Case 2
    printf("Test Case 2: %s\n", isPrime(4) ? "true" : "false");

    // Test Case 3
    printf("Test Case 3: %s\n", isPrime(2) ? "true" : "false");

    // Test Case 4
    printf("Test Case 5: %s\n", isPrime(-5) ? "true" : "false");

    // Test Case 5
    printf("Test Case 6: %s\n", isPrime(997) ? "true" : "false");

    // Test Case 6
    printf("Test Case 7: %s\n", isPrime(1000) ? "true" : "false");

    return 0;
}
