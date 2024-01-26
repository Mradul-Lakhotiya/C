#include <stdio.h>
#include <math.h>

int findLen (int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return 1 + findLen(n/10);
    }
}

int revers(int n) {
    if (n == 0) {
        return 0;
    }
    
    int len = findLen(n);

    return (n % 10 * pow(10, --len) + revers(n/10));
}

int main () {
    
    printf("%d", revers(123));
    return 0;
}