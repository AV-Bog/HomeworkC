#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binarySearch(int array[], int element, int left, int right);
bool testsSort();
bool testsSearch();
void quickSort(int array[], int low, int high);

int main() {
	if (!tests()) return 1;
	int len = 0;
	printf("Enter the length of the array: ");
	int rez = scanf("%d", &len);
	while (len <= 0) {
		printf("Invalid input you must enter a natural number.\n");
		printf("Enter the length of the array: ");
		scanf("%d", &len);
	}

	int amount = 0;
	printf("How many numbers do you want to check if they're in the array?: ");
	scanf("%d", &amount);
	while (amount <= 0) {
		printf("Invalid input you must enter a natural number.\n");
		printf("Enter the length of the array: ");
		scanf("%d", &amount);
	}

	int* array = malloc(len * sizeof(int));
	if (array == NULL) {
		printf("Memory is not available!\n");
		return 1;
	}

	int* numbers = malloc(amount * sizeof(int));
	if (numbers == NULL) {
		printf("Memory is not available!\n");
		free(array);
		return 1;
	}

	for (int i = 0; i < len; i++) {
		array[i] = rand() % 101;
	}
	for (int i = 0; i < amount; i++) {
		numbers[i] = rand() % 101;
	}

	printf("Generated array: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("Generated numbers: ");
	for (int i = 0; i < amount; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");

	int count = 0;

	for (int j = 0; j < amount; j++) {
		if (binarySearch(array, numbers[j], 0, len - 1) > 0) {
			printf("The number %d is in the array! \n", numbers[j]);
			count++;
		}
	}

	if (count == 0) {
		printf("none of these numbers are in the array \n");
	}

	free(numbers);
	free(array);
	return 0;
}

int binarySearch(int array[], int element, int left, int right) {
	if (left > right) {
		return -1;
	}

	int mid = (left + right) / 2;

	if (array[mid] == element) {
		return mid;
	}
	else if (array[mid] > element) {
		return binarySearch(array, element, left, mid - 1);
	}
	else {
		return binarySearch(array, element, mid + 1, right);
	}
}

void swap(int* firstNumber, int* secondNumber) {
	int temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
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
	if (low < high) {
		int pivotIndex = partition(array, low, high);
		quickSort(array, 0, pivotIndex - 1);
		quickSort(array, pivotIndex + 1, high);
	}
}

bool isSorted(int array[], int arrayLength) {
	for (int i = 0; i < arrayLength - 1; i++) {
		if (array[i] > array[i + 1]) {
			return false;
		}
	}
	return true;
}

bool testsSort() {
	int* array1[] = { 3,2,1,4,5,3,2,1,3,2 };
	quickSort(array1, 0, 9);
	if (!isSorted) {
		printf("sorting failed");
		return false;
	}

	int* array2[] = { 3,2,2,4,5,3,2,1,3,1 };
	quickSort(array2, 0, 9);
	if (!isSorted) {
		printf("sorting failed. the first pivot is the smallest element");
		return false;
	}

	int* array3[] = { 3,2,2,4,5,3,2,1,3,9 };
	quickSort(array3, 0, 9);
	if (!isSorted) {
		printf("sorting failed. the first pivot is the beggest element");
		return false;
	}

	int* array4[] = { 9,8,7,6,5,4,3,2,1,0 };
	quickSort(array4, 0, 9);
	if (!isSorted) {
		printf("Failed on an reversed array");
		return false;
	}
	return true;
}

bool testsSearch(){
	int testArray1[] = { 1,2,3,4,5,6,7,8,9,10 };
	if (binarySearch(testArray1, 1, 0, 9) != 0) {
		printf("Search Failed when the element in question is the first\n");
		return false;
	}

	int testArray2[] = { 1,2,3,4,5,6,7,8,9,10 };
	if (binarySearch(testArray2, 10, 0, 9) != 9) {
		printf("Search Failed when the element in question is the last\n");
		return false;
	}

	int testArray3[] = { 1,2,3,4,5,6,7,8,9,10 };
	if (binarySearch(testArray3, 111, 0, 9) != -1) {
		printf("Search Failed when the element in question is not in the array\n");
		return false;
	}

	return true;
}