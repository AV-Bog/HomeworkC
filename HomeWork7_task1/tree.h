#pragma once

// Structure for storing a dictionary
typedef struct Dictionary Dictionary;

typedef struct Node Node;

// Creating a structure for storing a dictionary
Dictionary* createDictionary();

// Node insertion function
void insert(Dictionary* dictionary, const char* key, const char* value);

// The function of verifying the existence of a key in the tree
bool theKeyExists(Dictionary* dictionary, char* key);

// The function of deleting a variable by key
void deleteViaKey(Dictionary* dictionary, char* key);

// Searching for the value of a variable by key
char* getValue(Dictionary* dictionary, char* key);

// Dictionary deletion function
void deleteDictionary(Dictionary* dictionary);