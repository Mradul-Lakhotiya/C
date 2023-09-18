#include <stdio.h>
#include <math.h>

int main() {
    int anum, n = 0, sum = 0,digit;

    printf("Enter a Number: ");
    scanf("%d", &anum);

    int temp = anum;
    
    int originalNum = anum;
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
    if (sum == originalNum) {
        printf("%d is an Armstrong number", originalNum);
    } else {
        printf("%d is not an Armstrong number", originalNum);
    }
    return 0;
}
