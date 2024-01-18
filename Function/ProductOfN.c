#include <stdio.h>
#include <stdarg.h>

double productofn (int args_count, ...);

int main () {
    printf ("%lf", productofn(3, 1.0, 8.0, 4.0));

    return 0;
}

double productofn (int args_count, ...) {
    va_list args;
    va_start(args, args_count);
    double product = 1.0;

    for (int i = 0; i < args_count; i++) {
        product *= va_arg(args, double);
    }

    va_end(args);

    return product;
}