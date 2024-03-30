#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int pop(long long int *arr, int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return arr[(*top)--];
}

void push(long long int *arr, long long int data, int *top, int N) {
    if (*top == N - 1) {
        printf("Stack is full\n");
        return;
    }
    arr[++(*top)] = data;
}

void print(long long int *arr, int top) {
    for (int i = 0; i <= top; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

long long int solution(long long int *arr, int N, int K, int *top) {
    if (K == 0) {
        return -1;
    }
    int max = pop(arr, top);

    while (K > 1) {
        int max2 = pop(arr, top);
        if (max > max2) {
            push(arr, max2, top, N);
        }
        else if (max2 > max) {
            max = max2;
        }
        K--;
    }

    return max;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    long long int *arr = (long long int *)malloc(N * sizeof(long long int));

    int top = 0;
    char str[2*N - 1];
    scanf("%s", str);

    for (int i = strlen(str) - 1; i >= 0 ; i--) {
        arr[top++] = (int)(str[i--] - '0');
    }
    printf("%lld\n", solution(arr, N, K, &top));

    free(arr);
    return 0;
}
