#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Dictionary Dictionary;
Dictionary* createDictionary();
void insert(Dictionary* dictionary, int key, char* value);
bool theKeyExists(Dictionary* dictionary, int key);
void deleteViaKey(Dictionary* dictionary, int key);
char* getValue(Dictionary* dictionary, int key);
void changeData(Dictionary* dictionary, int key, char* newData);
void deleteDictionary(Dictionary* dictionary);
