#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int studentId;
    char name[20];
    struct node *right;
};

struct node *nodeA = NULL;
// struct node *buildNode(struct node *, struct node *);
void buildNode(int, char[]);
void insertNode(struct node *, struct node *);
struct node *searchForVal(struct node *);
struct node *display(struct node *);

int main() {
    int option;
    int idInput;
    char dummy;
    do {
        printf("\n\n ****** MAIN MENU ******");
        printf("\n 1:   Add a node to the binary tree");
        printf("\n 2:   Search for a node in the binary tree");
        printf("\n 3:   Display the binary tree");
        printf("\n 4:   EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\n Enter new student's ID number: ");
                scanf("%d", &idInput);
                printf("\n %d", idInput);
                printf("\n Enter new student's name: ");
                scanf("%s", &dummy);
                
                buildNode(idInput, &dummy);
                break;
            case 2: nodeA = searchForVal(nodeA);
                    break;
            case 3: nodeA = display(nodeA);
                    break;
            default: break;
        }
    } while (option != 4);

    return 0;
}

void insertNode(struct node *tree, struct node *node) {
    printf("\n%d", node->studentId);
    printf("\n%s", node->name);
    if (tree == NULL) {
        tree = node;
        tree->left = NULL;
        tree->right = NULL;
    }
    if (node->studentId < tree->studentId) {
        insertNode(tree->left, node);
    }
    if (node->studentId > tree->studentId) {
        insertNode(tree->right, node);
    }
}

void buildNode(int id, char name[]) {
    printf("\n%d", id);
    printf("\n%s", name);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    for (int i = 0; i < 20; i++) {
        *(newNode->name + i) = *(name + i);
    }
    newNode->studentId = id;
    insertNode(nodeA, newNode);
}

struct node *display(struct node *root) {
    return root;
}

struct node *searchForVal(struct node *root) {
    struct node *ptr = root;
    double searchVal;
    printf("\n Enter a student's ID number: ");
    scanf("%lf", &searchVal);
    
    while (ptr->studentId != searchVal) {
        if (searchVal > ptr->studentId) {
            ptr = ptr->right;
        } else {
            ptr = ptr->left;
        }
    }
    printf("\n%s", ptr->name);
    return root;
}