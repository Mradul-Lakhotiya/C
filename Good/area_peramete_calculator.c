#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    float x, y, z, S;
    char A, ch;
    do {
        printf ("\n1.area(a)\n2.parametre(p)\n3.end(e)\n");
        scanf ("  %c",&ch);

        switch (ch)
        {
        case 'a' :

            printf("Select the object for which area needs to be calculated:\n");
            printf("Square = s\n");
            printf("Circle = c\n");
            printf("Rectangle = r\n");
            printf("Triangle = t\n");
    
            scanf(" %c", &A);

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
                    printf("Enter the length of first side : ");
                    scanf("%f", &x);
                    printf("Enter the lemgth of second side : ");
                    scanf("%f", &y);
                    printf("Enter the lemgth of thired side : ");
                    scanf("%f", &z);
                    S=(x+y+z/2);
                    printf("The area of the triangle with be %.2f", sqrt(S * (S - x) * (S - y) * (S - z)));
                    break;

                default:
                    printf("Please give a correct response\n");
                    break;
            }
            break;
        case 'p' :

                printf("Select the object for which parameter needs to be calculated:\n");
                printf("Square = s\n");
                printf("Circle = c\n");
                printf("Rectangle = r\n");
                printf("Triangle = t\n");
            
                scanf(" %c", &A);

            switch (A)
            {
                case 's':
                    printf("Enter the length of the side of the square: ");
                    scanf("%f", &x);
                    printf("The parameter of the Square with sides %.2f will be %.2f\n", x, 4*x);
                    break;

                case 'c':
                    printf("Enter the value of radius: ");
                    scanf("%f", &x);
                    printf("The parameter of the circle with radius %.2f will be %.2f\n", x, 2*M_PI*x);
                    break;

                case 'r':
                    printf("Enter the value of length: ");
                    scanf("%f", &x);
                    printf("Enter the value of Breadth: ");
                    scanf("%f", &y);
                    printf("The parameter of the rectangle with length %.2f and breadth %.2f is %.2f\n", x, y, 2*(x+y));
                    break;

                case 't':
                    printf("Enter the length of first side : ");
                    scanf("%f", &x);
                    printf("Enter the lemgth of second side : ");
                    scanf("%f", &y);
                    printf("Enter the lemgth of thired side : ");
                    scanf("%f", &z);
                    printf("The parameter of the triangle with be %.2f", x+y+z);
                    break;

                default:
                    printf("Please give a correct response\n");
                    break;
            }
            break;
            
        case 'e':     
            break;

        default : 
            printf ("Give a valid input");
            break;
        } 
    }while (ch!='e'); {
        printf ("Thanks for using the calculatror");
        }
}
