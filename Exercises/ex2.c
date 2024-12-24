#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void deleteElement(int a[], int *n, int i) {
    int j;
    for (j = i; j <= *n - 1; j++) {
        a[j] = a[j + 1];
    }
    *n = *n - 1;
}

void mergeArrays(int a1[], int s1, int a2[], int s2, int ma[]) {
    int j,k;
    k = 0;

    for (j = 0; j < s1; j++) {
        ma[k] = a1[j];
        k++;
    }
    for (j = 0; j < s2; j++) {
        ma[k] = a2[j];
        k++;
    }
}

int get_least(int a[], int s) {
    int least,i;
    least = a[0];
    for (i = 0; i < s; i++) {
        if (a[i] < least) {
            least = a[i];
        }
    }
    return least;
}

int get_least_rer(int *a, int s) {
    int least,i;
    least = *a;
    for (i = 0; i < s; i++) {
        if (*(a + i) < least) {
            least = *(a + i);
        }
    }
    return least;
} 

int main() {
    int arr1[10], n1Items, arr2[9], n2Items, i, index, mergedArray[18];
    n1Items = 10;
    srand(time(NULL));
    printf("\n\n");

    for (i = 0; i < n1Items; i++) {
        arr1[i] = rand() % 101;
    }

    printf("Array of 10 elements:  ");
    for (i = 0; i < n1Items; i++) {
        printf("%d  ", arr1[i]);
    }

    deleteElement(arr1, &n1Items, 7);
    printf("\nDeleted 8th element.\n");
    printf("Remaining array:  ");
    for (i = 0; i < n1Items; i++) {
        printf("%d  ", arr1[i]);
    }

    n2Items = 9;
    for (i = 0; i < n2Items; i++) {
        arr2[i] = rand() % 101;
    }

    printf("\n\nArray of 9 elements:  ");
    for (i = 0; i < n1Items; i++) {
        printf("%d  ", arr1[i]);
    }

    mergeArrays(arr1, n1Items, arr2, n2Items, mergedArray);
    printf("\nMerged first and second arrays.\n");
    printf("Merged array:  ");
    for (i = 0; i < n1Items + n2Items; i++) {
        printf("%d  ", mergedArray[i]);
    }

    n1Items++;

    for (i = 0; i < n1Items; i++) {
        arr1[i] = rand() % 101;
    }

    printf("\n\nArray of 10 elements:  ");
    for (i = 0; i < n1Items; i++) {
        printf("%d  ", arr1[i]);
    }

    printf("\nLeast element: %d\n", get_least(arr1, n1Items));

    printf("Least element by reference: %d\n\n", get_least_rer(arr1, n1Items));

    return 0;
}