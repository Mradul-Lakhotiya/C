#include <stdio.h>

int main () {
    int n, num=1;

    printf ("Enter the no. of lines need to be printed : ");
    scanf ("%d",&n);

    for (int i=1; i<=n; i++) {
        for (int j=i; j>=1; j--) {
            printf ("%d ",num);
            num++;
        }
        printf ("\n");
    }
}