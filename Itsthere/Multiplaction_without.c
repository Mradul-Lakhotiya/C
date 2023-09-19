#include <stdio.h>

int main () {
    int a, b, sum=0;

    printf ("Enter the first number : ");
    scanf ("%d",&a);

    printf ("Enter the second number : ");
    scanf ("%d",&b);

    for (int i=1 ; i<=b ; i++) {
        sum += a;
    }
    
    printf ("The multiplation of %d and %d is %d",a,b,sum);
}