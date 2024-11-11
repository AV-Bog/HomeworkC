#pragma once
#include <stdbool.h>

typedef struct ListElement ListElement;

typedef struct List List;

typedef ListElement* Position;

typedef int Value;

List* createList(void);

bool addElement(List* list, Position position, Value value);

bool deleteElement(List* list, Position position);

Value getValue(List* list, Position position);

void setValue(List* list, Position position, Value value);

Position first(List* list);

Position next(Position position);

bool isLast(List* list, Position position);

bool isValid(List* list, Position position);