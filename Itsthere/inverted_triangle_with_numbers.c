#include <stdio.h>

int main () {
    int n;

    printf ("Enter the no. of lines need to be printed : ");
    scanf ("%d",&n);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=(n+1-i); j++) {
            printf ("%d ",j);
        }
        printf ("\n");
    }
}