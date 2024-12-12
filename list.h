#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
Node* create_node(const char* word);
void insert(Node** head, const char* word);
void free_list(Node* head);

typedef struct HashTable HashTable;
unsigned int hash(const char* word);
HashTable* created_table();
void insert_word(HashTable* hashTable, const char* word);
Node* search(HashTable* hashTable, const char* word);
void freeTable(HashTable* hashTable);