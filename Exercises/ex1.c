#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertElement(int array[], int index, int nOfElements, int val) {
    int i;
    if (index <= nOfElements - 1) {
        for (i = nOfElements; i >= index; i--) 
            array[i + 1] = array[i];
    }
    array[index] = val;
}

int main() {
    int quantities[22];
    int e;
    int value;
    srand(time(NULL));

    for (e = 0; e < 20; e++) {
        quantities[e] = rand() % 1001;
    }

    printf("%s", "Array:  ");
    for (e = 0; e < 20; e++) printf("%d  ", quantities[e]);
    printf("%s","\n\n");

    printf("%s", "5th, 10th, 15th, 20th elements:  ");
    for (e = 1; e < 4; e++) printf("%d  ", quantities[5 * e]);
    printf("%s","\n\n");
    
    printf("Enter a number to insert into the beginning of the array: ");
    scanf("%d", &value);
    printf("\nArray:  ");
    insertElement(quantities, 0, 20, value);
    for (e = 0; e < 21; e++) printf("%d  ", quantities[e]);
    printf("%s","\n\n");

    printf("Enter a number to insert into the end of the array: ");
    scanf("%d", &value);
    printf("\nArray:  ");
    insertElement(quantities, 21, 21, value);
    for (e = 0; e < 22; e++) printf("%d  ", quantities[e]);
    printf("%s","\n\n");

    printf("%s\n\n", "Finding the largest value in the array...");
    value = quantities[0];
    for (e = 0; e < 22; e++) {
        if (quantities[e] > value) {
            value = quantities[e];
        }
    }
    
    printf("%d is the greatest value in the array.", value);

    return 1;
}