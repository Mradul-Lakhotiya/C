#include <stdio.h>

int main () {
    int n;

    printf ("Enter the value of lines : ");
    scanf ("%d",&n);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=(n-i); j++) {
            printf ("  ");
        }
        for (int j=1; j<=(2*i-1); j++) {
            if (i%2==0) {
                if ((i+j)%2==0) {
                    printf ("  ");
                } else {
                    printf ("%d ",i);
                }
            } else {
                if ((i+j)%2!=0) {
                    printf ("  ");
                } else {
                    printf ("%d ",i);
                }
            }
        }      
        printf ("\n");
    }
}