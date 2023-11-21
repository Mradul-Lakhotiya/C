#include <stdio.h>
#include <math.h>

int main () {
    float a, b, c, D, x1, x2;

    printf ("ax^2 + bx + c");
    printf ("\nEnter the value of a : ");
    scanf ("%f",&a);
    printf ("\nEnter the value of b : ");
    scanf ("%f",&b);
    printf ("\nEnter the value of c : ");
    scanf ("%f",&c);

    if (b*b < 4*a*c) {
        printf ("roots are not real");
    }
    else {
        D = sqrt(b*b - 4*a*c);
        x1 = (-b + D)/2*a;
        x2 = (-b - D)/2*a;

        printf ("roots are %.3f and %.3f",x1,x2);
    }
}