#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "searchTree.h"

typedef struct Node {
    NodeValue value;
    Node* leftChild;
    Node* rightChild;
} Node;

Node* createTreeNode(NodeValue value, int* errorCode) {
    Node* newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        *errorCode = 1;
        return NULL;
    }

    newNode->value.key = value.key;
    newNode->value.value = malloc(strlen(value.value) + 1);
    if (newNode->value.value == NULL) {
        free(newNode);
        *errorCode = 1;
        return NULL;
    }
    strcpy(newNode->value.value, value.value);

    return newNode;
}

void insertNode(Node* node, NodeValue value, int* error) {
    if (node->value.key == value.key) {
        free(node->value.value);
        node->value.value = malloc(strlen(value.value) + 1);
        if (node->value.value == NULL) {
            *error = 1;
        }
        else {
            strcpy(node->value.value, value.value);
        }
        return;
    }
    if (node->value.key > value.key && !node->leftChild) {
        Node* newNode = createTreeNode(value, error);
        if (*error == 1) return;
        node->leftChild = newNode;
    }
    else if (node->value.key < value.key && !node->rightChild) {
        Node* newNode = createTreeNode(value, error);
        if (*error == 1) return;
        node->rightChild = newNode;
    }
    else if (node->value.key > value.key) {
        insertNode(node->leftChild, value, error);
    }
    else if (node->value.key < value.key) {
        insertNode(node->rightChild, value, error);
    }
}

Node* getMinNodeOfRightSubtree(Node* node) {
    Node* parentOfMin = node->rightChild;
    Node* minNode = parentOfMin->leftChild ? parentOfMin->leftChild : parentOfMin;
    while (minNode->leftChild) {
        parentOfMin = minNode;
        minNode = minNode->leftChild;
    }
    parentOfMin->leftChild = minNode->rightChild ? minNode->rightChild : NULL;
    return minNode;
}

void deleteNodeByKey(Node* node, int key) {
    Node* parent = findParentNodeForRemoval(node, key);
    Node* nodeToDelete = NULL;
    if (!parent) return;

    if (parent->leftChild && parent->leftChild->value.key == key) {
        nodeToDelete = parent->leftChild;
    }
    else if (parent->rightChild && parent->rightChild->value.key == key) {
        nodeToDelete = parent->rightChild;
    }

    if (nodeToDelete) {
        Node* replacementNode = NULL;
        if (!nodeToDelete->leftChild && !nodeToDelete->rightChild) {
            replacementNode = NULL;
        }
        else if (nodeToDelete->leftChild && !nodeToDelete->rightChild) {
            replacementNode = nodeToDelete->leftChild;
        }
        else if (!nodeToDelete->leftChild && nodeToDelete->rightChild) {
            replacementNode = nodeToDelete->rightChild;
        }
        else {
            replacementNode = getMinNodeOfRightSubtree(nodeToDelete);
            replacementNode->leftChild = nodeToDelete->leftChild;
        }

        if (parent->leftChild == nodeToDelete) {
            parent->leftChild = replacementNode;
        }
        else {
            parent->rightChild = replacementNode;
        }

        free(nodeToDelete->value.value);
        free(nodeToDelete);
    }
}

void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    free(node->value.value);
    free(node);
}
