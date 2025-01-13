#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

bool test();
bool printOptions();

int main() {
	if (!test()) {
		return -1;
	}

	FILE* file = fopen("telephoneDirectory.txt", "r");
	if (file == NULL) {
		printf("");
		return 1;
	}

	LinkedList* dictionary = createList();

	int i = 0;
	while (!feof(file)) {
		char* bufferName = malloc(sizeof(char) * 100);
		if (bufferName == NULL) {
			printf("");
			return 1;
		}

		char* bufferNumber = malloc(sizeof(char) * 100);
		if (bufferNumber == NULL) {
			printf("");
			return 1;
		}

		fscanf(file, "%s", bufferName);
		fscanf(file, "%s", bufferNumber);

		insert((bufferNumber), bufferName, dictionary);
		i++;
	}
	fclose(file);
	bool choice = 0;
	printOptions();
	scanf("%d", &choice);
	if (choice == 0) {
		mergeSort(dictionary, false);
	}
	else {
		mergeSort(dictionary, true);
	}

	printList(dictionary);
	deleteList(dictionary);

}

bool printOptions() {
	printf("How would you like to sort entries?\n");
	printf("0 - sort by a telephone number\n");
	printf("1 - sort by a name\n");
	printf("Enter a corresponding digit to choose: ");

}

bool test() {
	LinkedList* list1 = createList();
	insert("12345", "askjd", list1);
	insert("14445", "lkxcm", list1);
	insert("12375", "epori", list1);
	insert("32345", "peric", list1);
	insert("12945", "alksd", list1);
	mergeSort(list1, false);
	if (!isSorted(list1, false)) {
		printf("sorting by number on standard example failed\n");
		return false;
	}
	mergeSort(list1, true);
	if (!isSorted(list1, true)) {
		printf("sorting by name on standard example failed\n");
		return false;
	}

	LinkedList* list2 = createList();
	insert("1", "aaaaa", list2);
	insert("11", "aaaa", list2);
	insert("111", "aaa", list2);
	insert("1111", "aa", list2);
	insert("11111", "a", list2);
	mergeSort(list2, false);
	if (!isSorted(list2, false)) {
		printf("sorting by number failed on example with repeating characters\n");
		return false;
	}
	mergeSort(list2, true);
	if (!isSorted(list2, true)) {
		printf("sorting by name failed on example with repeating characters\n");
		return false;
	}
}