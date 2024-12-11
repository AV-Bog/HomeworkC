#include <stdio.h>
#include <stdbool.h>
#include "tree.h"

#define LENGHT_OF_TEST_ARREY 10

bool tests();
bool isSorted(int array[], int length);

int main() {
    if (!tests()) {
        return 1;
    }
    int array[] = { 1134, 577, 1, 16, 955, 153, 13656 };
    int length = sizeof(array) / sizeof(array[0]);
    ordering(array, length);
    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

bool isSorted(int array[], int length) {
    for (int i = 0; i < (length - 1); i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    int array1[] = { 1, 3, 5, 7, 8, 10, 12, 14, 17, 19 };
    inOrderSort(array1, LENGHT_OF_TEST_ARREY);
    if (!isSorted(array1, LENGHT_OF_TEST_ARREY)) {
        printf("Test failed on initially sorted array");
        return false;
    }


    int array2[] = { 21, 19, 17, 15, 11, 9, 7, 5, 3, 1 };
    inOrderSort(array2, LENGHT_OF_TEST_ARREY);
    if (!isSorted(array2, LENGHT_OF_TEST_ARREY)) {
        printf("Test failed on array with numbers arranged in reverse order");
        return false;
    }

    int array3[] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
    inOrderSort(array3, LENGHT_OF_TEST_ARREY);
    if (!isSorted(array3, LENGHT_OF_TEST_ARREY)) {
        printf("Test failed on array with same numbers");
        return false;
    }

    int array4[] = { 123432, 13234, 123, 123, 13, 54, 87, 145, 145, 15490 };
    inOrderSort(array4, LENGHT_OF_TEST_ARREY);
    if (!isSorted(array4, LENGHT_OF_TEST_ARREY)) {
        printf("Test failed on standard example");
        return false;
    }
    return true;
}