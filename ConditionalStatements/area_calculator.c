#include <stdio.h>
#include <math.h> // Include the math library for M_PI

int main()
{
    float x, y;
    char A;

    printf("Select the object for which area needs to be calculated:\n");
    printf("Square = s\n");
    printf("Circle = c\n");
    printf("Rectangle = r\n");
    printf("Triangle = t\n");
    
    scanf("%c", &A);

    switch (A)
    {
        case 's':
            printf("Enter the length of the side of the square: ");
            scanf("%f", &x);
            printf("The area of the Square with sides %.2f will be %.2f\n", x, x * x);
            break;

        case 'c':
            printf("Enter the value of radius: ");
            scanf("%f", &x);
            printf("The area of the circle with radius %.2f will be %.2f\n", x, M_PI * x * x);
            break;

        case 'r':
            printf("Enter the value of length: ");
            scanf("%f", &x);
            printf("Enter the value of Breadth: ");
            scanf("%f", &y);
            printf("The area of the rectangle with length %.2f and breadth %.2f is %.2f\n", x, y, x * y);
            break;

        case 't':
            printf("Enter the length of base: ");
            scanf("%f", &x);
            printf("Enter the value of Height of the triangle: ");
            scanf("%f", &y);
            printf("The area of the triangle with base %.2f and height %.2f will be %.2f\n", x, y, 0.5 * x * y);
            break;

        default:
            printf("Please give a correct response\n");
            return 1; // Return a non-zero value to indicate an error
    }

    printf("Thanks for using this AREA CALCULATOR\n");
    return 0;
}
