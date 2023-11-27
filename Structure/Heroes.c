/*
Define a structure Superheroes with fields for name, 
superpower and universe(Marvel/DC). Write a program 
to input 5 superheroes from user and display the 
details of those superheroes whose universe the user 
inputs (Marvel OR DC).
*/

#include <stdio.h>

struct Superheroes {
    char fields_name[50];
    char name[50];
    char superpower[50];
    char Universe[6];
} Heroes[5];


int main () {
    for (int i = 0; i < 5; i++) {
        printf ("--------------------------------\n");
        printf ("Enter Field name : ");
        scanf ("%s", Heroes[i].fields_name);
        printf ("Enter the name : ");
        scanf ("%s", Heroes[i].name);
        printf ("Enter superpwer : ");
        scanf ("%s", Heroes[i].superpower);
        printf ("Enter the universe : ");
        scanf ("%s", Heroes[i].Universe);
    }
    for (int i = 0; i < 5; i++) {
        printf ("-------------------------------\n");
        printf ("field name : %s\n", Heroes[i].fields_name);
        printf ("name : %s\n", Heroes[i].name);
        printf ("Superpower : %s\n", Heroes[i].superpower);
        printf ("universe : %s\n", Heroes[i].Universe);
    }
    
    return 0;
}