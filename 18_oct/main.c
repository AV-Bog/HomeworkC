#include "frequentElement.h"
#define ARRAY_SIZE 1000

int main() {
    if (!tests()) {
        return 1;
    }

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
    printArray(array, index);

    quickSort(array, 0, index - 1);

    printf("\nThe most frequent element in the array is: %d\n", mostFrequentElement(array, index));
    return 0;
}
