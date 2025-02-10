#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

typedef struct Node {
    char* key;
    char* value;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

struct Dictionary {
    Node* root;
};

Dictionary* createDictionary() {
    Dictionary* tree = calloc(1, sizeof(Dictionary));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

Node* getNewNode(char* key, char* value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int height(Node* node) {
    return node == NULL ? 0 : node->height;
}

int getBalance(Node* root) {
    return root == NULL ? 0 : height(root->left) - height(root->right);
}

Node* rightRotate(Node* root) {
    Node* leftSubtree = root->left;
    if (leftSubtree->right != NULL) {
        Node* leftSubtreeRightSubtree = leftSubtree->right;
        leftSubtree->right = root;
        root->left = leftSubtreeRightSubtree;
        leftSubtree->height = max(height(leftSubtree->left), height(leftSubtree->right)) + 1;
        root->height = max(height(root->left), height(root->right)) + 1;
    }
    else {
        leftSubtree->right = root;
        root->left = NULL;
        leftSubtree->height = max(height(leftSubtree->left), height(leftSubtree->right)) + 1;
        root->height = max(height(root->left), height(root->right)) + 1;
    }
    return leftSubtree;
}

Node* leftRotate(Node* root) {
    Node* rightSubtree = root->right;
    if (rightSubtree->left != NULL) {
        Node* rightSubtreeLeftSubtree = rightSubtree->left;
        rightSubtree->left = root;
        root->right = rightSubtreeLeftSubtree;
        rightSubtree->height = max(height(rightSubtree->left), height(rightSubtree->right)) + 1;
        root->height = max(height(root->left), height(root->right)) + 1;
    }
    else {
        rightSubtree->left = root;
        root->right = NULL;
        rightSubtree->height = max(height(rightSubtree->left), height(rightSubtree->right)) + 1;
        root->height = max(height(root->left), height(root->right)) + 1;
    }
    return rightSubtree;
}

Node* insertRecursive(Node* root, char* key, char* value) {
    if (root == NULL) {
        return getNewNode(key, value);
    }

    if (strcmp(key, root->key) < 0) {
        root->left = insertRecursive(root->left, key, value);
    }
    else if (strcmp(key, root->key) > 0) {
        root->right = insertRecursive(root->right, key, value);
    }
    else {
        free(root->value);
        root->value = strdup(value);
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && strcmp(key, root->left->key) < 0) {
        return rightRotate(root);
    }

    if (balance < -1 && strcmp(key, root->right->key) > 0) {
        return leftRotate(root);
    }

    if (balance > 1 && strcmp(key, root->left->key) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && strcmp(key, root->right->key) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void insert(Dictionary* dictionary, const char* key, const char* value) {
    dictionary->root = insertRecursive(dictionary->root, key, value);
}

void deleteRecursion(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteRecursion(root->left);
    deleteRecursion(root->right);
    free(root->key);
    free(root->value);
    free(root);
}

void deleteDictionary(Dictionary* dictionary) {
    deleteRecursion(dictionary->root);
    free(dictionary);
}

bool search(Node* root, char* key) {
    if (root == NULL) {
        return false;
    }
    if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    }
    if (strcmp(key, root->key) > 0) {
        return search(root->right, key);
    }
    return true;
}

bool theKeyExists(Dictionary* dictionary, char* key) {
    return search(dictionary->root, key);
}

Node* findNodeByKey(Node* root, char* key) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(key, root->key) == 0) {
        return root;
    }
    return strcmp(key, root->key) < 0 ? findNodeByKey(root->left, key) : findNodeByKey(root->right, key);
}

char* searchGetValue(Node* root, char* key) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(root->key, key) == 0) {
        return root->value;
    }
    return strcmp(root->key, key) < 0 ? searchGetValue(root->left, key) : searchGetValue(root->right, key);
}

char* getValue(Dictionary* dictionary, char* key) {
    return searchGetValue(dictionary->root, key);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteRootRecursion(Node* root, char* key) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(key, root->key) < 0) {
        root->left = deleteRootRecursion(root->left, key);
    }
    else if (strcmp(key, root->key) > 0) {
        root->right = deleteRootRecursion(root->right, key);
    }
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                free(root->key);
                free(root->value);
                free(root);
                return NULL;
            }
            else {
                *root = *temp;
                free(temp->key);
                free(temp->value);
                free(temp);
            }
        }
        else {
            Node* temp = minValueNode(root->right);
            free(root->key);
            free(root->value);
            root->key = temp->key;
            root->value = temp->value;
            root->right = deleteRootRecursion(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return NULL;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void deleteViaKey(Dictionary* dictionary, char* key) {
    dictionary->root = deleteRootRecursion(dictionary->root, key);
}
