#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "hashtable.h"

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