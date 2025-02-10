#pragma once

typedef struct {
    int key;
    char* value;
} NodeValue;

typedef struct Node Node;

// Create a node
Node* createTreeNode(NodeValue value, int* errorCode);

// Inserts a new node into the tree at the appropriate position based on key comparison.
void insertNode(Node* node, NodeValue value, int* error);

// Delete element by key
void deleteNodeByKey(Node* node, int key);

// Remove tree
void deleteTree(Node* node);