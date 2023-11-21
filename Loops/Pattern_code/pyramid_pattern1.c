#include <stdio.h>

int main () {
    int n;

    printf ("Enter the value of n (the no. till You waht the parimide) : ");
    scanf ("%d",&n);

    for (int i = 1 ; i <= n ; i ++) {
        printf ("\n");
        for (int x = i ; x != 0 ; --x ) {
            printf ("%d",i);
        }
    }
}