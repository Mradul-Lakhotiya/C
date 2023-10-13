#include <stdio.h>

int main () {
    int n;
    
    printf ("Enter the size of the array : ");
    scanf ("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++) {
        printf ("Enter arr[%d] : ", i);
        scanf ("%d", &arr[i]);
    }

    int mx = arr[0];
    int mn = arr[0];

    for(int i=1; i<n; i++)
    {
        if(arr[i]>mx)
        {
            mx = arr[i];
        }

        if(arr[i]<mn)
        {
            mn = arr[i];
        }
    }

    printf ("The Max no. is : %d\n", mx);
    printf ("The Min no. is : %d", mn);

    return 0;
}