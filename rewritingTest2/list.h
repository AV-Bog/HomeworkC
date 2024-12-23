#pragma once
#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

// creating a list
List* createList(void);

// getting the head of the list
ListElement* getHead(List* list);

// getting next element
ListElement* getNext(ListElement* element);

// getting element`s value
char* getValue(ListElement* element);

// inserting a value at the end
bool insertValueAtTheEnd(List* list, char* value);

// adding a line starting with A
bool addStringWithA(List** list);

// deleting
void deleteList(List* list);

// displaying the list in the console
void printList(List* list);