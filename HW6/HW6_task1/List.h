#pragma once
#include <stdbool.h>

typedef struct ListElement ListElement; // List element structure
typedef struct List List; // List structure
typedef ListElement* Position; // Position type, representing a pointer to a ListElement
typedef int Value; 

// Creates and returns a new, empty list
List* createList(void);

// Adds a new element with the given value at the specified position in the list
bool addElement(List* list, Position position, Value value);

// Deletes the element at the specified position in the list
bool deleteElement(List* list, Position position);

// Retrieves the value of the element at the specified position in the list
Value getValue(List* list, Position position);

// Sets the value of the element at the specified position in the list
void setValue(List* list, Position position, Value value);

// Returns the first position (head) of the list
Position first(List* list);

// Returns the next position after the specified position in the list
Position next(Position position);

// Checks if the given position is the last position in the list
bool isLast(List* list, Position position);

// Checks if the given position is valid within the list
bool isValid(List* list, Position position);

// Clearing memory from the list
void deleteList(List* list);