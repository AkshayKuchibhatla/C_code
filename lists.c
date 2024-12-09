#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        printf(" ");
    }
}

void append(int array[], int size, int newItem) {
    int newArray[size+1];
    int i;
    for (i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    newArray[size] = newItem;
    printArray(newArray, 11);
}

void insert(int array[], int size, int newItem, int index) {
    int newArray[size+1];
    if (index < 0 || index > size) {
        return;
    }
    newArray[index] = newItem;
    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }
    for (int i = index; i < size; i++) {
        newArray[i+1] = array[i];
    }
    printArray(newArray, size+1);
}

void delete(int array[], int size, int index) {
    int newArray[size-1];
    if (index < 0 || index > size - 1) {
        return;
    }
    for (int i = 0; i < index; i++) {
        newArray[i] = array[i];
    }
    for (int i = index+1; i < size; i++) {
        newArray[i - 1] = array[i];
    }
    printArray(newArray, size - 1);
}

int main() {
    int array1[10] = {7, 11, 19, 23, 1, 0, 5, 99, 117, 61};
    printArray(array1, 10);
    printf("\n");
    append(array1, 10, 34);
    printf("\n");
    insert(array1, 10, 24, 10);
    printf("\n");
    delete(array1, 10, 9);

    return 0;
}