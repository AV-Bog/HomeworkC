#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

typedef struct LinkedList LinkedList;

void insert(char* number, char* name, LinkedList* linkedList);

void printList(LinkedList* linkedList);

LinkedList* createList();

void mergeSort(LinkedList* linkedList, bool byName);

void split(Node* head, Node** front, Node** back);

void mergeSortRecursion(Node** head, bool byName);

bool isSorted(LinkedList* linkedList, bool byName);

Node* mergeSortedLists(Node* front, Node* back, bool byName);

void deleteList(LinkedList* list);