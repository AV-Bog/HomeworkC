#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BinaryTree {
    Node* root;
} BinaryTree;

Node* getNewNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertRecurion(Node** root, int value) {
    if (*root == NULL) {
        *root = getNewNode(value);
    }
    else if ((*root)->value <= value) {
        (*root)->left = insertRecurion(&(*root)->left, value);
    }
    else {
        (*root)->right = insertRecurion(&(*root)->right, value);
    }
    return *root;
}

void insert(BinaryTree* dictionary, int value) {
    insertRecurion(&(dictionary->root), value);
}

BinaryTree* createTree() {
    BinaryTree* tree = malloc(sizeof(BinaryTree));
    tree->root = NULL;
    return tree;
}

void deleteRecursion(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteRecursion(root->left);
    deleteRecursion(root->right);
    free(root);
}

void deleteTree(BinaryTree* dictionary) {
    deleteRecursion(dictionary->root);
}

void traversalOrdering(Node* root, int array[], int* index) {
    if (root == NULL) {
        return;
    }
    traversalOrdering(root->left, array, index);
    array[*index] = root->value;
    ++(*index);
    traversalOrdering(root->right, array, index);
}

void ordering(int array[], int length) {
    BinaryTree* tree = createTree();
    for (int i = 0; i < length; ++i) {
        insert(tree, array[i]);
    }
    int index = 0;
    ordering(tree->root, array, &index);
    deleteRecursion(tree->root);
}