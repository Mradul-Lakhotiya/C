#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int arr[3] = {1, 1, 3};
    int res[6] = {0};
    bool flag = false;
    int m = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j && j != k && k != i)
                    res[m++] = arr[i]*100 + arr[j]*10 + arr[k]; 
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        flag = 0;
        for (int j = i+1; j < 6; j++) {
            if (res[i] == res[j]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("%d ", res[i]);
        }
    }
}