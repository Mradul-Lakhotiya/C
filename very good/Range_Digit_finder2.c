#include <stdio.h>

int main () {
    int end_range = 0, from, key, n, count = 0;

    printf ("Enter the from : ");
    scanf ("%d", &from);
    printf ("Enter the to : ");
    scanf ("%d", &end_range);
    printf ("Enter the key : ");
    scanf ("%d", &key);

    for (int i = from; i <= end_range; i++) {
        int temp = i;
        n = 0;
        while (temp != 0) {
            temp /= 10;
            n++;
        }
        temp = i;
        for (int tn = n; tn >= 1; tn--) {
            int digit = temp % 10;
            if (digit == key) {
                printf ("%d ", i);
                count++;
                temp /= 10;
                break;
            }
            temp /= 10;
        }
    }
    printf ("\nThe numbers containing %d are %d", key, count);
}
