#include <stdio.h>
#include <stdlib.h>

int piramide ();
int number_triangle();

int piramide () {
    int n;
    
    printf ("Enter the number of lines to be printed : ");
    scanf ("%d",&n);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=(n-i); j++) {
            printf ("  ");
        }
        for (int j=1; j<=i; j++) {
            printf ("* ");
        }
        for (int j=i; j>1; j--) {
            printf ("* ");
        }
        printf ("\n");     
    }
}

int number_triangle () {
    int n;
    
    printf ("Enter the number of lines to be printed : ");
    scanf ("%d",&n);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            printf ("%d ",i);
        }
        printf ("\n");
    }
}

int main () {
    int print;
    do {
        printf ("\n\t1\n\t22\n  (1)   333\n\t4444\n\tnn....n\n");
        printf ("\n\t    *\n\t   ***\n  (2)     *****\n\t *******\n\t*********\n");
        printf ("\n  (3)    EXIT");
        printf ("\n\n\tWhich pattern you want to print : ");
        scanf ("%d",&print);

        switch (print) {
            case 1:
                number_triangle ();
                break;
            
            case 2:
                piramide ();
                break;
            
            case 3:
                printf ("Exiting The Printer.....10%%.....59%%.......99%%");
                break;

            default :
                printf ("\tEnter a valid inupt");
                break;
        } 
    } while (print!=3);

}