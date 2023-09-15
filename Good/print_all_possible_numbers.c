#include <stdio.h>

int main () {
    int num[4], i, j, k;
    
    printf ("Enter the 3 dgit Number : ");
    scanf ("%d",&num[0]);

    num[1]=num[0]%10;
    num[0]=num[0]/10;
    num[2]=num[0]%10;
    num[0]=num[0]/10;
    num[3]=num[0];

    printf ("%d,%d,%d",num[3],num[2],num[1]);

    for (i=0;i!=3;i++) {
        for (j=0;j!=3;j++) {
            for (k=0;k!=3;k++) {
                if (i!=k && i!=j && j!=k) {
                    printf ("%d%d%d",num[i],num[j],num[k]);
                }
            }
        }
    }
}