#include <stdio.h>

int main () {
    int n;

    printf ("Enter the number of lines : ");
    scanf ("%d",&n);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=2*n; j++) {
            if (j<=i || j>=2*n-i+1) {
                printf ("* ");
            } else {
                printf ("  ");
            } 
        }
        printf ("\n");
    }
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=2*n; j++) {
            if (j<=i || j>=2*n-i+1) {
                printf ("* ");
            } else {
                printf ("  ");
            } 
        }
        printf ("\n");
    }    
}