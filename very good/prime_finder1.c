#include <stdio.h>
#include <math.h>

int main() {
    int x;
    float s, c;
    
    printf("Enter a Number: ");
    scanf("%d", &x);

    if (x == 1) {
        printf("Did You Know ONE is not a prime number\n");
    } else {
        if (x == 2 || x == 3 || x == 5 || x == 7 || x == 11) {
            printf("%d is a prime\n", x);
        } else {
            if (x % 2 != 0 && x % 3 != 0 && x % 5 != 0 && x % 7 != 0) {
                s = sqrt(x);
                if (s * s != x) {
                    c = cbrt(x);
                    if (c * c * c != x) {
                        printf("%d is a prime\n", x);
                    } else {
                        printf("%d is not a prime\n", x);
                    }
                } else {
                    printf("%d is not a prime\n", x);
                }
            } else {
                printf("%d is not a prime\n", x);
            }
        }
    }

    return 0;
}
