#include <stdio.h>
#include <math.h>

int main() {
    int anum, n = 0, sum = 0, digit, to;

    printf("Enter to  Number: ");
    scanf("%d", &to);

    for (anum = 1 ; anum<= to ; anum++) {
        int temp = anum;
        while (temp != 0) {
            temp /= 10;
            n++;
        }

        temp = anum;

        for (int tn = n; tn != 0 ; tn--) {
            digit = temp % 10;
            sum = sum + pow(digit,n);
            temp /= 10;
        }
        if (sum == anum) {
            printf("%d,",anum);
        }
        n = 0;
        sum = 0;
    }
}