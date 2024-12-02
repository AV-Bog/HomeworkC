#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

void readingAFile(HashTable* hashTable) {
	FILE* file = fopen("file.txt", "r");
	if (file == NULL) {
		printf("Failed to open file");
		return;
	}

	char wordBuffer[256];
	while (!feof(file)) {
		fscanf(file, "%s", &wordBuffer);
		const char* word = malloc(sizeof(char) * strlen(wordBuffer));
		if (strlen(word) > 0) {
			insert_word(hashTable, word);
		}
	}
	fclose(file);
}

int main() {
	HashTable* hashTable = created_table();
	readingAFile(hashTable);
	printWordAndCount(hashTable);
	CalculationAndDisplayOfStatistics(hashTable);

	freeTable(hashTable);
	return 0;
}