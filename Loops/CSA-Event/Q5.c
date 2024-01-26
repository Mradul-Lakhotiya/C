#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Check if the sentence is Pangram.
// A Pangram is a sentence where every letter of the English alphabet appears at least once.

bool checkIfPangram(const char *sentence)
{
    // Write Your Code Here
    int arr[128] = {0};

    for (int i = 0; i < strlen(sentence); i++) {
        arr[(int)*(sentence + i)]++;
    }

    for (int i = 'a'; i <= 'z'; i++) {
        if (arr[i] == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    // Test Case 1
    const char *sentence1 = "thequickbrownfoxjumpsoverthelazydog";
    printf("Test Case 1: %s\n", checkIfPangram(sentence1) ? "true" : "false");

    // Test Case 2
    const char *sentence2 = "thequickbrownfoxjumpsoverthelazyg";
    printf("Test Case 2: %s\n", checkIfPangram(sentence2) ? "true" : "false");

    // Test Case 3
    const char *sentence3 = "";
    printf("Test Case 3: %s\n", checkIfPangram(sentence3) ? "true" : "false");

    // Test Case 4
    const char *sentence4 = "a1";
    printf("Test Case 4: %s\n", checkIfPangram(sentence4) ? "true" : "false");

    // Test Case 5
    const char *sentence5 = "abcdefghijklmnopqrstuvwxyz";
    printf("Test Case 5: %s\n", checkIfPangram(sentence5) ? "true" : "false");

    return 0;
}