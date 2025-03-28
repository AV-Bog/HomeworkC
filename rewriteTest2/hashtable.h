#pragma once

// Hash table structure
typedef struct HashTable HashTable;

// Create table operation
HashTable* create_node();

// Hash value calculation operation
unsigned int hash(const char* word);

// Add operation
bool insert(HashTable* head, const char* word);

// Search operation
bool search(HashTable* hashTable, const char* word);

// Hash table delete operation
void freeTable(HashTable* hashTable);