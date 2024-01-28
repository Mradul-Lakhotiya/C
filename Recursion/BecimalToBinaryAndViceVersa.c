#include <stdio.h>
#include <math.h>

int len (int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return 1 + len(n/10);
    }
}

int binaryToDecimal(int binary) {
    if (binary == 0) {
        return 0;
    }
    else {
        int length = len(binary) - 1;
        return (binary % 10)*(pow(2, length)) + binaryToDecimal(binary/10);
    }
}

int decimalToBinary (int decimal) {
    if (decimal == 0) {
        return 0;
    }
    else {
        return (decimal % 2) + decimalToBinary(decimal/2)*10;
    }
}

int main() {
    printf("%d\n", binaryToDecimal(1111));
    printf("%d", decimalToBinary(15));
    return 0;
}