#include <stdio.h>
#include <stdarg.h>
#include <float.h>

double max (int args_count, ...);

int main () {
    
    printf("%lf", max(7, 1.0, 1.0, 1.0, 3.0, 3.0, 8.0, 9.0));

    return 0;
}

double max (int args_count, ...) {
    va_list args;
    va_start(args, args_count);

    double MAX = DBL_MIN;

    for (int i = 0; i < args_count; i++) {
        double current = va_arg(args, double);

        if (MAX < current) {
            MAX = current;
        }
    }

    va_end(args);

    return MAX;
}