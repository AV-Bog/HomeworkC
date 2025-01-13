#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "list.h"

void printOptions();
void printList(List* list);
void addElementToSortedList(List* list, Value value);
void deleteElementFromSortedList(List* list, Value value);
bool listTest();

int main() {
    if (!listTest()) return -1;

    List* list = createList();
    Position position = first(list);
    printOptions();

    int option = -1;
    while (option != 0) {
        printf("Enter option number: ");
        if (scanf("%d", &option) != 1) {
            printf("Error input\n");
            return 1;
        }
        switch (option) {
        case 0: {
            free(list);
            break;
        }
        case 1: {
            Value value = 0;
            printf("Enter the value for the adding: ");
            scanf("%d", &value);
            addElementToSortedList(list, value);
            break;
        }
        case 2: {
            Value place = 0;
            printf("Enter the value for the deleting: ");
            scanf("%d", &place);
            deleteElementFromSortedList(list, place);
            break;
        }
        case 3: {
            printList(list);
            break;
        }
        default:
            printf("There is no such operation\n");
            return 0;
        }
    }
    return 0;
}

void printOptions() {
    printf("All options:\n");
    printf("0 - Exit\n");
    printf("1 - Add a value to the sorted list\n");
    printf("2 - Delete a value from list\n");
    printf("3 - Print list\n");
}

void printList(List* list) {
    Position position = first(list);
    position = next(position);
    while (position != NULL) {
        printf("%d ", getValue(list, position));
        position = next(position);
    }
    printf("\n");
}

void addElementToSortedList(List* list, Value value) {
    Position position = first(list);
    while (!isLast(list, position) && getValue(list, next(position)) <= value) {
        position = next(position);
    }
    addElement(list, position, value);
}

void deleteElementFromSortedList(List* list, Value value) {
    Position position = first(list);
    while (!isLast(list, position)) {
        if (getValue(list, next(position)) == value) {
            deleteElement(list, position);
            break;
        }
        if (getValue(list, position) > value) {
            break;
        }
        position = next(position);
    }
}

bool listTest() {
    List* list = createList();
    if (list == NULL) {
        printf("Error creating the List structure");
        return false;
    }

    Position position = first(list);
    addElement(list, position, 17);
    if (!isValid(list, position)) {
        printf("Error when adding to the List structure (position = 0)");
        deleteList(list);
        return false;
    }

    position = next(position);
    if (getValue(list, position) != 17) {
        printf("Error when adding to the List structure (the added value does not match the one being added)");
        deleteList(list);
        return false;
    }

    addElement(list, position, 52);
    position = next(position);
    addElement(list, position, 63);
    setValue(list, position, 71);
    if (getValue(list, position) != 71) {
        printf("multiple addition error");
        deleteList(list);
        return false;
    }

    return true;
}