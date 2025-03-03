#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "hashtable.h"

void readFromFile(HashTable* hashTable) {
	FILE* file = fopen("file.txt", "r");
	if (file == NULL) {
		printf("Failed to open file");
		return;
	}

	char wordBuffer[100] = { '\0' };
	while (!feof(file)) {
		fscanf(file, "%s", wordBuffer);
		const char* word = malloc(sizeof(char) * strlen(wordBuffer));
		if (word == NULL) {
			printf("Memory allocation failed\n");
			fclose(file);
			return;
		}

		if (strlen(word) > 0) {
			if (!insertWord(hashTable, word)) {
				printf("Error inserting word\n");
				free(word);
				fclose(file);
				return;
			}
		}
		free(word);
	}
}

bool tests();

int main() {
	if (!tests()) {
		return 1;
	}
	HashTable* hashTable = createTable();
	readFromFile(hashTable);
	printWordAndCount(hashTable);
	CalculationAndDisplayOfStatistics(hashTable);

	freeTable(hashTable);
	return 0;
}

bool tests() {
	HashTable* hashTable = createTable();
	if (hashTable == NULL) {
		printf("Memory allocation failed for hash table\n");
		return false;
	}

	if (!insertWord(hashTable, "word1")) {
		printf("Error allocating memory for addition\n");
		freeTable(hashTable);
		return false;
	}
	insertWord(hashTable, "word2");
	insertWord(hashTable, "word3");
	insertWord(hashTable, "word4");

	Node* current = search(hashTable, "word2");
	if (current == NULL) {
		printf("Word not found in hash table\n");
		freeTable(hashTable);
		return false;
	}

	freeTable(hashTable);
	return true;
}