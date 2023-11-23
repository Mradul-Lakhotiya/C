#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf ("Enter the size of arr : ");
    scanf ("%d", &n);

    int* arr = (int*)malloc(n*sizeof(int));

    if (arr == NULL) {
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        printf ("arr[%d] : ", i);
        scanf ("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf ("%d, ", arr[i]);
    }

	return 0;
}