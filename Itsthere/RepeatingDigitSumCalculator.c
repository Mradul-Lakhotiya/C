#include <stdio.h>

int main () {
    int toadd,x,sum=0;

    printf ("x + xx + xxx + xxxx + .. n Enter the value of n : ");
    scanf ("%d",&toadd);

    printf ("x + xx + xxx + xxxx + .. n Enter the value of x : ");
    scanf ("%d",&x);

    for (int i=0; i<=toadd ; i++) {
         sum = sum + x;
         x = x*10 + x;
    }
    printf ("Sum is %d",sum);
}