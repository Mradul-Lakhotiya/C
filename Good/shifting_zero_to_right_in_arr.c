#include <stdio.h>

int main () {
    int n, count=0;

    printf ("Enter the size of arr : ");
    scanf ("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++) {
        printf ("arr[%d] : ", i);
        scanf ("%d", &arr[i]);
    }

    for (int i=0; i<n; i++) {
        if (arr[i]==0) {
            count++;
        }
    }

    int index =0;
    for (int i=0; i<n; i++) {
        if (arr[i]!=0) {
            arr[index++]=arr[i];
        }
    }

    for (int i=index; i<n; i++) {
        arr[i]=0;
    }

    for (int i=0; i<n; i++) {
        printf ("%d", arr[i]);
    }

    return 0;
}