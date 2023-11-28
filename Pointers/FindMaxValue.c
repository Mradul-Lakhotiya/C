// Max number using pointers

#include <stdio.h>

int main () {
    int a, b;
    printf ("Enter the value of a : ");
    scanf ("%d", &a);
    printf ("Enter The value of b : ");
    scanf ("%d", &b);

    int *prt1 = &a;
    int *prt2 = &b;

    int *Max = *prt1 >= *prt2 ? prt1 : prt2;

    printf ("%d", *Max);
}