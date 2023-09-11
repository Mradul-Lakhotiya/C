#include <stdio.h>

int main () {
    float months,years,weeks;
    int days,temp,i;

    printf ("Enter the numbers of days : ");
    scanf ("%d",&days);

    printf ("\nThe Number of Days %d can be written as",days);

    years = days/365;
    i = days%365;
    months = i/30;
    i %= 30;
    weeks = i/ 7;
    i %= 7;
    days = i;

    printf ("\n%d Years \n%d Months \n%d Weeks\n%d Days\n\n",(int)years,(int)months,(int)weeks,days);

    return 0;
}