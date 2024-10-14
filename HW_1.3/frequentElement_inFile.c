#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 1000

int mostFrequentElement(int array[], int len);
bool tests();
void quickSort(int array[], int low, int high);
void printArr(int array[], int size);

int main() {
    if (!tests()) return 1;

    FILE* input = fopen("array.txt", "r");
    if (input == NULL) {
        printf("File not found");
        return -1;
    }

    int array[ARRAY_SIZE] = { 0 };
    int index = 0;
    while (fscanf_s(input, "%d", &array[index]) != EOF) {
        index++;
    }
    fclose(input);

    printf("The array: ");
    printArr(array, index);

    quickSort(array, 0, index - 1);

    printf("\nThe most frequent element in the array is: %d\n", mostFrequentElement(array, index));
    return 0;
}

void swap(int *firstValue, int *secondValue) {
    int temp = *firstValue;
    *firstValue = *secondValue;
    *secondValue = temp;
}

int partition(int array[], int low, int high) {
    int pivotVal = array[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (array[j] < pivotVal) {
            swap(&array[j], &array[i]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, 0, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

int mostFrequentElement(int array[], int len) {
    int count = 1;
    int answer = array[0];
    int countAns = -1;

    for (int i = 1; i < len - 1; i++) {
        if (array[i] == array[i + 1]) {
            count++;
            if (count > countAns) {
                countAns = count;
                answer = array[i];
            }
        }
        else count = 1;
    }
    return answer;
}

bool isSorted(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
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

bool tests() {
    int array1[] = { 3,2,1,4,5,3,2,1,3,2 };
    quickSort(array1, 0, 9);
    if (!isSorted) {
        printf("sorting failed");
        return false;
    }

    int array2[] = { 3,2,2,4,5,3,2,1,3,1 };
    quickSort(array2, 0, 9);
    if (!isSorted) {
        printf("sorting failed. the first pivot is the smallest element");
        return false;
    }

    int array3[] = { 3,2,2,4,5,3,2,1,3,9 };
    quickSort(array3, 0, 9);
    if (!isSorted) {
        printf("sorting failed. the first pivot is the beggest element");
        return false;
    }

    int array4[] = { 9,8,7,6,5,4,3,2,1,0 };
    quickSort(array4, 0, 9);
    if (!isSorted) {
        printf("Failed on an reversed array");
        return false;
    }

    int array5[] = { 1,7,7,7,7,7,7,7,8,9 };
    if (mostFrequentElement(array5, 10) != 7) {
        printf("frequent element detection failed");
        return false;
    }

    int test6[1] = { 9 };
    if (mostFrequentElement(test6, 1) != 9) {
        printf("Failed when there's only one element\n");
        return false;
    }
    return true;
}