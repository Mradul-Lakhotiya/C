#include <stdio.h>

int main() {
    int n, place, num;
    
    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n + 1];

    // Input array elements
    for (int i = 0; i < n; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    // Input number and place to insert
    printf("The number to be inserted: ");
    scanf("%d", &num);
    printf("The place to insert it in: ");
    scanf("%d", &place);
    
    // Shift elements and insert the number
    for (int i = n; i >= place; i--)
        arr[i] = arr[i - 1];
    arr[place - 1] = num;

    // Display the updated array
    printf("Updated array: ");
    for (int i = 0; i <= n; i++)
        printf("%d, ", arr[i]);

    return 0;
}
