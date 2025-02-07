#include <stdio.h>
#include <string.h>

int main () {
    int j = 0;
    char alphabets[27]="abcdefghijklmnopqrstuvwxyz ";
    char to_print[100];

    printf ("Enter the string in lower case : ");
    scanf (" %[^\n]", to_print);

    char output[strlen(to_print) + 1];
    for (int i = 0; i < strlen(to_print); i++) {
        output[i] = ' ';
    }
    output[strlen(to_print)] = '\0';

    for (int i = 0; i <= 27; i++) {
        output[j] = alphabets[i];
        if (output[j] == to_print[j]  && j < strlen(to_print)) {
            j++;
            i = -1;
        }

        printf ("%s\n", output);

        if (strcmp(output, to_print) == 0) {
            break;
        }
    }
    return 0;
}