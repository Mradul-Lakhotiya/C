#include <stdio.h>

int main () {
    int row, cols;

    printf ("Enter the no. of row : ");
    scanf ("%d",&row);

    for (int i=1; i<=row; i++) {
        for (int j=1; j<=(row-i); j++) {
            printf ("  ");
        }
        for (int k=i; k>=1; k--) {
            printf ("* ");
        }
        printf ("\n");
    }
}