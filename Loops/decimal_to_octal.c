#include <stdio.h>

int main() {
    int num, sum = 0, digit, onum=0;

    printf("Enter a number in decimal form: ");
    scanf("%d", &num);
    //converting it into the octal
    while (num != 0) {
        digit = num % 8;
        sum = digit + sum * 10;
        num /= 8;
    }
    digit = 0;
    //recopacal of the digit
    while (sum!=0) {
        digit = sum % 10;
        onum = digit + onum * 10;
        sum /= 10;
    }

    printf("Octal representation: %d\n", onum);
}
