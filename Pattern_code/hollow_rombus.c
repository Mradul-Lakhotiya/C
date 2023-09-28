#include <stdio.h>

int main () {
    int n;

    printf ("Enter the value of lines : ");
    scanf ("%d",&n);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=(n-i); j++) {
            printf ("  ");
        }
        for (int j=1; j<=n; j++) {
            if (j==1 || i==1 || i==n || j==n) {
                printf ("* ");
            } else {
                printf ("  ");
            }
        }            
        printf ("\n");
    }
}