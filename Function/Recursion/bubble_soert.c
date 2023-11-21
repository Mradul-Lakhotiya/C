#include <stdio.h>

void bubble_sort(int arr[], int n) {
    if (n == 1) {
        return;
    } 
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubble_sort(arr, --n);
}

int main() {
    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d,", arr[i]);
    }

    return 0;
}
