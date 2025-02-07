#include <stdio.h>

int main () {
    int num[5];

    printf ("Enter a number : ");
    scanf ("%d",&num[0]);

    if ( 10<num[0] && num[0]<100) {
        num[1]=(int)num[0]/10;
        num[2]=num[0]%10;

        if (num[1]==num[2]) {
            printf ("%d is a palindrome",num[0]);
        }
    }
    else if (100<num[0] && num[0]<1000) {
        num[1]=(int)num[0]/100;
        num[3]=num[0]%10;

        if (num[1]==num[3]) {
            printf ("%d is a palindrome",num[0]);
        }
    }
    else if (1000<num[0] && num[0]<10000) {
        num[1]=(int)num[0]/1000;
        num[2]=(int)(num[0]%1000)/100;
        num[3]=(int)((num[0]%1000)%100)/10;
        num[4]=((num[0]%1000)%100)%10;

        if (num[1]==num[4] && num[2]==num[3]) {
            printf ("%d is a palindrome",num[0]);
        }
    }
    else {
        printf ("%d is a not palindrome",num[0]);
    }
}