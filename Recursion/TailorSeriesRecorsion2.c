#include <stdio.h>

// Function to calculate Taylor series
double tailorSeries(double x, int n) {
    if (n == 0) {
        return 1;
    }
    static double factorial = 1, power = 1;
    double result = tailorSeries(x, --n);

    factorial = factorial * n;
    power = power * x;

    return result + power / factorial;
}

int main() {
    double x;
    int n;

    // Input values
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the number of terms (n) for Taylor series: ");
    scanf("%d", &n);

    // Calculate and display Taylor series result
    double result = tailorSeries(x, n);
    printf("Taylor series result: %lf\n", result);

    return 0;
}
