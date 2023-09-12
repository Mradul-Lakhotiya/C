#include <stdio.h>

int main () {
    float side1, side2, side3, max;
    
    printf ("Enter the value of side 1 : ");
    scanf ("%f",&side1);

    printf ("Enter the value of side 2 : ");
    scanf ("%f",&side2);
    
    printf ("Enter the value of side 3 : ");
    scanf ("%f",&side3);

    if (side1==side2 && side2==side3) {
        printf ("Equilateral");
    }
    else if (side1==side2 || side1==side3 || side3==side2){
        printf ("Isosceles");
    }
    else {
        printf ("Scalene");
    }
}