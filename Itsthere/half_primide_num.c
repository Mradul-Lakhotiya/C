#include <stdio.h>

int main () {
    int line;

    printf ("enterv the number of line : ");
    scanf ("%d",&line);

    for (int i = 1 ; i<=line ; i++) {
        for (int j = 1 ; j<=i ; j++) {
            printf ("%d ",j);
        }
        printf ("\n");
    }
}