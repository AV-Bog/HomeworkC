#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool tests();
void printArr(int array[], int size);
void quickSort(int array[], int low, int high);

int main() {
    if (!tests()) {
        return 1;
    }

    int size = 0;
    printf("Enter the size of the array: ");
    int rez0 = scanf("%d", &size);
    while (size <= 0) {
        printf("Invalid input! (size must be greater than 0)\n");
        printf("Enter the size of the array: ");
        int rez1 = scanf("%d", &size);
    }

    int* array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Out of memory\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter the element #%d: ", i);
        int rez2 = scanf("%d", &array[i]);
    }

    printf("\nThe array before the sort: ");
    printArr(array, size);

    quickSort(array, 0, size - 1);

    printf("\nThe array after the sort: ");
    printArr(array, size);

    free(array);
    return 0;
}

bool checkSorted(const int array[], int arrayLength) {
    for (int i = 0; i < arrayLength - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void printArr(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void swap(int* firstVal, int* secondVal) {
    int temp = *firstVal;
    *firstVal = *secondVal;
    *secondVal = temp;
}

void insertionSort(int array[], int low, int high) {
    for (int i = low; i < high; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= low && array[j] >= key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int partition(int array[], int low, int high) {
    int pivotVal = array[high];

    int i = low;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivotVal) {
            swap(&array[j], &array[i]);
            i++;
        }
    }
    swap(&array[high], &array[i]);
    return i;
}

void quickSort(int array[], int low, int high) {
    if (high - low + 1 < 10) {
        insertionSort(array, low, high + 1);
        return;
    }
    if (low < high) {
        int pivotIndex = partition(array, 0, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}
bool tests() {
    const int bigArraySize = 100;
    int* testArray1 = malloc(bigArraySize * sizeof(int));
    if (testArray1 == NULL) {
        printf("Tests failed: No memory\n");
        return false;
    }
    for (int i = 0; i < bigArraySize; i++) {
        testArray1[i] = rand() % 100;
    }

    quickSort(testArray1, 0, bigArraySize - 1);
    if (!checkSorted(testArray1, bigArraySize)) {
        printf("Failed on an array of 100 elements");
        free(testArray1);
        return false;
    }
    free(testArray1);

    int* array1[] = { 3,2,1,4,5,3,2,1,3,2 };
    quickSort(array1, 0, 9);
    if (!checkSorted(array1, 10)) {
        printf("sorting failed");
        return false;
    }

    int* array2[] = { 3,2,2,4,5,3,2,1,3,1 };
    quickSort(array2, 0, 9);
    if (!checkSorted(array2, 10)) {
        printf("sorting failed. the first pivot is the smallest element");
        return false;
    }

    int* array3[] = { 3,2,2,4,5,3,2,1,3,9 };
    quickSort(array3, 0, 9);
    if (!checkSorted(array3, 10)) {
        printf("sorting failed. the first pivot is the beggest element");
        return false;
    }

    int* array4[] = { 9,8,7,6,5,4,3,2,1,0 };
    quickSort(array4, 0, 9);
    if (!checkSorted(array4, 10)) {
        printf("Failed on an reversed array");
        return false;
    }

    return true;
}