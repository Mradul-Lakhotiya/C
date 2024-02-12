/*
Author: Mradul Lakhotiya
SAP ID: 500125405
Email: Mradul.125405@stu.upes.ac.in
Batch: Batch-50
Aim: Find the total number of alphabets, digits, or special characters in a string.
*/
#include <stdio.h>
#include <string.h>

int main() {
    char Something[100];
    int Alph = 0, Specahr = 0, Digits = 0;

    // Input the string
    printf("Enter the string: ");
    gets(Something);

    int size = strlen(Something);

    for (int i = 0; i < size; i++) {
        if (('a' <= Something[i] && Something[i] <= 'z') || ('A' <= Something[i] && Something[i] <= 'Z')) {
            Alph++;
        } else if ('0' <= Something[i] && Something[i] <= '9') {
            Digits++;
        } else {
            Specahr++;
        }
    }

    // Display the counts
    printf("Alphabets = %d \nDigits = %d \nSpecial characters = %d\n", Alph, Digits, Specahr);

    return 0;
}
