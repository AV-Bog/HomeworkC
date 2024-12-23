#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

typedef struct ListElement {
    char* value;
    struct ListElement* next;
} ListElement;

typedef struct List {
    ListElement* head;
} List;

List* createList(void) {
    return calloc(1, sizeof(List));
}

bool insertValueAtTheEnd(List* list, char* value) {
    ListElement* element = malloc(sizeof(ListElement));
    if (element == NULL) {
        return false;
    }
    element->value = _strdup(value);
    element->next = NULL;
    if (list->head == NULL) {
        list->head = element;
        return true;
    }
    ListElement* tmp = list->head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = element;
    return true;
}

bool addStringWithA(List** list) {
    List* newList = createList();
    ListElement* element = (*list)->head;
    ListElement* tmp = (*list)->head;
    while (element != NULL) {
        insertValueAtTheEnd(newList, element->value);
        element = element->next;
    }

    while (tmp != NULL) {
        if (tmp->value[0] == 'a') {
            insertValueAtTheEnd(newList, tmp->value);
        }
        tmp = tmp->next;
    }
    deleteList(*list);
    *list = newList;
    return true;
}

void deleteList(List* list) {
    ListElement* current = list->head;
    while (current->next != NULL) {
        ListElement* tmp = current;
        current = current->next;
        free(tmp->value);
        free(tmp);
    }
    free(current->value);
    free(current);
}

//get listLength
int listLength(List* list) {
    ListElement* element = list->head;
    int length = 1;
    while (element->next != NULL) {
        ++length;
        element = element->next;
    }
    return length;
}

void printList(List* list) {
    ListElement* element = list->head;
    while (element != NULL) {
        printf("%s", element->value);
        element = element->next;
    }
    printf("\n");
}

ListElement* getHead(List* list) {
    return list->head;
}

ListElement* getNext(ListElement* element) {
    return element->next;
}

char* getValue(ListElement* element) {
    return element->value;
}