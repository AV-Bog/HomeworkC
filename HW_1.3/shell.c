#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define testLength 5
void ShellSort(int mass[], int n);
bool tests();

int main() {
   /* if (!tests()) return 1;*/

    int size = 0;

    printf("Enter the size of the array: ");
    int rez0 = scanf("%d", &size);

    while (size <= 0) {
        printf("Invalid input (enter a natural number)");
        printf("Enter the size of the array: ");
        int rez1 = scanf("%d", &size);
    }

    int* array = malloc(sizeof(int) * size);
    if (array == NULL) {
        printf("Memory is not avaialble!\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter the element N%d: ", i);
        int rez2 = scanf("%d", &array[i]);
    }

    ShellSort(array, size);

    printf("Sorted array: ");

    for (int i = 0; i < size; i++) printf("%d ", array[i]);

    free(array);
    return 0;
}


void ShellSort(int array[], int size) {
    int i, j, step;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++) {
            for (j = i; j >= step; j -= step) {
                if (array[j - step] > array[i]) {
                    array[j] = array[j - step];
                }
                else break;
            }
            array[j] = array[i];
        }
}


bool isSorted(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

bool tests() {
    int test[testLength] = { 5, 4, 3, 2, 1 };
    ShellSort(test, testLength);
    if (!isSorted(test, testLength)) {
        printf("Failed on the example array\n");
        return false;
    }

    int test1[testLength] = { 1, 2, 3, 4, 5 };
    ShellSort(test1, testLength);
    if (!isSorted(test1, testLength)) {
        printf("Failed on the sorted array\n");
        return false;
    }

    int test2[testLength] = { 9, 9, 9, 9, 9 };
    ShellSort(test2, testLength);
    if (!isSorted(test2, testLength)) {
        printf("Failed on the array consisisting of the same element\n");
        return false;
    }
    return true;
}