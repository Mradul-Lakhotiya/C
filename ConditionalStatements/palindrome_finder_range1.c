#include <stdio.h>

int main () {
    int num[5], till;

    printf ("Enter the value till u want the palindrome : ");
    scanf ("%d",&till);
    printf ("Enter the value from u want the palindrome : ");
    scanf ("%d",&num[0]);

    for (num[0];num[0]<=till;num[0]++) {
        if ( 10<num[0] && num[0]<100) {
            num[1]=(int)num[0]/10;
            num[2]=num[0]%10;

            if (num[1]==num[2]) {
                printf ("%d\t",num[0]);
            }
        }
        else if (100<num[0] && num[0]<1000) {
            num[1]=(int)num[0]/100;
            num[3]=num[0]%10;

            if (num[1]==num[3]) {
                printf ("%d\t",num[0]);
            }
        }
        else if (1000<num[0] && num[0]<10000) {
            num[1]=(int)num[0]/1000;
            num[2]=(int)(num[0]%1000)/100;
            num[3]=(int)((num[0]%1000)%100)/10;
            num[4]=((num[0]%1000)%100)%10;

            if (num[1]==num[4] && num[2]==num[3]) {
                printf ("%d\t",num[0]);
            } 
        }
    }
}