#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

void displayList (struct Node *Head);
void insertAtBeginning (struct Node **Head, int value);
void insertAtEnd (struct Node **Head, int value);
void InsertBeforeNode (struct Node **Head, int postion, int value);
void InsertAfterNode (struct Node **Head, int postion, int value); 
void deleteNodeAtBeginning (struct Node **Head);
void deleteNodeAtTheEnd (struct Node **Head);
void deleteGiveNode (struct Node **Head, int position);
void deleteNodeAfterGivenNode (struct Node **Head, int position); 
// void frequencyInList(struct Node *Head); //TODO working Sorting will make it work
void deleteLinkedList (struct Node *Head);
void deleteByValue (struct Node *Head, int value);
void reverseList (struct Node **Head);
void removeDuplicates(struct Node **Head_ptr);
void bubbleSortLinkList(struct Node *Head);
void mergeLinkList(struct Node *Head, struct Node *Head1);
struct Node *mergeInSortedManner(struct Node **List1, struct Node **List2); // working

struct Node *userInput();

int countNodes (struct Node *Head);
int sumOfList (struct  Node *Head);
int minInList (struct Node *Head);
int maxInList (struct Node *Head);
int searchLinear (struct Node *Head, int key);

bool containDuplicates (struct Node **Head_ptr);


void displayList (struct Node *Head) {
    struct Node *currentNode = Head;
    if (Head == NULL) {
        printf("[ ]");
        return;
    }
    
    printf("[ ");
    while (currentNode != NULL) {
        printf("%d, ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\b\b ]");

    return;
}

void insertAtBeginning (struct Node **Head, int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMEMORY ALLOCATION FAILED");
        return;
    }

    newNode->data = value;
    newNode->next = *Head;
    *Head = newNode;

    return;
}

void insertAtEnd (struct Node **Head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMEMORY ALLOCATION FAILED");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*Head == NULL) {
        *Head = newNode;
        return;
    }

    struct Node *last = *Head;

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;

    return;
}

void InsertBeforeNode (struct Node **Head, int postion, int value) {
    if (*Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *temp = NULL;
    struct Node *current = *Head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMEMORY ALLOCATION FAILED\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    while (current != NULL && postion > 0) {
        temp = current;
        current = current->next;
        postion--;
    }

    if (postion > 0) {
        printf("\nEnter a VALID POSITION\n");
        free(newNode);
        return;
    }

    temp->next = newNode;
    newNode->next = current;

    return;
}

void InsertAfterNode (struct Node **Head, int position, int value) {
    if (*Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *temp = NULL;
    struct Node *current = *Head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMEMORY ALLOCATION FAILED\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    

    while(current != NULL && position > 0) {
        current = current->next;
        position--;
    }

    if (position > 0) {
        printf("\nEnter a VALID POSITION\n");
        free(newNode);
        return;
    }

    temp = current->next;
    current->next = newNode;
    newNode->next = temp;

    return;
}

void deleteNodeAtBeginning(struct Node **Head) {
    if (*Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *temp = *Head;

    *Head = (*Head)->next;
    free(temp);
}

void deleteNodeAtTheEnd (struct Node **Head) {
    if (*Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *current = *Head;
    struct Node *temp = NULL;

    while(current->next != NULL) {
        temp = current;
        current = current->next;
    }

    if (temp != NULL) {
        temp->next = NULL;
        free(current);
    }
    else {
        free(current);
        *Head = NULL;
    }

    return;
}

void deleteGiveNode (struct Node **Head, int position) {
    if (*Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *current = *Head;
    struct Node *temp = NULL;

    while(current != NULL && position > 0) {
        temp = current;
        current = current->next;
        position--;
    }

    if (position > 0 || current->next == NULL) {
        printf("\nEnter a VALID POSITION\n");
        return;
    }

    temp->next = current->next;
    free(current);

    return;
}

void deleteLinkedList (struct Node *Head) {
    if (Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *current = Head;
    struct Node *temp = NULL;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    Head = NULL;
    return;
}

void deleteNodeAfterGivenNode (struct Node **Head, int position) {
    if (*Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *current = *Head;
    struct Node *temp = NULL;

    while (current != NULL && position > 0) {
        current = current->next;
        position--;
    }

    if (position > 0 || current->next == NULL) {
        printf("\nEnter a VALID POSITION\n");
        return;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);

    return;
}

void deleteByValue (struct Node *Head, int value) {
    if (Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *current = Head;
    struct Node *beforCurrent = NULL; 

    while (current != NULL && current->data != value) {
        beforCurrent = current;
        current = current->next;
    }

    if(current->data == value) {
        beforCurrent->next = current->next;
        free(current);
    }
    else {
        printf("\nINVALID VALUE\n");
    }

    return;
}

void reverseList (struct Node **Head) {
    if (*Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *next = NULL;
    struct Node *current = *Head;
    struct Node *prev = NULL;

    while (current != NULL) {
        // storing the next
        next = current->next;
        // Pointing the Pointing In revers Direction
        current->next = prev;
        // Moving the Current
        prev = current;
        current = next;
    }

    (*Head) = prev;
    return;
}

void removeDuplicates(struct Node **Head_prt) {
    if (*Head_prt == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *current = *Head_prt;
    struct Node *beforeHelper = NULL;
    struct Node *helper = NULL;

    while (current != NULL) {
        beforeHelper = current;
        helper = current->next;

        while (helper != NULL) {
            if(current->data == helper->data) {
                beforeHelper->next = helper->next;
                free(helper);
                helper = beforeHelper->next;
            }
            else {
                beforeHelper = beforeHelper->next;
                helper = helper->next;
            }
        }

        current = current->next;
    }
}

void bubbleSortLinkList(struct Node *Head) {
    struct Node *current = Head;
    struct Node *current2 = NULL;

    while (current != NULL) {
        current2 = Head;
        
        while (current2 != NULL && current2->next != NULL) {

            if (current2->data > current2->next->data) {
                int temp = current2->data;
                current2->data = current2->next->data;
                current2->next->data = temp;
            }

            current2 = current2->next;
        }

        current = current->next;
    }
}

void mergeLinkList(struct Node *Head, struct Node *Head1) {
    if (Head1 == NULL || Head == NULL) {
        printf("\nERROR\n");
        return;
    }

    struct Node *current = Head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = Head1;
}

struct Node *mergeInSortedManner(struct Node **List1_ptr, struct Node **List2_ptr) {
    struct Node *SortedList = NULL;
    struct Node **SortedList_ptr = &SortedList;
    struct Node *List1 = *List1_ptr;
    struct Node *List2 = *List2_ptr;
    
    while (List1 != NULL && List2 != NULL) {
        if (List1->data < List2->data) {
            insertAtEnd (SortedList_ptr, List1->data);
            List1 = List1->next;
        }
        else {
            insertAtEnd (SortedList_ptr, List2->data);
            List2 = List2->next;
        }
    }

    while (List1 != NULL) {
        insertAtEnd (SortedList_ptr, List1->data);
        List1 = List1->next;
    }

    while (List2 != NULL) {
        insertAtEnd (SortedList_ptr, List2->data);
        List2 = List2->next;
    }

    deleteLinkedList(*List1_ptr);
    deleteLinkedList(*List2_ptr);

    return SortedList;
}

//! -------------------------------------------------------------------------------------------- //

struct Node *userInput() {
    struct Node *Head = NULL;
    int size = 0;
    int value;

    printf("Entre The size of List : ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("List[%d] : ", i);
        scanf("%d", &value);

        insertAtEnd(&Head, value);
    }

    return Head;
} 

//! -------------------------------------------------------------------------------------------- //

bool containDuplicates (struct Node **Head_ptr) {
    if (*Head_ptr == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return false;
    }

    struct Node *current = *Head_ptr;
    struct Node *helper = NULL;

    while (current != NULL) {
        helper = current->next;
        
        while (helper != NULL) {
            if (helper->data == current->data) {
                return true;
            }

            helper = helper->next;
        }

        current = current->next;
    }

    return false;
}

//! -------------------------------------------------------------------------------------------- //

int countNodes(struct Node *Head) {
    if (Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return 0;
    }

    struct Node *currentNode = Head;
    int length = 0;

    while(currentNode != NULL) {
        length++;
        currentNode = currentNode->next;
    }

    return length;
}

int sumOfList(struct Node *Head) {
    struct Node *current = Head;
    int sum = 0;
    
    if(Head == NULL) {
        return sum;
    }

    while(current != NULL) {
        sum += current->data;
        current = current->next;
    }

    return sum;
}

int minInList (struct Node *Head) {
    struct Node *current = Head;
    int min = INT_MAX;

    if(Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return min;
    }

    while(current != NULL) {
        if (min > current->data) {
            min = current->data;
        }

        current = current->next;
    }

    return min;
}

int maxInList (struct Node *Head) {
    struct Node *current = Head;
    int max = INT_MIN;

    if(Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return max;
    }

    while (current != NULL) {
        if (max < current->data) {
            max = current->data;
        }

        current = current->next;
    }

    return max;
}

int searchLinear (struct Node *Head, int key) {
    if(Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
    }

    struct Node *current = Head;
    int currentNode = 0;

    while(current != NULL) {
        if (current->data == key) {
            return currentNode;
        }
        
        current = current->next;
        currentNode++;
    }

    return -1;
}

//! -------------------------------------------------------------------------------------------- //

int main() {
    struct Node *Head = NULL;
    struct Node **Head_prt = &Head;

    int choice;
    int choice_max_min;
    int choice_merge;

    int value;
    int length = 0;
    int position;

    int sum;
    int max;
    int min;
    int key;
    int positionOfKey;

    bool containDuplicate = false;
    
    do {
        printf("\n----------------------------------------\n");
        printf("              MENU OPTIONS\n");
        printf("----------------------------------------\n");
        printf(" 1. Create a new list\n");
        printf(" 2. Display the current list\n");
        printf(" 3. Count the number of nodes in the list\n");
        printf(" 4. Calculate the sum of all elements in the list\n");
        printf(" 5. Find the maximum and minimum values in the list\n");
        printf(" 6. Search for a key in the list\n");
        printf(" 7. Insert a node at the beginning\n");
        printf(" 8. Insert a node at the end\n");
        printf(" 9. Insert before a given node\n");
        printf("10. Insert after a given node\n");
        printf("11. Delete a node at the beginning\n");
        printf("12. Delete a node at the end\n");
        printf("13. Delete a node at a specific position\n");
        printf("14. Delete the node after a specific position\n");
        printf("15. Delete nodes by value\n");
        printf("16. Check if the list contains duplicates\n");
        printf("17. Remove duplicates from the list\n");
        printf("18. Reverse the list\n");
        printf("19. Sort the list in descending order (Bubble Sort)\n");
        printf("20. Delete the entire linked list\n");
        printf("21. Merge Link List\n");
        printf(" 0. Exit\n");
        printf("----------------------------------------\n");
        printf("    Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 0:
            deleteLinkedList(Head);
            printf("\nExiting.........30%%.......70%%....99%%..\n");
            break;
        case 1:
            printf("Enter a value to insert : ");
            scanf("%d", &value);

            insertAtEnd(Head_prt, value);
            break;
        
        case 2:
            printf("\n");
            displayList(*Head_prt);
            printf("\n");
            break;

        case 3:
            length = countNodes(Head);

            printf("\nNumber of node are : %d\n", length);
            break;

        case 4:
            sum = sumOfList(Head);

            printf("\nThe sum of all the Element of list is : %d\n", sum);
            break;

        case 5:
            do {                
                printf("\n1. Find MAX\n");
                printf("2. Find MIN\n");
                printf("0. Back\n");
                printf("Choice : ");
                scanf("%d", &choice_max_min);
                
                switch (choice_max_min)
                {
                case 0:
                    printf("\nGoing Back......\n");
                    break;
            
                case 1:
                    max = maxInList(Head);

                    printf("The MAX Value in List is : %d", max);
                    break;

                case 2:
                    min = minInList(Head);

                    printf("The MIN Value in List is : %d", min);
                    break;

                default:
                    printf("\nINVALID INPUT\n");
                    break;
                }
            }
            while (choice_max_min != 0);
            break;

        case 6:
            printf("\nEnter Key : ");
            scanf("%d", &key);

            positionOfKey = searchLinear(Head, key);

            if (positionOfKey == -1) {
                printf("\nKey \"NOT FOUND\"");
            }
            else {
                printf("%d is at %d Node(0 indexing)", key, positionOfKey);
            }
            break;
            
        case 7:
            printf("Enter a value to insert : ");
            scanf("%d", &value);

            insertAtBeginning(Head_prt, value);
            break;

        case 8:
            printf("Enter a value to insert : ");
            scanf("%d", &value);

            insertAtEnd(Head_prt, value);
            break;

        case 9:
            printf("Enter The Position : ");
            scanf("%d", &position);
            printf("Entre the Value : ");
            scanf("%d", &value);

            InsertBeforeNode(Head_prt, position, value);
            break;

        case 10:
            printf("Enter The Position : ");
            scanf("%d", &position);
            printf("Entre the Value : ");
            scanf("%d", &value);

            InsertAfterNode(Head_prt, position, value);
            break;

        case 11:
            deleteNodeAtBeginning(Head_prt);
            break;

        case 12:
            deleteNodeAtTheEnd(Head_prt);
            break;

        case 13:
            printf("Enter The Position : ");
            scanf("%d", &position);

            deleteGiveNode(Head_prt, position);
            break;

        case 14:
            printf("Enter The Position : ");
            scanf("%d", &position);

            deleteNodeAfterGivenNode(Head_prt, position);
            break;

        case 15:
            printf("Enter the value to remove : ");
            scanf("%d", &value);

            deleteByValue(Head, value);
            break;

        case 16:
            containDuplicate = containDuplicates(Head_prt);

            if (containDuplicate) {
                printf("\nContain Duplicates\n");
            }
            else {
                printf("\nDoes not Contain Duplicates\n");
            }

            break;

        case 17:
            removeDuplicates(Head_prt);
            break;
        
        case 18:
            reverseList(Head_prt);
            break;

        case 19:
            bubbleSortLinkList(Head);
            break;

        case 20:
            deleteLinkedList(Head);
            Head = NULL;
            break;
        
        case 21:
            if (Head == NULL) {
                printf("\nEntre The values for the first List\n");
                Head = userInput();
            }

            printf("\nEntre The Value for second link list\n");
            struct Node *Head2 = userInput();

            printf("\n1. Merge in a unsorted manner\n");
            printf("2. Merge in Sorted manner\n");
            printf("0. Back\n");
            printf("Choice : ");
            scanf("%d", &choice_merge);
            
            switch (choice_merge)
            {
            case 0:
                printf("\nGoing Back......\n");
                break;
        
            case 1:
                mergeLinkList(Head, Head2);
                displayList(Head);

                break;

            case 2:
                bubbleSortLinkList(Head);
                bubbleSortLinkList(Head2);

                Head = mergeInSortedManner(&Head, &Head2);
                displayList(Head);

                break;

            default:
                printf("\nINVALID INPUT\n");
                break;
            }

            break;

        default:
            printf("INVALID INPUT");
            break;
        }
    }
    while (choice != 0);

    return 0;
}