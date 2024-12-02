#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#define TABLE_SIZE 1000

typedef struct Node {
	const char* word;
	int count;
	Node* next;
} Node;

typedef struct HashTable {
	Node* table[TABLE_SIZE];
} HashTable;

Node* create_node(const char* word) {
	Node* new_node = malloc(sizeof(Node));
	new_node->word = word;
	new_node->count = 1;
	new_node->next = NULL;
	return new_node;
}

void insert(Node** head, const char* word) {
	Node* current = *head;
	while (current != NULL) {
		if (strcmp(current->word, word) == 0) {
			current->count++;
			return;
		}
		current = current->next;
	}

	Node* new_node = create_node(word);
	if (*head != NULL) {
		new_node->next = *head;
		*head = new_node;
	}
	else {
		*head = new_node;
	}
	return;
}

void free_list(Node* head) {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}


unsigned int hash(const char* word) {
	unsigned int hash_value = 0;
	while (*word) {
		hash_value = (hash_value * 31) + (unsigned char)(*word++);
	}
	return hash_value % TABLE_SIZE;
}

HashTable* created_table() {
	HashTable* hashTable = malloc(sizeof(HashTable));
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable->table[i] = NULL;
	}
	return hashTable;
}

void insert_word(HashTable* hashTable, const char* word) {
	unsigned int index = hash(word);
	insert(&(hashTable->table[index]), word);
}

Node* search(HashTable* hashTable, const char* word) {
	unsigned int index = hash(word);
	Node* current = hashTable->table[index];
	while (current != NULL) {
		if (strcmp(current->word, word) == 0) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

void freeTable(HashTable* hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		free_list(hashTable->table[i]);
	}
	free(hashTable);
}

void printWordAndCount(HashTable* hashTable) {
	printf("Words and their frequencies: \n");
	for (int i = 0; i < TABLE_SIZE; i++) {
		Node* current = hashTable->table[i];
		while (current != 0) {
			printf("\"%s\": %d\n", current->word, current->count);
			current = current->next;
		}
	}
}

void CalculationAndDisplayOfStatistics(HashTable* hashTable) {
	int totalEntries = 0;
	int maxListLenght = 0;
	int totalListLehght = 0;
	int nonEmptyBuckets = 0;

	for (int i = 0; i < TABLE_SIZE; i++) {
		Node* current = hashTable->table[i];
		int listLenght = 0;
		while (current != NULL) {
			listLenght++;
			current = current->next;
		}
		if (listLenght > 0) {
			nonEmptyBuckets++;
			totalListLehght += listLenght;
			if (listLenght >= maxListLenght) {
				maxListLenght = listLenght;
			}
			totalEntries += listLenght;
		}
	}

	printf("Fill factor: %.2f\n", (float)totalEntries / TABLE_SIZE);
	printf("Max list lenght: %d\n", maxListLenght);
	printf("Average list length: %.2f\n", (float)nonEmptyBuckets/totalListLehght);
}