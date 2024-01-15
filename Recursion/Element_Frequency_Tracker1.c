#include <stdio.h>
#include <stdlib.h>

void bubble_sort (int n, int arr[]) {
    if (n<=1) {
        return;
    } 
    for (int i=0; i<n-1; i++) {
        if (arr[i]>arr[i+1]) {
            int temp = arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    bubble_sort (n-1,arr);
}

void counter (int count, int arr[], int n, int i) {

    if (i>=n) {
        return;
    }
    for (int j=0; j<=n; j++) {
        if (arr[i]==arr[j]) {
            count ++;
        }
    }
    printf ("%d comes %d times\n",arr[i],count);
    counter (0,arr,n,i+count);
}

int main () {
    int n;

    printf ("Entre the size of array : ");
    scanf ("%d",&n);

    int arr[n], count=0;

    for (int i=0; i<n; i++) {
        printf ("Enter the value of arr[%d] : ",i);
        scanf ("%d",&arr[i]);
    }

    bubble_sort (n,arr);
    counter (count, arr, n, 0);
}