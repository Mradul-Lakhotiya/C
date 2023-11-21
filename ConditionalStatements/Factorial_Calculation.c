#include <stdio.h>
 
 int main () 
 {
    int x, i = 1,f = 1;

    printf ("Enter a number : ");
    scanf ("%d",&x);

    if (x != 0) {
         while (i <= x) {
        f = i * f;
        i++;
        }
    }
    printf ("Factorial of %d is %d" ,x,f);
    
    return 0 ;
 }