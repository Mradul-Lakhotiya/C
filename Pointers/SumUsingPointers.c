// Write a program in C to demonstrate how to handle pointers in a program.

#include <stdio.h>

int main () {
    int a, b;
    printf ("Enter the value of a : ");
    scanf ("%d", &a);
    printf ("Enter The value of b : ");
    scanf ("%d", &b);
    
    int *prt1 = &a, *prt2 = &b;
    *prt1 = *prt1 + *prt2;

    printf (" a + b = %d", *prt1);
}