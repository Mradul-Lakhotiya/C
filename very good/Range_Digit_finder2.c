#include <stdio.h>

int main () {
    int to=0, from, key, n;

    printf ("Enter the from : ");
    scanf ("%d",&from);
    printf ("Enter the to : ");
    scanf ("%d",&to);
    printf ("Enter the key : ");
    scanf ("%d",&key);

    for (int i=from ; i<=to ; i++) {
        int temp = i;
        n=0;
        while (temp!=0) {
            temp /= 10;
            n++;
        }
        for (n ; n!=0 ; n++) {
            int digit = temp%10;
            if (digit=key) {
                printf ("%d ",i);
                break;
            }
            temp /= 10;
        }
    }
}