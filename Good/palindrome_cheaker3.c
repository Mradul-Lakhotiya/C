#include <stdio.h>

int main () {
    int num, temp, rnum=0, dnum;

    printf ("Enter the number : ");
    scanf ("%d",&num);

    dnum = num;

    do {
        temp = dnum % 10;
        rnum = rnum * 10 + temp;
        dnum /= 10;
    } while (dnum != 0);

    if (rnum==num) {
        printf ("%d is a Palindrome",num);
    } else {
        printf ("%d is not a Palindrome",num);
    }
}