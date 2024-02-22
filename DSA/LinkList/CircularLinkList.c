#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

void displayChoice();

void insertAtBeginning(struct node **last_ptr, int data);
void viewList(struct node **last_ptr);
void insertAtEnd(struct node **last_ptr, int data);
void insertBeforeGivenNode(struct node **last_ptr, int data, int position);
void insertAfterGivenNode(struct node **last_ptr, int data, int position);
void deleteNodeAtBeginning(struct node **last_ptr);
void deleteNodeAtEnd(struct node **last_ptr);
void deleteGivenNode(struct node **last_ptr, int position); 
void deleteAfterGivenNode(struct node **last_ptr, int position);
void RemoveDuplicates(struct node **last_ptr); 
void sortBubble(struct node **last_ptr);
void reverseList(struct node **last_ptr);
void deleteList(struct node **last_ptr, bool showMsg);
void deleteByValue(struct node **last_ptr, int data);
void userInput(struct node **last_ptr);

struct node *mergeTwoCircularLists(struct node **last_ptr1, struct node **last_ptr2);

int numberOfNodes(struct node **last_ptr);
int sumOfAllTheElement(struct node **last_ptr);
int maxInList(struct node **last_ptr);
int minInList(struct node **last_ptr);
int searchInList(struct node **last_ptr, int data);

bool containsDuplicates(struct node **last_ptr);


int main (int argc, char const *argv[]) {

    displayChoice();

    return 0;
}

void displayChoice() {
    struct node *last = NULL;
    struct node **last_ptr = &last;

    struct node *last2 = NULL;
    struct node **last_ptr2 = &last;

    int choice, data;
    int length, sum, max, min; 
    int position = 0;
    bool containsDuplicate;

    do {
        printf("\n----------------------------------------\n");
        printf("              MENU OPTIONS\n");
        printf("----------------------------------------\n");
        printf(" 1. Insert at Beginning\n");
        printf(" 2. Insert in last\n");
        printf(" 3. View List\n");
        printf(" 4. Find The Number of Nodes\n");
        printf(" 5. Find the sum of all the Element\n");
        printf(" 6. Find Max and Min\n");
        printf(" 7. Search in list\n");
        printf(" 8. Insert Befor a Given Node\n");
        printf(" 9. Insert After a Given Node\n");
        printf("10. Delete a Node at Beginning\n");
        printf("11. Delete a Node at End\n");
        printf("12. Delete A give node\n");
        printf("13. Delete a node after the given node\n");
        printf("14. Delete By Value\n");
        printf("15. Does it Contains Duplicate\n");
        printf("16. Remove Duplicate\n");
        printf("17. Sort The List\n");
        printf("18. Revers The list\n"); // 
        printf("19. Create another List and Merge\n"); // 
        printf("20. Delete The list\n");
        printf("21. Mass Value Entre\n");
        printf(" 0. Exit\n");
        printf("----------------------------------------\n");
        printf("    Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                deleteList(last_ptr, false);
                printf("\nExiting........39%%....57%%...99%%.\n");
                break;

            case 1:
                printf("Entre the Value To Add : ");
                scanf("%d", &data);

                insertAtBeginning(last_ptr, data);
                break;

            case 2:
                printf("Entre the Value To Add : ");
                scanf("%d", &data);

                insertAtEnd(last_ptr, data);
                break;
            
            case 3:
                viewList(last_ptr);
                break;

            case 4:
                length = numberOfNodes(last_ptr);

                printf("\nThe length of List is %d\n", length);
                break;

            case 5:
                sum = sumOfAllTheElement(last_ptr);

                printf("\nThe Sum of all the Element in the list will be : %d", sum);
                break;
            
            case 6:
                max = maxInList(last_ptr);
                min = minInList(last_ptr);

                printf("\n\t\tmax = %d\n\t\tmin = %d", max, min);
                break;

            case 7:
                printf("Entre the number to find : ");
                scanf("%d", &data);

                position = searchInList(last_ptr, data);
                printf("\nThe %d is at %d position\n", data, position);
                break;

            case 8:
                printf("Entre the Value To Add : ");
                scanf("%d", &data);
                printf("Entre the postion of add it before : ");
                scanf("%d", &position);   
                      
                insertBeforeGivenNode(last_ptr, data, position);
                break;

            case 9:
                printf("Entre the Value To Add : ");
                scanf("%d", &data);
                printf("Entre the postion of add it After : ");
                scanf("%d", &position);   
                      
                insertAfterGivenNode(last_ptr, data, position);
                break;

            case 10:
                deleteNodeAtBeginning(last_ptr);
                break;
                
            case 11:
                deleteNodeAtEnd(last_ptr);
                break;

            case 12:
                printf("Entre the postion To Delete : ");
                scanf("%d", &position);   
                      
                deleteGivenNode(last_ptr, position);
                break;

            case 13:
                printf("Entre the postion to delete after : ");
                scanf("%d", &position);   

                deleteAfterGivenNode(last_ptr, position);                      
                break;

            case 14:
                printf("Entre The value to Delete : ");
                scanf("%d", &data);

                deleteByValue(last_ptr, data);
                break;

            case 15:
                containsDuplicate = containsDuplicates(last_ptr);

                if (containsDuplicate) {
                    printf("\nContains Duplicate\n");
                }
                else {
                    printf("\nDoes Not Contains Duplicate\n");
                }
                break;

            case 16:
                RemoveDuplicates(last_ptr);
                break;

            case 17:
                sortBubble(last_ptr);
                break;

            case 18:
                reverseList(last_ptr);
                break;

            case 19:
                last = mergeTwoCircularLists(last_ptr, last_ptr2);
                *last_ptr2 = NULL;
                break;

            case 20:
                deleteList(last_ptr, true);
                break;

            case 21:
                userInput(last_ptr);
                break;

            default:
                printf("\"INVALID INPUT\"");
                break;
        }
    }
    while (choice != 0);
}

void insertAtBeginning (struct node **last_ptr, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("\"Memory Allocation Failed.....\"");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if ((*last_ptr) == NULL) {
        (*last_ptr) = newNode;
        (*last_ptr)->next = (*last_ptr);
    }
    else {
        newNode->next = (*last_ptr)->next;
        (*last_ptr)->next = newNode;
    }
}

void viewList (struct node **last_ptr) {
    if ((*last_ptr) == NULL) {
        printf("\n[ ]\n");
        return;
    }
    else {
        struct node *current = (*last_ptr)->next;

        printf("\n[ ");
        do {
            printf("%d, ", current->data);
            current = current->next;
        }
        while (current != (*last_ptr)->next);

        printf("\b\b ]\n");
    }
}

void insertAtEnd(struct node **last_ptr, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed.....");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*last_ptr == NULL) {
        (*last_ptr) = newNode;
        newNode->next = newNode;
    }
    else {
        struct node *head = (*last_ptr)->next;

        (*last_ptr)->next = newNode;
        newNode->next = head;
        *last_ptr = newNode;
    }
}

int numberOfNodes(struct node **last_ptr) {
    if (*last_ptr == NULL) {
        return 0;
    }

    struct node *current = *last_ptr;
    struct node *marker = *last_ptr;

    int length = 0;

    do {
        current = current->next;
        length++;
    }
    while(current != marker);

    return length;
}

int sumOfAllTheElement(struct node **last_ptr) {
    if (*last_ptr == NULL) {
        return 0;
    }

    struct node *current = *last_ptr;
    struct node *marker = *last_ptr;

    int sum = 0;

    do {
        sum += current->data;
        current = current->next;
    }
    while (current != marker);

    return sum;
}

int maxInList(struct node **last_ptr) {
    int max = INT_MIN;
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return max;
    }
    struct node *current = *last_ptr;
    struct node *marker = *last_ptr;

    do {
        if (max < current->data) {
            max = current->data;
        }

        current = current->next;
    }
    while (current != marker);

    return max;
}

int minInList(struct node **last_ptr) {
    int min = INT_MAX;
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return min;
    }

    struct node *current = *last_ptr;
    struct node *marker = *last_ptr;

    do {
        if (min > current->data) {
            min = current->data;
        }

        current = current->next;
    }
    while (current != marker);

    return min;
}

int searchInList(struct node **last_ptr, int data) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return -1;
    }

    int position = 0;
    struct node *current = *last_ptr;
    struct node *marker = *last_ptr;

    do {
        if (data == current->data) {
            return position;
        }

        current = current->next;
        position++;
    }
    while (current != marker);

    return -1;
}

void insertBeforeGivenNode(struct node **last_ptr, int data, int position) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed.....");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    struct node *current = (*last_ptr)->next;
    struct node *previous = NULL;
    int currentPosition = 0;

    do {
        currentPosition++;
        previous = current;
        current = current->next;
    }
    while(current != (*last_ptr)->next && currentPosition != position);

    if (current != (*last_ptr)->next) {
        previous->next = newNode;
        newNode->next = current;
    }
    else {
        printf("\nINVALID POSITION\n");
    }
}

void insertAfterGivenNode(struct node **last_ptr, int data, int position) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed.....");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    struct node *current = (*last_ptr)->next;
    struct node *marker = (*last_ptr)->next;
    int currentPosition = 0;

    do {
        currentPosition++;
        current = current->next;
    }
    while(current != marker && currentPosition != position);

    if (current != marker) {
        // using marker as temp to store the address of current 
        marker = current->next;
        // now pointing the current pointer to the new node
        current->next = newNode;
        // storing the location of the old current in the newNode->next
        newNode->next = marker;
    }
    else {
        printf("\nINVALID POSITION\n");
    }
}

void deleteNodeAtBeginning(struct node **last_ptr) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *toDelete = (*last_ptr)->next;
    struct node *helper = toDelete->next;

    (*last_ptr)->next = helper;
    free(toDelete);
}

void deleteNodeAtEnd(struct node **last_ptr) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *toDelete = *last_ptr;
    struct node *helper = toDelete->next;

    while (helper->next != toDelete) {
        helper = helper->next;
    }

    helper->next = (*last_ptr)->next;
    *last_ptr = helper;
    free(toDelete);
}

void deleteGivenNode(struct node **last_ptr, int position) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *current = (*last_ptr)->next;
    struct node *beforeCurrent = (*last_ptr);
    struct node *marker = (*last_ptr)->next;
    int currentPosition = 0;

    do {
        currentPosition++;
        beforeCurrent = beforeCurrent->next;
        current = current->next;
    }
    while(current != marker && currentPosition != position);

    if (current != marker) {
        // using marker as a temp var
        marker = current;
        beforeCurrent->next = current->next;
        free(current);       
    }
    else {
        printf("\nINVALID POSITION\n");
    }
}

void deleteAfterGivenNode(struct node **last_ptr, int position) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *current = (*last_ptr)->next;
    struct node *afterCurrent = current->next;
    int currentPosition = 0;

    do {
        currentPosition++;
        current = current->next;
        afterCurrent = afterCurrent->next;
    }
    while(current != (*last_ptr)->next && currentPosition < position);

    if (current != (*last_ptr)->next) {
        current->next = afterCurrent->next;
        free(afterCurrent);
    }
    else {
        printf("\nINVALID POSITION\n");
    }
}

bool containsDuplicates(struct node **last_ptr) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return false;
    }

    struct node *current = (*last_ptr)->next;
    struct node *current2 = NULL;

    do {
        current2 = current->next;
        do {
            if (current->data == current2->data) {
                return true;
            }
            
            current2 = current2->next;
        }
        while (current2->next != (*last_ptr)->next);
    }
    while (current != (*last_ptr)->next);

    return false;
}

void RemoveDuplicates(struct node **last_ptr) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *current = (*last_ptr)->next;
    struct node *current2 = NULL;
    struct node *previous = NULL;

    do {
        current2 = current->next;
        previous = current;
        do {
            if (current->data == current2->data) {
                previous->next = current2->next;
                free(current2);
                current2 = previous->next;
                return;
            }
            
            current2 = current2->next;
            previous = previous->next;
        }
        while (current2->next != current);
    }
    while (current != (*last_ptr)->next);
    
    printf("\nDoes not contains Duplicate\n");
}

void sortBubble(struct node **last_ptr) {
    // Check if the list is empty or has only one element
    if (*last_ptr == NULL || (*last_ptr)->next == *last_ptr) {
        printf("\nCreate a List with at least two elements for sorting\n");
        return;
    }

    struct node *current = (*last_ptr)->next;
    struct node *current2 = NULL;
    int swapped;

    do {
        current2 = current->next;

        do {
            if (current->data > current2->data) {
                int temp = current2->data;
                current2->data = current->data;
                current->data = temp;
            } 

            current2 = current2->next;
        }
        while (current2 != (*last_ptr)->next);

        current = current->next;
    }
    while (current != (*last_ptr)->next);

    int temp = (*last_ptr)->data;
    (*last_ptr)->data = ((*last_ptr)->next)->data; 
    ((*last_ptr)->next)->data = temp;
}

void reverseList(struct node **last_ptr) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *next = NULL;
    struct node *current = (*last_ptr)->next;
    struct node *prev = *last_ptr;

    do {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    while (current != (*last_ptr)->next);

    (*last_ptr)->next = prev;
}

void deleteList(struct node **last_ptr, bool showMsg) {
    if (*last_ptr == NULL && showMsg) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *current = (*last_ptr)->next;
    struct node *afterCurrent = NULL;

    do {
        afterCurrent = current->next;
        free(current);
        current = afterCurrent;
    } while (current != (*last_ptr)->next);

    *last_ptr = NULL;
}

void deleteByValue(struct node **last_ptr, int data) {
    if (*last_ptr == NULL) {
        printf("\nCreate a List First\n");
        return;
    }

    struct node *current = (*last_ptr)->next;
    struct node *helper = NULL;
    bool deleted = false;

    do {
        if (current->data == data) {
            if (current == (*last_ptr)->next) {
                (*last_ptr)->next = current->next;
            }
            else {
                helper->next = current->next;
            }

            free(current);
            deleted = true;
            break;
        }

        helper = current;
        current = current->next;
    }
    while (current != (*last_ptr)->next);

    if (!deleted) {
        printf("\nValue is Not There\n");
    }
}

void userInput(struct node **last_ptr) {
    int values, data;
    printf("\nEntre The Number of values to add : ");
    scanf ("%d", &values);

    for (int i = 0; i < values; i++) {
        printf("Entre The %d value : ", i);
        scanf("%d", &data);

        insertAtEnd(last_ptr, data);
    }
}

struct node *mergeTwoCircularLists(struct node **last_ptr1, struct node **last_ptr2) {
    if (*last_ptr1 == NULL) {
        printf("\nCreating The First List : \n");
        userInput(last_ptr1);
    }

    printf("\nCreating the Second List : \n");
    userInput(last_ptr2);

    // Merge the two lists
    struct node *temp1 = (*last_ptr1)->next;
    struct node *temp2 = (*last_ptr2)->next;

    (*last_ptr1)->next = temp2;
    (*last_ptr2)->next = temp1;

    // Update the last_ptr of the first list to point to the new last node
    *last_ptr1 = *last_ptr2;

    return *last_ptr1; // Return the merged list's last_ptr
}
