#include <stdio.h>

int main () {

    int a = 0, b = 1,x ,y ;

    printf ("The Number you want in the Fibonacci series : ");
    scanf ("%d",&x);
    printf ("%d\n%d\n",a,b);

    while ( (x -2) > 0) {
        y = a + b;
        printf ("%d \n",y);
        a = b;
        b = y; 
        x--;
    }
    return 0;
}