#include <stdio.h>

int main () {
    int n;

    printf ("Enter a number : ");
    scanf ("%d",&n);

    for (int n1=0 ; n1!=n; n1++) {
        for (int i=0 ; i!=n ; i++) {
            printf ("* ");
        }
        printf ("\n");
    }
}