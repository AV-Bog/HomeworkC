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
    newNode->value = value;
    return newNode;
}

void attachLeftChild(Node* node, Node* child) {
    node->leftChild = child;
}

void attachRightChild(Node* node, Node* child) {
    node->rightChild = child;
}

void insertNode(Node* node, NodeValue value, int* error) {
    if (node->value.key == value.key) {
        char* oldValue = node->value.value;
        node->value = value;
        free(oldValue);
        return;
    }
    if (node->value.key > value.key && !node->leftChild) {
        Node* newNode = createTreeNode(value, error);
        attachLeftChild(node, newNode);
    }
    else if (node->value.key < value.key && !node->rightChild) {
        Node* newNode = createTreeNode(value, error);
        attachRightChild(node, newNode);
    }
    else if (node->value.key > value.key) {
        insertNode(node->leftChild, value, error);
    }
    else if (node->value.key < value.key) {
        insertNode(node->rightChild, value, error);
    }
}

Node* getLeftChild(Node* node) {
    return node->leftChild;
}

Node* getRightChild(Node* node) {
    return node->rightChild;
}

NodeValue getNodeValue(Node* node) {
    return node->value;
}

void setNodeValue(Node* node, NodeValue value) {
    node->value = value;
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

Node* findElementByKey(Node* node, int key) {
    if (!node) {
        return NULL;
    }
    else if (node->value.key == key) {
        return node;
    }
    else if (node->value.key > key) {
        return findElementByKey(node->leftChild, key);
    }

    return findElementByKey(node->rightChild, key);
}

bool isNodePresent(Node* node, int key) {
    return findElementByKey(node, key) != NULL;
}

Node* findParentNodeForRemoval(Node* node, int key) {
    if (!node || node->value.key == key) {
        return node;
    }
    if ((node->leftChild && node->leftChild->value.key == key) || (node->rightChild && node->rightChild->value.key == key)) {
        return node;
    }
    if (node->value.key > key) {
        return findParentNodeForRemoval(node->leftChild, key);
    }

    return findParentNodeForRemoval(node->rightChild, key);
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