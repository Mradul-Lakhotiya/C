#include <stdio.h>

int main() {
    char arr[100];
    int i = 0;

    printf("Enter 'E' to exit\n");

    while (1) {
        printf("Enter the arr[%d] : ", i);
        scanf(" %c", &arr[i]);

        if (arr[i] == 'e' || arr[i] == 'E') 
            break;  // Exit the loop when 'e' or 'E' is entered
        
        i++;
    }

    printf("Number of elements entered: %d\n", i);

    return 0;
}