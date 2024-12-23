#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Dictionary Dictionary;
Dictionary* createDictionary();
void insert(Dictionary* dictionary, char* key, char* value);
bool theKeyExists(Dictionary* dictionary, char* key);
void deleteViaKey(Dictionary* dictionary, char* key);
char* getValue(Dictionary* dictionary, char* key);
void changeData(Dictionary* dictionary, char* key, char* newValue);
void deleteDictionary(Dictionary* dictionary);