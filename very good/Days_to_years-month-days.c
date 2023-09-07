#include <stdio.h>

int main () {
    float months,years;
    int days,temp;

    printf ("Enter the numbers of days :");
    scanf ("%d",&days);

    printf ("\nThe Number of Days %d can be written as",days);

    years = days/365;
    months = (days % 365)/30;
    days = (days % 365) % 30;

    printf ("\n%d Years \n%d Months \n%d Days\n\n",(int)years,(int)months,days);

    return 0;
}