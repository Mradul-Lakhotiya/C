#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

void insert(int[], int);
int hash(int);
int probe(int[], int);
void printArr(int[]);
bool search(int[], int);

int main() {
    int arr[SIZE] = {0};
    insert(arr, 5);
    insert(arr, 25);
    insert(arr, 15);
    insert(arr, 35);
    insert(arr, 95);
    insert(arr, 75);
    
    printArr(arr);
}

int hash(int key) {
    return key%SIZE;
} 

int probe(int arr[], int key) {
    int index = hash(key);
    int i = 0;
    while(arr[(index+i*i)%SIZE] != 0) {
        i++;
    }
    return (index+i*i)%SIZE;
}

void insert(int arr[], int key) {
    int index = hash(key);
    if(arr[index] != 0) {
        index = probe(arr, key);
    }
    arr[index] = key;
} 

void printArr(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d, ", arr[i]);
    }
}

bool search(int arr[], int key) {
    int index = hash(key);
    int i = 0;
    while(arr[(index+i*i)%SIZE] != key) {
        i++;
        if(arr[(index+i*i)%SIZE] == 0) {
            return false;
        }
    }
    return true;
}