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
		strcpy(word, wordBuffer);
		if (strlen(word) > 0) {
			insertWord(hashTable, word);
		}
	}
	fclose(file);
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
	if (!insertWord(hashTable, "word1")) {
		printf("error allocating memory for addition");
		return false;
	}
	insertWord(hashTable, "word2");
	insertWord(hashTable, "word3");
	insertWord(hashTable, "word4");
	
	Node* current = search(hashTable, "word2");
	if (current == NULL) {
		printf("word not found in hash table");
		return false;
	}

	freeTable(hashTable);
	return true;
}