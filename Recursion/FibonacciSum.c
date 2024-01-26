#include <stdio.h>

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int fibonacciSum (int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n) + fibonacciSum(n - 1);
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        printf("%d, ", fibonacci(i+1));
    }

    printf ("\n%d", fibonacciSum(4));
    return 0;
}