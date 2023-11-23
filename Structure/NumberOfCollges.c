#include <stdio.h>
#define MAX 100

struct CollageDetiles {
    int NumberOfStu;
    int AreaCovred;

    struct StudentDetiles {
        char name[25];
        int SAP;
    }Student[MAX];
};

int main () {
    int NumberOfCollges;
    int choise;

    printf ("Enter the number of Collages : ");
    scanf ("%d", &NumberOfCollges);

    struct CollageDetiles Collage[NumberOfCollges];
    
    for (int i = 0; i < NumberOfCollges; i++) { // detile sof collage

        printf ("Student in Collage[%d] : ", i+1);
        scanf ("%d", &Collage[i].NumberOfStu);

        printf ("Area of Collage[%d] : ", i+1);
        scanf ("%d", &Collage[i].AreaCovred);

        for (int j = 0; j < Collage[i].NumberOfStu; j++) { // scaning the detile of stu
            printf ("Enter the name of Stu %d : ", j+1);
            scanf ("%s", Collage[i].Student[j].name);
            printf ("Enter the SAP %d : ", j+1);
            scanf ("%d", &Collage[i].Student[j].SAP);
        }
    }

    printf ("Sort by? \n Area '1'\n No. stu '2' \nOption : "); // choise
    scanf ("%d", &choise);

    switch (choise)
    {
    case 1:
        for (int i = 0; i < NumberOfCollges - 1; i++) { // using selection sort
            int min_index = i;
            for (int j = i + 1; j < NumberOfCollges; j++) {
                if (Collage[j].AreaCovred < Collage[min_index].AreaCovred) {
                    min_index = j;
                }
            }
            struct CollageDetiles temp = Collage[min_index];
            Collage[min_index] = Collage[i];
            Collage[i] = temp;
        }
        // printing the sorted detiles
        printf("Sorted list ------------------------------------------\n");
        for (int i = 0; i < NumberOfCollges; i++) {
            printf ("Collage[%d]\n", i+1);
            printf ("No. of stu : %d\n", Collage[i].NumberOfStu);
            printf ("Area : %d\n", Collage[i].AreaCovred);
            printf ("---------------------------------------------------\n");
        }
        break;

    case 2:
        for (int i = 0; i < NumberOfCollges - 1; i++) { // using selection sort
            int min_index = i;
            for (int j = i + 1; j < NumberOfCollges; j++) {
                if (Collage[j].NumberOfStu < Collage[min_index].NumberOfStu) {
                    min_index = j;
                }
            }
            struct CollageDetiles temp = Collage[min_index];
            Collage[min_index] = Collage[i];
            Collage[i] = temp;
        }
        // printing the sorted detiles
        printf("Sorted list ------------------------------------------\n");
        for (int i = 0; i < NumberOfCollges; i++) {
            printf ("Collage[%d]\n", i+1);
            printf ("No. of stu : %d\n", Collage[i].NumberOfStu);
            printf ("Area : %d\n", Collage[i].AreaCovred);
            printf ("---------------------------------------------------\n");
        }
        break;
    
    default:
        printf ("Error");
        break;
    }
}