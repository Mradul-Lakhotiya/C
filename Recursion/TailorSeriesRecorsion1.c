#include <stdio.h>
#include <math.h>

// Function to calculate factorial
int factorial(int num) {
    if (num == 1 || num == 0) {
        return 1;
    }

    return num * factorial(num - 1);
}

// Function to calculate Taylor series
double tailorSeries(int n, double x) {
    if (n == 0) {
        return 0;
    }

    return pow(x, n) / factorial(n) + tailorSeries(n - 1, x);
}

int main(int argc, char const *argv[]) {
    double x; 
    int n;

    printf("Enter the number to find the Taylor series of: ");
    scanf("%lf", &x);
    printf("Enter the number of iterations to perform: ");
    scanf("%d", &n);

    // Calculate and display Taylor series result
    double result = tailorSeries(n, x);
    printf("Taylor series result: %lf\n", result);

    return 0;
}
