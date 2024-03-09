// Implement a program to find the number of rabbits and chickens in a farm. 
// Given the number of heads and legs of the chickens and rabbits in a farm, 
// identify and display the number of chickens and rabbits in the farm.
// If the given input cannot make a valid number of rabbits and chickens, then display an appropriate message.

#include <stdio.h>
#include <stdlib.h>

int *numberOfRabbitsAndChickens(int heads, int legs) {
    int rabbits = 0;
    int chickens = 0;
    int *result = (int *)malloc(2 * sizeof(int));

    if (legs % 2 != 0) {
        return result;
    }
    rabbits = (legs - 2 * heads) / 2;
    chickens = heads - rabbits;
    if (rabbits < 0 || chickens < 0) {
        return result;
    }

    result[0] = chickens;
    result[1] = rabbits;
    return result;
}

int main () {
    int legs;
    int heads;
    printf("Enter the number of heads: ");
    scanf("%d", &heads);
    printf("Enter the number of legs: ");
    scanf("%d", &legs);
    
    int *result = numberOfRabbitsAndChickens(heads, legs);
    printf("Number of chickens: %d\n", result[0]);
    printf("Number of rabbits: %d\n", result[1]);
    return 0;
}