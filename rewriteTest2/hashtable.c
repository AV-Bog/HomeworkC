#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"
#define TABLE_SIZE 1000

typedef struct HashTable {
	char** words;  
	bool* occupied;
} HashTable;

HashTable* create_node() {
	HashTable* new_node = malloc(sizeof(HashTable));
	if (!new_node) {
		return NULL;
	}

	new_node->words = malloc(TABLE_SIZE * sizeof(char*));
	new_node->occupied = malloc(TABLE_SIZE * sizeof(bool));
	if (new_node->words == NULL || new_node->occupied == NULL) {
		return NULL;
	}

	for (int i = 0; i < TABLE_SIZE; i++) {
		new_node->occupied[i] = false;
		new_node->words[i] = NULL;
	}

	return new_node;
}

unsigned int hash(const char* word) {
	unsigned int hash_value = 0;
	while (*word) {
		hash_value = (hash_value * 31) + (unsigned char)(*word++);
	}
	return hash_value % TABLE_SIZE;
}

bool insert(HashTable* hashTable, const char* word) {
	unsigned int index = hash(word);

	for (int i = 0; i < TABLE_SIZE; i++) {
		int probeIndex = (index + i) % TABLE_SIZE;

		if (!hashTable->occupied[probeIndex]) {
			hashTable->words[probeIndex] = strdup(word);
			hashTable->occupied[probeIndex] = true;
			return true;
		}

		if (strcmp(hashTable->words[probeIndex], word) == 0) {
			return false;
		}
	}
	return false;
}

bool search(HashTable* hashTable, const char* word) {
	unsigned int index = hash(word);
	
	for (int i = 0; i < TABLE_SIZE; i++) {
		int probeIndex = (index + i) % TABLE_SIZE;

		if (!hashTable->occupied[probeIndex]) {
			return false;
		}

		if (strcmp(hashTable->words[probeIndex], word) == 0) {
			return true;
		}
	}

	return false;
}

void freeTable(HashTable* hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable->occupied[i]) {
			free(hashTable->words[i]);
		}
	}
	free(hashTable->words);
	free(hashTable->occupied);
	free(hashTable);
}

bool tests();

int main() {
	if (!tests()) {
		return -1;
	}

	return 0;
}

bool tests() {
	HashTable* hashTable = create_node();
	if (!hashTable) {
		printf("Failed to create hash table.\n");
		return 1;
	}

	if (insert(hashTable, "dog")) {
		printf("Error: Failed to add item");
		return false;
	}

	if (!search(hashTable, "dog")) {
		printf("Error: An existing element in the table was not found");
		return false;
	}

	if (!search(hashTable, "cat")) {
		printf("Error: Found non-existent element");
		return false;
	}

	freeTable(hashTable);

	return true;
}