#pragma once

// Structure for storing a dictionary
typedef struct Dictionary Dictionary;

// Structure for storing a node in the dictionary
typedef struct Node Node;

// Creating a structure for storing a dictionary
Dictionary* createDictionary();

// Node insertion function
bool insert(Dictionary* dictionary, const char* key, const char* value);

// The function of verifying the existence of a key in the tree
bool theKeyExists(Dictionary* dictionary, char* key);

// The function of deleting a variable by key
void deleteViaKey(Dictionary* dictionary, char* key);

// Searching for the value of a variable by key
char* getValue(Dictionary* dictionary, char* key);

// Dictionary deletion function
void deleteDictionary(Dictionary* dictionary);

// Function for checking the balance of the dictionary
bool checkBalance(Dictionary* dictionary);