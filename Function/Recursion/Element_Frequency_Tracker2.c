#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort on the array
void performBubbleSort(int n, int arr[]) {
    if (n <= 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Recursive call to sort the remaining elements
    performBubbleSort(n - 1, arr);
}

// Function to count the occurrences of a specific element in the array
int countOccurrences(int currentIndex, int n, int arr[], int targetIndex, int count) {
    if (currentIndex >= n) {
        return count;
    }

    if (arr[targetIndex] == arr[currentIndex]) {
        count++;
        countOccurrences(currentIndex + 1, n, arr, targetIndex, count);
    } else {
        return count;
    }
}

// Function to count occurrences of each element and display the count
void displayElementCounts(int count, int arr[], int n, int currentIndex) {
    if (currentIndex >= n) {
        return;
    }

    count = countOccurrences(currentIndex, n, arr, currentIndex, 0);
    printf("%d occurs %d times\n", arr[currentIndex], count);
    
    // Recursive call to process the next unique element
    displayElementCounts(0, arr, n, currentIndex + count);
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n], count = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter the value of arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Sort the array using bubble sort
    performBubbleSort(n, arr);

    // Count occurrences and display the count for each element
    displayElementCounts(count, arr, n, 0);

    return 0;
}