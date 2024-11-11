#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedList LinkedList;

LinkedList* createList();

LinkedList* createCircle(int n);

int count(LinkedList* circularList, int m);