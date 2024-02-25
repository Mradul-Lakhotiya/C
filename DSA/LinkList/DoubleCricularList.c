#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

void displayChoice();

void insertAtBeginning(struct node **head_ptr, int data);
void viewList(struct node **head_ptr);
void insertAtEnd(struct node **head_ptr, int data);
void insertBeforeGivenNode(struct node **head_ptr, int data, int position);
void insertAfterGivenNode(struct node **head_ptr, int data, int position);
void deleteNodeAtBeginning(struct node **head_ptr);
void deleteNodeAtEnd(struct node **head_ptr);
void deleteGivenNode(struct node **head_ptr, int position); 
void deleteAfterGivenNode(struct node **head_ptr, int position);
void RemoveDuplicates(struct node **head_ptr); 
void sortBubble(struct node **head_ptr);
void reverseList(struct node **head_ptr);
void deleteList(struct node **head_ptr, bool showMsg);
void deleteByValue(struct node **head_ptr, int data);
void userInput(struct node **head_ptr);

struct node *mergeTwoLists(struct node **head_ptr1, struct node **head_ptr2);

int numberOfNodes(struct node **head_ptr);
int sumOfAllTheElement(struct node **head_ptr);
int maxInList(struct node **head_ptr);
int minInList(struct node **head_ptr);
int searchInList(struct node **head_ptr, int data);

bool containsDuplicates(struct node **head_ptr);


int main (int argc, char const *argv[]) {

    displayChoice();

    return 0;
}

void displayChoice() {
    struct node *head = NULL;
    struct node **head_ptr = &head;

    struct node *head2 = NULL;
    struct node **head_ptr2 = &head2;

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
        printf("18. Revers The list\n");
        printf("19. Create another List and Merge\n");
        printf("20. Delete The list\n");
        printf("21. Mass Value Entre\n");
        printf(" 0. Exit\n");
        printf("----------------------------------------\n");
        printf("    Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                deleteList(head_ptr, false);
                printf("\nExiting........39%%....57%%...99%%.\n");
                break;

            case 1:
                printf("Entre the Value To Add : ");
                scanf("%d", &data);

                insertAtBeginning(head_ptr, data);
                break;

            case 2:
                printf("Entre the Value To Add : ");
                scanf("%d", &data);

                insertAtEnd(head_ptr, data);
                break;
            
            case 3:
                viewList(head_ptr);
                break;

            case 4:
                length = numberOfNodes(head_ptr);

                printf("\nThe length of List is %d\n", length);
                break;

            case 5:
                sum = sumOfAllTheElement(head_ptr);

                printf("\nThe Sum of all the Element in the list will be : %d", sum);
                break;
            
            case 6:
                max = maxInList(head_ptr);
                min = minInList(head_ptr);

                printf("\n\t\tmax = %d\n\t\tmin = %d", max, min);
                break;

            case 7:
                printf("Entre the number to find : ");
                scanf("%d", &data);

                position = searchInList(head_ptr, data);
                printf("\nThe %d is at %d position\n", data, position);
                break;

            case 8:
                printf("Entre the Value To Add : ");
                scanf("%d", &data);
                printf("Entre the postion of add it before : ");
                scanf("%d", &position);   
                      
                insertBeforeGivenNode(head_ptr, data, position);
                break;

            case 9:
                printf("Entre the Value To Add : ");
                scanf("%d", &data);
                printf("Entre the postion of add it After : ");
                scanf("%d", &position);   
                      
                insertAfterGivenNode(head_ptr, data, position);
                break;

            case 10:
                deleteNodeAtBeginning(head_ptr);
                break;
                
            case 11:
                deleteNodeAtEnd(head_ptr);
                break;

            case 12:
                printf("Entre the postion To Delete : ");
                scanf("%d", &position);   
                      
                deleteGivenNode(head_ptr, position);
                break;

            case 13:
                printf("Entre the postion to delete after : ");
                scanf("%d", &position);   

                deleteAfterGivenNode(head_ptr, position);
                break;

            case 14:
                printf("Entre The value to Delete : ");
                scanf("%d", &data);

                deleteByValue(head_ptr, data);
                break;

            case 15:
                containsDuplicate = containsDuplicates(head_ptr);

                if (containsDuplicate) {
                    printf("\nContains Duplicate\n");
                }
                else {
                    printf("\nDoes Not Contains Duplicate\n");
                }
                break;

            case 16:
                RemoveDuplicates(head_ptr);
                break;

            case 17:
                sortBubble(head_ptr);
                break;

            case 18:
                reverseList(head_ptr);
                break;

            case 19:
                head = mergeTwoLists(head_ptr, head_ptr2);
                *head_ptr2 = NULL;
                break;

            case 20:
                deleteList(head_ptr, true);
                break;

            case 21:
                userInput(head_ptr);
                break;

            default:
                printf("\"INVALID INPUT\"");
                break;
        }
    }
    while (choice != 0);
}

void insertAtBeginning(struct node **head_ptr, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("\nMEMORY ALLOCATION FAILED\n");
        return;
    }

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (*head_ptr == NULL) {
        // If empty, set the new node as the only node in the list
        *head_ptr = newNode;
        (*head_ptr)->next = newNode;
        (*head_ptr)->prev = newNode;
    }
    else {
        // If not empty, update pointers to insert the new node at the beginning
        struct node *last = (*head_ptr)->prev;
        (*head_ptr)->prev = newNode;
        newNode->next = *head_ptr;
        newNode->prev = last;
        last->next = newNode;

        *head_ptr = newNode; // Update the head pointer to the new node
    }
}

void viewList(struct node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("[ ]");
    }
    else {
        struct node *current = *head_ptr;
        printf("[ ");
        do {
            printf("%d, ", current->data);
            current = current->next;
        } while (current != (*head_ptr));
        printf("\b\b ]\n");
    }
}

void insertAtEnd(struct node **head_ptr, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("\nMEMORY ALLOCATION FAILED\n");
        return;
    }

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    if (*head_ptr == NULL) {
        // If empty, set the new node as the only node in the list
        *head_ptr = newNode;
        (*head_ptr)->next = newNode;
        (*head_ptr)->prev = newNode;
    }
    else {
        // If not empty, update pointers to insert the new node at the end
        struct node *last = (*head_ptr)->prev;
        (*head_ptr)->prev = newNode;
        newNode->next = *head_ptr;
        newNode->prev = last;
        last->next = newNode;
    }
}

int numberOfNodes(struct node **head_ptr) {
    if (*head_ptr == NULL) {
        return 0;
    }
    int len = 0;
    struct node *current = *head_ptr;
    do {
        len++;
        current = current->next;
    } while(current != *head_ptr);

    return len;
}

int sumOfAllTheElement(struct node **head_ptr) {
    if (head_ptr == NULL) {
        return 0;
    }
    int sum = 0;
    struct node *current = *head_ptr;
    do {
        sum += current->data;
        current = current->next;
    } while(current != *head_ptr);

    return sum;
}

int maxInList(struct node **head_ptr) {
    int max = INT_MIN;

    if (*head_ptr == NULL) {
        printf("Create a List First");
        return max;
    }

    struct node *current = *head_ptr;
    do {
        if (max < current->data){
            max = current->data;
        }

        current = current->next;
    } while (current != *head_ptr);

    return max;
}

int minInList(struct node **head_ptr) {
    int min = INT_MAX;

    if (*head_ptr == NULL) {
        printf("Create a List First");
        return min;
    }

    struct node *current = *head_ptr;
    do {
        if (min > current->data){
            min = current->data;
        }

        current = current->next;
    } while (current != *head_ptr);

    return min;
}

int searchInList(struct node **head_ptr, int data) {
    if (*head_ptr == NULL) {
        printf("Create a List First");
        return -1;
    }

    struct node *current = *head_ptr;
    int position = 0;

    do {
        if (data == current->data) {
            return position;
        }
        position++;
        current = current->next;
    } while (current != *head_ptr);

    return -1;
}

void insertBeforeGivenNode(struct node **head_ptr, int data, int position) {
    if (*head_ptr == NULL) {
        printf("Create a List First");
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("\nMEMORY ALLOCATION FAILED\n");
        return;
    }

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    struct node *current = *head_ptr;
    int currentPosition = 0;

    do {
        current = current->next;
        currentPosition++;
    } while (current != *head_ptr && currentPosition < position);

    if (current != *head_ptr) {

        if (current->prev != NULL) {
            (current->prev)->next = newNode;
        }

        newNode->next = current;
        newNode->prev = current->prev;
        current->prev = newNode;

    } else {
        printf("Invalid Position");
    }
}

void insertAfterGivenNode(struct node **head_ptr, int data, int position) {
    if (*head_ptr == NULL) {
        printf("Create a List First");
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("\nMEMORY ALLOCATION FAILED\n");
        return;
    }

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    struct node *current = *head_ptr;
    int currentPosition = 0;

    do {
        current = current->next;
        currentPosition++;
    } while (current != *head_ptr && currentPosition < position);

    if (current != *head_ptr) {
        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != NULL) {
            (current->next)->prev = newNode;
        }

        current->next = newNode;

    } else {
        printf("Invalid Position");
    }   
}

void deleteNodeAtBeginning(struct node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("Create a List First");
        return;
    }

    struct node *current = *head_ptr;

    if ((*head_ptr)->next == *head_ptr) {
        free(current);
        *head_ptr = NULL;
        return;
    }

    *head_ptr = current->next;

    current->next->prev = current->prev;
    current->prev->next = current->next;

    free(current);
}

void deleteNodeAtEnd(struct node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("Create a List First");
        return;
    }

    struct node *current = *head_ptr;

    if ((*head_ptr)->next == *head_ptr) {
        free(current);
        *head_ptr = NULL;
        return;
    }

    current = current->prev;
    current->next->prev = current->prev;
    current->prev->next = current->next;

    free(current);
}

void deleteGivenNode(struct node **head_ptr, int position) {
    if (*head_ptr == NULL) {
        printf("Create a List First\n");
        return;
    }
    
    struct node *current = *head_ptr;
    int currentPosition = 0;

    do {
        current = current->next;
        currentPosition++;
    } while (current != *head_ptr && currentPosition < position);

    if (current != *head_ptr) {

        current->next->prev = current->prev;
        current->prev->next = current->next;

        free(current);
    } 
    else {
        printf("Invalid Position");
    }
}

void deleteAfterGivenNode(struct node **head_ptr, int position) {
    if (*head_ptr == NULL) {
        printf("Create a List First\n");
        return;
    }
    
    struct node *current = *head_ptr;
    int currentPosition = 0;

    do {
        current = current->next;
        currentPosition++;
    } while (current != *head_ptr && currentPosition <= position);

    if (current != *head_ptr) {

        current->next->prev = current->prev;
        current->prev->next = current->next;

        free(current);

    } else {
        printf("Invalid Position");
    }
}

void deleteByValue(struct node **head_ptr, int data) {
    if (*head_ptr == NULL) {
        printf("Create a List First\n");
        return;
    }
    
    struct node *current = *head_ptr;

    do {
        if (current->data == data) {
            break;
        }
        current = current->next;
    } while (current != *head_ptr);

    if (current != *head_ptr) {

        current->next->prev = current->prev;
        current->prev->next = current->next;

        free(current);
    } 
    else {
        printf ("The Value is not in List\n");
    }
}

bool containsDuplicates(struct node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("Create a List First\n");
        return false;
    }

    struct node *current1 = (*head_ptr);
    struct node *current2 = NULL;

    do {
        current2 = current1->next;

        do {
            if (current1->data == current2->data) {
                return true;
            }

            current2 = current2->next;
        } while (current2 != *head_ptr);

        current1 = current1->next;
    } while (current1 != *head_ptr);

    return false;
}

void RemoveDuplicates(struct node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("Create a List First\n");
        return;
    }

    struct node *current1 = (*head_ptr);
    struct node *current2 = NULL;

    do {
        current2 = current1->next;

        do {
            if (current1->data == current2->data) {
                struct node *temp = current2->next;

                current2->next->prev = current2->prev;
                current2->prev->next = current2->next;
                
                free(current2);
                current2 = temp;

                continue;
            }

            current2 = current2->next;

        } while (current2 != *head_ptr);
        current1 = current1->next;

    } while (current1 != *head_ptr);
}

void sortBubble(struct node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("Create a List First\n");
        return;
    }

    struct node *current1 = (*head_ptr);
    struct node *current2 = NULL;

    do {
        current2 = current1->next;

        do {
            if (current1->data < current2->data) {
                int temp = current1->data;
                current1->data = current2->data;
                current2->data = temp;
            }
            current2 = current2->next;
        } while (current2 != *head_ptr);

        current1 = current1->next;
    } while (current1 != *head_ptr);
}

void reverseList(struct node **head_ptr) {
    if (*head_ptr == NULL) {
        printf("Create a List First\n");
        return;
    }

    struct node *current = *head_ptr;
    struct node *newHead = (*head_ptr)->prev;
    struct node *temp = NULL;
    struct node *temp2 = NULL;

    do {
        temp2 = current->next;

        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        current = temp2;

    } while (current != *head_ptr);

    *head_ptr = newHead;
}

void userInput(struct node **head_ptr) {
    int n, value;
    printf("Entre The Number of Value : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entre The value to store : ");
        scanf("%d", &value);

        insertAtEnd(head_ptr, value);
    }
}

struct node *mergeTwoLists(struct node **head_ptr1, struct node **head_ptr2) {
    if (*head_ptr1 == NULL) {
        printf("Entre The Element of List 1 : \n");
        userInput(head_ptr1);
    }

    printf("Entre the Element of List 2 : ");
    userInput(head_ptr2);

    struct node *last1 = (*head_ptr1)->prev;
    struct node *last2 = (*head_ptr2)->prev;

    (*head_ptr1)->prev = (*head_ptr2);
    last1->next = last2;
    
    (*head_ptr2)->next = (*head_ptr1);
    last2->prev = last1;

    return *head_ptr1;
}

void deleteList(struct node **head_ptr, bool showMsg) {
    if (*head_ptr == NULL && showMsg) {
        printf("Create a List First\n");
        return;
    }

    struct node *current = *head_ptr;
    struct node *temp = NULL;
    

    do {
        current->prev = NULL;
        temp = current->next;

        free(current);
        current = temp;
    } while (current != *head_ptr);

    *head_ptr = NULL;
}
