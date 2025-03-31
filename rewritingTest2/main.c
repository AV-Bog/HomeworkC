#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

bool testAddStringWithA();

int main(void) {
    if (!testAddStringWithA()) {
        printf("Test is failed\n");
        return -1;
    }
    List* list = createList();
    insertValueAtTheEnd(list, "abc");
    insertValueAtTheEnd(list, "def");
    insertValueAtTheEnd(list, "awe");
    printList(list);
    addStringWithA(&list);
    printList(list);
    deleteList(list);
    return 0;
}

//for the test: compares the lists
bool listTheSame(List* list1, List* list2) {
    ListElement* element1 = getHead(list1);
    ListElement* element2 = getHead(list2);
    while (getNext(element1) != NULL && getNext(element2) != NULL) {
        if (strcmp(getValue(element1), getValue(element2)) != 0) {
            return false;
        }
        element1 = getNext(element1);
        element2 = getNext(element2);
    }
    return getNext(element1) == NULL && getNext(element2) == NULL;
}

bool testAddStringWithA() {
    List* testList1 = createList();
    List* testList2 = createList();
    insertValueAtTheEnd(testList1, "a");
    insertValueAtTheEnd(testList1, "b");
    insertValueAtTheEnd(testList1, "c");
    insertValueAtTheEnd(testList1, "abc");
    addStringWithA(&testList1);

    insertValueAtTheEnd(testList2, "a");
    insertValueAtTheEnd(testList2, "b");
    insertValueAtTheEnd(testList2, "c");
    insertValueAtTheEnd(testList2, "abc");
    insertValueAtTheEnd(testList2, "a");
    insertValueAtTheEnd(testList2, "abc");

    if (!listTheSame(testList1, testList2)) {
        printf("The lists are not equal\n");
        deleteList(testList1);
        deleteList(testList2);
        return false;
    }
    deleteList(testList1);
    deleteList(testList2);
    return true;
}