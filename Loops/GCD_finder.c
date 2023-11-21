#include <stdio.h>

int main () {
    int a, b;

    printf ("Enter the value of a : ");
    scanf ("%d",&a);

    printf ("Enter the value of b : ");
    scanf ("%d",&b);

    while (a!=0) {
        int temp = a;
        a = b % a;
        b = temp;
    }
    
    printf ("The GCD will be %d",b);
}