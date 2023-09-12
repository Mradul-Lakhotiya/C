#include <stdio.h>

int main () {
    int to, from, find, i, count=0, ahi, ati;

    printf ("Enter the to Number : ");
    scanf ("%d",&to);// end of range

    printf ("Enter the from Number : ");
    scanf ("%d",&from); // starting of range

    printf ("Enter the Nunber which you want ot find : ");
    scanf ("%d",&find);// the no. which u want to find

    for(i = from ; i <= to ; i++) {
        if (i<10) {
            if (i==find) {
                printf ("%d\t",i);
                count++;
            }//cheaking for the 1th place
        }
        if (10<i && i<100) {
            if ((int)i/10 == find || i%10 == find) {
                printf ("%d\t",i);
                count++;
            }//cheaking for the 10th place
        }
        if (100<i && i<1000) {

            ahi = i % 100;

            if ((int)i/100 == find || (int)ahi/10 == find || ahi%10 == find) {
                printf ("%d\t",i);
                count++;
            }//cheaking for the 100th place
        }
        if (1000<i && i<10000) {

            ati = i % 1000;
            ahi = i % 100;

            if ((int)i/1000 == find || (int)ati/100 == find || ati%100 == find || (int)ahi/10 == find || ahi%10 == find) {
                printf ("%d\t",i);
                count++;
            }//cheaking for the 1000th place
        }
    }
    printf ("\nThe Total Number of Numbers comtaing %d from %d to %d is %d",find,from,to,count);
}