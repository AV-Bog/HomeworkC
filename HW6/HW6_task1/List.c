#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"

typedef struct ListElement {
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List {
    ListElement* head;
} List;

typedef ListElement* Position;

typedef int Value;

List* createList(void) {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    ListElement* head = calloc(1, sizeof(ListElement));
    if (head == NULL) {
        free(list);
        return NULL;
    }
    list->head = head;
    return list;
}

bool addElement(List* list, Position position, Value value) {
    ListElement* element = calloc(1, sizeof(ListElement));
    if (element == NULL) {
        return;
    }
    element->value = value;
    element->next = position->next;
    position->next = element;
    return true;
}

Value getValue(List* list, Position position) {
    assert(position != NULL);
    return position->value;
}

void setValue(List* list, Position position, Value value) {
    position->value = value;
}

Position first(List* list) {
    return list->head;
}

Position next(Position position) {
    return position->next;
}

bool deleteElement(List* list, Position position) {
    assert(position->next != NULL);
    List* ptr = position->next->next;
    free(position->next);
    position->next = ptr;
    return true;
}

bool isLast(List* list, Position position) {
    return position->next == NULL;
}

bool isValid(List* list, Position position) {
    return position != NULL;
}