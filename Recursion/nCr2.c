#include <stdio.h>

int nCr(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    else {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
}

int main() {
    int n, r;

    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of r: ");
    scanf("%d", &r);

    int result = nCr(n, r);
    printf("Combinations (nCr) result: %d\n", result);

    return 0;
}