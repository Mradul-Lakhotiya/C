#include <stdio.h>
#include <math.h>

int main () {
    int num, n=0, sum=0, digite;

    printf ("Enter a Number in octal from : ");
    scanf ("%d",&num);

    int dnum = num;

    while (dnum!=0) {
        dnum /= 10;
        n++;
    }
    dnum = num;
    for (int i=0; i<n; i++) {
        digite = dnum%10;
        sum = sum + digite*pow(8, i);
        dnum /= 10;
    }
    printf ("%d",sum);
}