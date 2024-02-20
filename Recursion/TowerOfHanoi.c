#include <stdio.h> 

void towerOfHanoi(int n, char source, char helper, char dest) {
    if (n == 1) {
        printf("%c -> %c | ", source, dest);
    } 
    else {
        towerOfHanoi(n - 1, source, dest, helper);
        printf("%c -> %c | ", source, dest);
        towerOfHanoi(n - 1, helper, source, dest);
    }
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}