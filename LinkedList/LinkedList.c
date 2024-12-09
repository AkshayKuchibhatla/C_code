#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <malloc.h>

struct node {
    double value;
    struct node *nextNode;
};

struct node *publicStartNode = NULL;
struct node *createLL(struct node *);
struct node *display(struct node *);
struct node *insertAtIndex(struct node *);
struct node *deleteAtIndex(struct node *);
struct node *deleteList(struct node *);
struct node *sortList(struct node *);
struct node *get(struct node *);
struct node *swap(struct node *);
int main(int argc, char *argv[]) {
    int option;
    
    do {
        printf("\n\n ****** MAIN MENU ******");
        printf("\n 1:   Create a list");
        printf("\n 2:   Display the list");
        printf("\n 3:   Add a node at index");
        printf("\n 4:   Delete a node at index");
        printf("\n 5:   Delete the entire list");
        printf("\n 6:   Sort the list");
        printf("\n 7:   Get the list item at index");
        printf("\n 8:   EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
       
        switch(option) {
            case 1: publicStartNode = createLL(publicStartNode);
                    printf("\n Linked list created.");
                    break;
            case 2: publicStartNode = display(publicStartNode);
                    break;
            case 3: publicStartNode = insertAtIndex(publicStartNode);
                    break;
            case 4: publicStartNode = deleteAtIndex(publicStartNode);
                    break;
            case 5: publicStartNode = deleteList(publicStartNode);
                    break;
            case 6: publicStartNode = sortList(publicStartNode);
                    break;
            case 7: publicStartNode = get(publicStartNode);
                    break;
            default: break;
        }
    } while (option != 8);

    return 0;
}

struct node *createLL(struct node *start) { 
    // Creates a linked list.
    struct node *newNode, *ptr;
    double num;
    printf("\n Enter -1 to end"); // When User enters -1, the list entry stops.
    printf("\n Enter value: "); // Ask user to enter the value.
    scanf("%lf", &num); // Get the value.
    
    do {
        // Then, allocate memory and assign a node to it.
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->value = num;

        if (start == NULL) { 
            // If the list is empty, just assign the node as the only value for now.
            newNode->nextNode = NULL;
            start = newNode;
        } else {
            ptr = start;
            while(ptr->nextNode != NULL) ptr = ptr->nextNode;
            ptr->nextNode = newNode;
            newNode->nextNode = NULL;
        }
        printf("\n Enter value: "); // Ask user to enter the value.
        scanf("%lf", &num); // Get the value.
    } while (num != -1);
    return start;
}

struct node *display(struct node *start) {
    struct node *ptr = start;
    while(ptr != NULL && ptr->nextNode != NULL) {
        printf("%lf", ptr->value);
        printf("\n");
        ptr = ptr->nextNode;
    }
    return start;
}

struct node *insertAtIndex(struct node *start) {
    int insertVal;
    int insertIndex;
    int currentIndex;

    printf("\n In insert \n"); 
    display(start);
    printf("\n Enter index: ");
    scanf("%d", &insertIndex);
    printf("\n Enter value: ");
    scanf("%d", &insertVal);
    printf("\n Insert Index : "); printf("\n"); printf("%d", insertIndex);
    struct node *beforePtr = start;
    struct node *afterPtr = start;

    for (currentIndex = 0; currentIndex < insertIndex; currentIndex++) {
        printf("\n After "); printf("%lf", afterPtr->value);
        if(currentIndex == insertIndex-2) {
            beforePtr = afterPtr->nextNode;
            printf("\n Before"); printf("%lf", beforePtr->value);
        }
        afterPtr = afterPtr->nextNode;
    }
    printf("\n After Pointer : ");
    printf("%lf", afterPtr->value);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->nextNode = afterPtr;
    newNode->value = insertVal;
    beforePtr->nextNode = newNode;
    return start;
}
struct node *deleteAtIndex(struct node *start) {
    int currentIndex = 0;
    int deleteIndex;
    printf("Enter index: ");
    scanf("%d", &deleteIndex);
    /* After retrieving input on what index we 
    have to delete at, we can place a pointer 
    before and after that index: */
    struct node *beforePtr = start;
    struct node *afterPtr = start;

    for (currentIndex = 0; currentIndex < deleteIndex + 1; currentIndex++) {
        if(currentIndex == deleteIndex-2) {
            beforePtr = afterPtr->nextNode;
        }
        afterPtr = afterPtr->nextNode;
    }
    printf("\n Before"); printf("%lf", beforePtr->value);
    printf("\n After "); printf("%lf", afterPtr->value);
    /* ...Then, we can do some switiching and
    freeing: */
    free(beforePtr->nextNode);
    beforePtr->nextNode = afterPtr;
    return start;
}
struct node *deleteList(struct node *start) {
    int originalLength = 0;
    struct node *nodePtr;
    // while (true) {
    nodePtr = start;
    while ((nodePtr != NULL) && (nodePtr->nextNode != NULL)) {
        /* First, this while loop counts the number
        of elements in the linked list: */
        nodePtr = nodePtr->nextNode;
    }
    printf("\n%lf", nodePtr->value);
    free(nodePtr->nextNode);
    nodePtr->nextNode = NULL;
    // }
    
    printf("%d", originalLength);
    return start;
}
struct node *sortList(struct node *start) {
    return start;
}
struct node *get(struct node *start) {
    return start;
}