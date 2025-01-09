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

// Retrieves the left child of the given node.
Node* getLeftChild(Node* node);

// Retrieves the right child of the given node.
Node* getRightChild(Node* node);

// Find element by key
Node* findElementByKey(Node* node, int key);

// Check if an element is present in a tree
bool isNodePresent(Node* node, int key);

// Get left child
Node* getLeftChild(Node* node);

// Get right child
Node* getRightChild(Node* node);

// Get value from node
NodeValue getNodeValue(Node* node);

// Add values ​​to node
void setNodeValue(Node* node, NodeValue value);

// Delete element by key
void deleteNodeByKey(Node* node, int key);

// Remove tree
void deleteTree(Node* node);