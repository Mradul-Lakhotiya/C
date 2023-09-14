#include <stdio.h>

int main () {
    int x, n=0, i=0, last, dx, ox=0;

    printf ("Enter a number : ");
    scanf ("%d",&x);

    for (dx=x;dx!=0;n++) {
        dx = (int)dx/10;
    }
    dx = x;
    while (n!=0) {
        last = dx%10;
        dx=(int)dx/10;
        ox = ox*10 + last;
        n--;
    }
    if (ox==x) {
        printf ("%d is a palindrome",x);
    } else {
        printf ("%d is not a palindrome",x);
    }
}