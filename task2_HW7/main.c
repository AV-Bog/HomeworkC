#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

void options();
bool tests();

int main() {
	if (!tests()) {
		return 1;
	}

	Dictionary* dictionary = createDictionary();

	int choice = -1;
	char valueBuffer[256] = { '\0' };
	int key = 0;
	options();
	scanf("%d", &choice);

	while (choice != 0) {
		switch (choice) {
		case 1:
			printf("Enter a key: ");
			scanf("%d", &key);
			printf("Enter the value: ");
			scanf("%c", &valueBuffer);

			char* value = malloc(sizeof(char) * 256);
			if (value == NULL) {
				printf("Out of memory\n");
				deleteDictionary(dictionary);
				return 1;
			}

			strcpy(value, valueBuffer);
			if (theKeyExists(dictionary, key)) {
				changeData(dictionary, key, value);
				break;
			}
			insert(dictionary, key, value);
			break;
		case 2:
			printf("Enter key: ");
			scanf("%d", &key);
			printf("The value is %s\n", getValue(dictionary, key));
			break;
		case 3:
			printf("Enter a key: ");
			scanf("%d", &key);
			if (theKeyExists(dictionary, key)) {
				printf("There is such a key in the dictionary\n");
			}
			else {
				printf("There is no such a key in the dictionary\n");
			}
			break;
		case 4:
			printf("Enter a key: ");
			scanf("%d", &key);
			if (theKeyExists(dictionary, key)) {
				deleteViaKey(dictionary, key);
				printf("the key and its corresponding value were successfully deleted");
			}
			else {
				printf("the key is not in the dictionary");
			}
		default:
			printf("Invalid input");
			deleteDictionary(dictionary);
			break;
		}
	}
	deleteDictionary(dictionary);
}

bool tests() {
	Dictionary* testDictionary = createDictionary();
	insert(testDictionary, 7, "hjvfirf");
	insert(testDictionary, 3, "cbufhtnf");
	insert(testDictionary, 2, "fktrif");
	insert(testDictionary, 5, "yjdbx");
	insert(testDictionary, 4, "rhfi");
	insert(testDictionary, 6, "xnjgbcfnmc.lf");
	insert(testDictionary, 14, "lfgj[eq");

	if (!theKeyExists(testDictionary, 6)) {
		printf("existing key not found");
		deleteDictionary(testDictionary);
		return false;
	}
	if (theKeyExists(testDictionary, 10)) {
		printf("non-existent key found");
		deleteDictionary(testDictionary);
		return false;
	}
	if (getValue(testDictionary, 14) != "lfgj[eq") {
		printf("error searching for value by existing key");
		deleteDictionary(testDictionary);
		return false;
	}
	if (strcmp(getValue(testDictionary, 13), "NULL") != 0) {
		printf("Get value function failed on trying to get a value of a nonexistent key");
		deleteDictionary(testDictionary);
		return false;
	}

	deleteViaKey(testDictionary, 4);
	if (theKeyExists(testDictionary, 4)) {
		printf("error deleting key with its corresponding value");
		deleteDictionary(testDictionary);
		return false;
	}
	return true;
}

void options() {
	printf("Options\n");
	printf("0 - Exit\n");
	printf("1 - Add a value with a correlating key\n");
	printf("2 - Get a value via a key\n");
	printf("3 - Check to see if there's a key in the dictionary\n");
	printf("4 - Delete a key and acorrelating value\n");
	printf("Enter a corresponding digit to choose an aption: ");
}