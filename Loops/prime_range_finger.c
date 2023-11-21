#include <stdio.h>

int main () {
    int to, temp =0;

    printf  ("Enter the to Value : ");
    scanf ("%d",&to);

    for (int i = 2 ; i<=to ; i++) {
        int flag = 1;
        for (temp = 2 ; temp < i ; temp++) {
            if (i%temp == 0) {
                flag = 0;
                break;
            }
        } 
        if (flag==1) {
            printf ("%d,",i);
        }
    }

}