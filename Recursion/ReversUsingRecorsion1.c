#include <stdio.h>

int revers(int n) {
    static int rev = 0;

    if (n == 0) {
        return rev;
    }

    rev = n % 10 + rev*10;
    return revers(n/10);
}

int main () {
    printf("%d ", revers(123456789));

    return 0;
}