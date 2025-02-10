#pragma once

// Forward declaration of Node and HashTable structures.
typedef struct Node Node;
typedef struct HashTable HashTable;

// Hash function to compute an hash index for a given word.
unsigned int hash(const char* word);

// Function to create a new hash table.
HashTable* createTable();

// Function to insert a word into the hash table.
bool insertWord(HashTable* hashTable, const char* word);

// Function to search for a word in the hash table.
Node* search(HashTable* hashTable, const char* word);

// Function to free the memory allocated for the hash table.
void freeTable(HashTable* hashTable);

void printWordAndCount(HashTable* hashTable);

void CalculationAndDisplayOfStatistics(HashTable* hashTable);