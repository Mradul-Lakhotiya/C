#include <stdio.h>

int nCr(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    else {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
}

void printPascalTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", nCr(i, j));
        }

        printf("\n");
    }
}

int main() {
    printPascalTriangle(5);

    return 0;
}