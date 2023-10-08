#include <stdio.h>

void revers_finder (int on, int temp) {
    if (temp==0) {
        printf ("%d\n",on);
        return;
    }
    revers_finder(10*on + temp%10, temp/10);
}

int main () {
    int n;

    printf ("Enter the number : ");
    scanf ("%d",&n);
    revers_finder(n%10, n/10);
    
    return 0;
}