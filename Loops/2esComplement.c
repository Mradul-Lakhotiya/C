#include <stdio.h>

int main() {
    int n;
    int carry = 1;

    printf("Enter the size of the binary number: ");
    scanf("%d", &n);

    char binary[n + 1];
    char onescomplement[n + 1];
    char twoscomplement[n + 2];  // Extend the size by one to handle carry

    printf("\nEnter the binary number: ");
    scanf("%s", binary);

    printf("%s", binary);
    printf("\nThe one's complement of the binary number is : ");

    for (int i = 0; i < n; i++) {
        if (binary[i] == '0') {
            onescomplement[i] = '1';
        } else if (binary[i] == '1') {
            onescomplement[i] = '0';
        }
    }

    onescomplement[n] = '\0';

    printf("%s", onescomplement);

    printf("\nThe two's complement of the binary number is : ");

    // Handle the carry separately
    for (int i = n - 1; i >= 0; i--) {
        if (onescomplement[i] == '1' && carry == 1) {
            twoscomplement[i + 1] = '0';
        } 
        else if (onescomplement[i] == '0' && carry == 1) {
            twoscomplement[i + 1] = '1';
            carry = 0;
        } 
        else {
            twoscomplement[i + 1] = onescomplement[i];
        }
    }

    // Set the most significant bit based on the final carry
    twoscomplement[0] = carry + '0';

    twoscomplement[n + 1] = '\0';

    printf("%s", twoscomplement);

    return 0;
}
