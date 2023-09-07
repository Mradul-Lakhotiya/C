#include <stdio.h>

int main() {
    int x, y, s = 0; // This code will include the numbers provided in the sum if they are even

    printf("Enter from number: "); // to make the number even
    scanf("%d", &x);

    if (x % 2 == 1) {
        x++;
    }

    printf("Enter to number: "); // to make the number even
    scanf("%d", &y);

    if (y % 2 == 1) {
        y--;
    }

    while (x <= y) {
        s += x;
        x += 2; // now the number is even, so we can just add it by 2 to get the sum of all the even numbers in between
    }

    printf("The sum of all the even numbers between the two provided numbers will be %d\n", s);

    return 0;
}