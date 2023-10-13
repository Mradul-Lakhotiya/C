#include <stdio.h>

int main () {
    int n;
    
    printf ("Enter the size of the array : ");
    scanf ("%d", &n);

    int arr[n], odd[n], even[n], oddc=0, evenc=0;

    for (int i=0; i<n; i++) {
        printf ("Enter arr[%d] : ", i);
        scanf ("%d", &arr[i]);
    }

    for (int i=0; i<n; i++) {
        if (arr[i]%2==0) {
            even[evenc]=arr[i];
            evenc++;
        } else {
            odd[oddc]=arr[i];
            oddc++;
        }
    }
    
    printf ("Even : ");
    for (int i=0; i<evenc; i++) {
        printf ("%d, ", even[i]);
    }

    printf ("\nOdd  : ");
    for (int i=0; i<oddc; i++) {
        printf ("%d, ", odd[i]);
    }

    return 0;
}