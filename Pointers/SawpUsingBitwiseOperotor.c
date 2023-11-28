#include <stdio.h>

void sawp (int *prt1, int *prt2) {
    *prt1 = *prt1 ^ *prt2;
    *prt2 = *prt1 ^ *prt2;
    *prt1 = *prt1 ^ *prt2;
}

int main () {
    int a, b;
    printf ("Enter the value of a : ");
    scanf ("%d", &a);
    printf ("Enter The value of b : ");
    scanf ("%d", &b);

    sawp(&a, &b);

    printf ("after sawp a = %d, b = %d", a, b);

    return 0;
}