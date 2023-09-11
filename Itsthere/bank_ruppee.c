#include <stdio.h>

int main () {
    int x,i;

    printf ("Enter The Amount : ");
    scanf ("%d",&x);

    i = x/2000;
    printf ("2000 * %d \n",(int)i);
    i = (x%2000)/500;
    printf ("500 * %d \n",(int)i);
    i = ((x%2000)%500)/100;
    printf ("100 * %d \n",(int)i);
    i = (((x%2000)%500)%100)/50;
    printf ("50 * %d \n",(int)i);
    i = ((((x%2000)%500)%100)%50)/20;
    printf ("20 * %d \n",(int)i);
    i = (((((x%2000)%500)%100)%50)%20)/10;
    printf ("10 * %d \n",(int)i);
    i = ((((((x%2000)%500)%100)%50)%20)%10)/5;
    printf ("5 * %d \n",(int)i);
    i = (((((((x%2000)%500)%100)%50)%20)%10)%5)/2;
    printf ("2 * %d \n",(int)i);
    i = ((((((((x%2000)%500)%100)%50)%20)%10)%5)%2);
    printf ("1 * %d \n",(int)i);
}