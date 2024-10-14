#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 1000

int mostFrequentElement(int array[], int len);
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

void printArr(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}