#include <stdio.h>

int main () {
    int x=0, n=0, i=0, last, dx, ox=0, from, to;

    printf ("Enter the lower limit : ");
    scanf ("%d",&from);
    printf ("Enter the upper limit : ");
    scanf ("%d",&to);

    while (from<to) {
        n = 0;
        for (dx=x;dx!=0;n++) {
            dx = (int)dx/10;
        }
        dx = x;
        ox = 0;
        while (n!=0) {
            last = dx%10;
            dx=(int)dx/10;
            ox = ox*10 + last;
            n--;
        }
        if (ox==x) {
            printf (" %d ",x);
        }
        x++;
        to--;
    }
}