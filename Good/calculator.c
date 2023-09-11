// I have updated the name 
#include <stdio.h>

int main() {
    int a, d, n;
    printf("Enter the First term of the series : ");
    scanf("%d", &a);  // Use '&' before 'a' to get the address of the variable.
    
    printf("Enter the Common difference of the series : ");
    scanf("%d", &d);  // Use '&' before 'd' to get the address of the variable.
    
    printf("Enter the number of terms (n) : ");
    scanf("%d", &n);  // You need to get the value of 'n' from the user before using it in the formula.

    int Sn = (n * (2 * a + (n - 1) * d)) / 2;  // The formula for the sum of an AP is modified.
    
    printf("The sum up to %d terms of an AP with First term %d and common difference %d will be %d", n, a, d, Sn);

    return 0;
}
