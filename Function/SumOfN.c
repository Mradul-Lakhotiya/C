#include <stdio.h>
#include <stdarg.h>


double sumOfN (int args_count, ...);

int main () {
    printf ("%lf", sumOfN(3, 1.0, 2.0, 3.0));

    return 0;
}

double sumOfN (int args_count, ...) {
    double sum = 0.0;
    //* This line declares a variable of type va_list named args. 
    //* It's like a tool that helps the function handle variable arguments.
    va_list args; 
    //* This line initializes the args tool to start processing variable arguments. 
    //* It's set up to begin at the first variable argument after the fixed argument num.
    va_start(args, args_count);

    for (int i = 0; i < args_count; i++) {
        sum += va_arg(args, double);
    }

    va_end(args);

    return sum;
}