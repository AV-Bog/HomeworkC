#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

Node* createNode(const char* word) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }

    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

bool insert(Node** head, const char* word) {
    Node* current = *head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    Node* newNode = createNode(word);
    if (newNode == NULL) {
        return false;
    }

    *head = newNode;

    return true;
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

unsigned int hash(const char* word) {
    unsigned int hash_value = 0;
    int i = 0;
    while (word[i] != '\0') {
        hash_value = (hash_value * 31) + (unsigned char)(word[i]);
        i++;
    }
    return hash_value % TABLE_SIZE;
}

HashTable* createTable() {
    HashTable* hashTable = ñalloc(1, sizeof(HashTable));
    if (hashTable == NULL) {
        return NULL;
    }
    return hashTable;
}

bool insertWord(HashTable* hashTable, const char* word) {
    unsigned int index = hash(word);
    if (!insert(&(hashTable->table[index]), word)) {
        return false;
    }
    return true;
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
    int maxListLength = 0;
    int totalListLehgth = 0;
    int nonEmptyBuckets = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable->table[i];
        int listLength = 0;
        while (current != NULL) {
            listLength++;
            current = current->next;
        }
        if (listLength > 0) {
            nonEmptyBuckets++;
            totalListLehgth += listLength;
            if (listLength >= maxListLength) {
                maxListLength = listLength;
            }
            totalEntries += listLength;
        }
    }

    printf("Fill factor: %.2f\n", (float)totalEntries / TABLE_SIZE);
    printf("Max list lenght: %d\n", maxListLength);
    printf("Average list length: %.2f\n", (float)nonEmptyBuckets/totalListLehgth);
}