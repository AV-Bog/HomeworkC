#include <stdbool.h>
#include <string.h>
#include "list.h"

typedef struct Node {
    char* number;
    char* name;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* createList() {
    LinkedList* linkedList = malloc(sizeof(LinkedList));
    linkedList->head = NULL;
    return linkedList;
}

void printList(LinkedList* linkedList) {
    Node* temp = linkedList->head;
    if (temp == NULL) {
        printf("The list is empty!\n");
        return;
    }
    while (temp->next != NULL) {
        printf("%s ", temp->name);
        printf("%s \n", temp->number);
        temp = temp->next;
    }
}

bool isSorted(LinkedList* linkedList, bool byName) {
    if (byName) {
        Node* temp = linkedList->head;
        while (temp->next != NULL) {
            if (strcmp(temp->name, temp->next->name) > 0) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
    else {
        Node* temp = linkedList->head;
        while (temp->next != NULL) {
            if (strcmp(temp->number, temp->next->number) > 0) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }
}

void deleteList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        free(temp->name);
        free(temp->next);
        free(temp->number);
        temp = temp->next;
    }
    free(temp);
}

void insert(char* number, char* name, LinkedList* linkedList) {
    Node* temp = malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    temp->number = number;
    temp->name = name;
    temp->next = linkedList->head;
    linkedList->head = temp;
}

void mergeSort(LinkedList* linkedList, bool byName) {
    mergeSortRecursion(&(linkedList->head), byName);
}

void mergeSortRecursion(Node** head, bool byName) {
    if ((*head) == NULL || (*head)->next == NULL) {
        return;
    }

    Node* front;
    Node* back;
    split(*head, &front, &back);

    mergeSortRecursion(&front, byName);
    mergeSortRecursion(&back, byName);
    *head = mergeSortedLists(front, back, byName);
}

void split(Node* head, Node** front, Node** back) {
    Node* temp = head;
    Node* count = head;
    while (count->next != NULL) {
        count = count->next;
    }

    *front = temp->next;
    *back = head;
    temp->next = NULL;
}

Node* mergeSortedLists(Node* front, Node* back, bool byName) {
    Node* temp = NULL;

    if (front == NULL) {
        return back;
    }
    if (back == NULL) {
        return front;
    }

    if (byName) {
        if (strcmp(front->name, back->name) < 0) {
            temp = front;
            temp->next = mergeSortedLists(front->next, back, byName);
        }
        else {
            temp = back;
            temp->next = mergeSortedLists(front, back->next, byName);
        }
        return temp;
    }
    else {
        if (strcmp(front->number, back->number) < 0) {
            temp = front;
            temp->next = mergeSortedLists(front->next, back, byName);
        }
        else {
            temp = back;
            temp->next = mergeSortedLists(front, back->next, byName);
        }
        return temp;
    }
}