#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTree BinaryTree;

void insert(BinaryTree* dictionary, int value);

BinaryTree* createTree();

void deleteTree(BinaryTree* dictionary);

void ordering(int array[], int length);