#include <stdio.h>

// Function to perform bubble sort using recursion
void bubble_sort(int arr[], int size, int i, int j) {
    if (i == size - 1) {
        return;
    }
    if (j < size - i - 1) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
        bubble_sort(arr, size, i, j + 1);
    } else {
        bubble_sort(arr, size, i + 1, 0);
    }
}

void freq_in_the_arr (int freq[], int number, int count) {
    freq[number-1] = count;
}

// Function to check frequency of elements in the sorted array using recursion
void freq_checker(int arr[], int size, int i, int count, int freq[]) {
    if (i == size) {
        return;
    }
    if (i < size - 1 && arr[i] == arr[i + 1]) {
        freq_checker(arr, size, i + 1, count + 1, freq);
    } else {
        // printf("%d comes %d times\n", arr[i], count + 1);
        freq_in_the_arr (freq, arr[i], count + 1);
        freq_checker(arr, size, i + 1, 0, freq);
    }
}

int main() {
    int size;
    printf("Enter the size of arr: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, size, 0, 0); // Call the bubble sort function with recursion
    int MAX = arr[size-1];

    int freq[MAX];
    for (int i = 0; i < MAX; i++) {
        freq[i] = 0;
    }

    freq_checker(arr, size, 0, 0, freq); // Call the frequency checker function with recursion

    for (int i = 0; i < MAX; i++) {
        printf ("%d comes %d times\n", i, freq[i]);
    }

    return 0;
}