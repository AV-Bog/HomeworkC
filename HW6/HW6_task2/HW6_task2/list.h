#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedList LinkedList;

// A function for creating a linked list (used when creating a cyclic linked list)
LinkedList* createList(void);

// Creates a circular list with elements 1...n;
LinkedList* createCircle(int n);

// The account of Josephus
int count(LinkedList* circularList, int m);

// Function to remove cyclic list
void deleteCircleList(LinkedList* list);