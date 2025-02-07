#include <stdio.h>

int main () {
    char x;

    printf ("enter a letter : ");
    scanf (" %c",&x);

    switch (x)
    {
    case 'a':
        printf ("%c is a voval",x);
        break;
    
    case 'e':
        printf ("%c is a voval",x);
        break;

    
    case 'i':
        printf ("%c is a voval",x);
        break;
    
    
    case 'o':
        printf ("%c is a voval",x);
        break;
    
    
    case 'u':
        printf ("%c is a voval",x);
        break;
    
    default:
    printf ("%c is not a voval",x);
        break;
    }
    return 0 ;
}