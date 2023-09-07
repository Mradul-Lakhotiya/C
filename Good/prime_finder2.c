#include <stdio.h>

int main () {
    int x,flag = 0,i;

    printf ("Enter a number : ");
    scanf ("%d",&x);

    
    if (x==1) {
        printf ("%d is a not prime ",x);
    } 
    else {
    if (x==0) {
        printf ("%d is a not prime ",x);
    }
     else {
            if (x==2) {
                printf ("%d is a prime ",x);
            } 
            else {
                for (i=2;i<x;i++) {
                    if (x%i==0) {
                        flag = 1;
                    }
                }
            }
         }
    }

    if (flag = 0) {
    printf ("%d is a prime ",x);}
    else {
    printf ("%d  is not a prime",x);}

    return 0 ;
}