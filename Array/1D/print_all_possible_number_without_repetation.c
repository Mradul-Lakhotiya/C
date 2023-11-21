#include <stdio.h>

int main () {
    int num[4], i, j, k , countnum[6], n;
    
    printf ("Enter the 3 dgit Number : ");
    scanf ("%d",&num[0]);

    num[1]=num[0]%10;
    num[0]=num[0]/10;
    num[2]=num[0]%10;
    num[0]=num[0]/10;
    num[3]=num[0];

    n=0;
    for (i=0;i!=3;i++) {
        for (j=0;j!=3;j++) {
            for (k=0;k!=3;k++) {
                if (i!=k && i!=j && j!=k) {
                    countnum[n]= num[i]*100 + num[k]*10 + num[j];
                    n++;
                }
            }
        }
    }
    for (n=0; n<6 ; n++) {
        if (countnum[n]!=countnum[n+1] && countnum[n]!=countnum[n+3] && countnum[n]!=countnum[n+5]) {
            printf ("%d\n",countnum[n]);
        }
    }
}