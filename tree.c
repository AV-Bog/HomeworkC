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
    Dictionary* tree = malloc(sizeof(Dictionary));
    tree->root = NULL;
    return tree;
}

Node* getNewNode(char* key, char* value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int height(struct Node* node) {
    return node == NULL ? 0 : node->height;
}

int getBalance(struct Node* root) {
    return root == NULL ? 0 : height(root->left) - height(root->right);
}

Node* rightRotate(Node* root) {
    Node* leftSubtree = root->left;
    if (leftSubtree->right != NULL) {
        Node* leftSubtreeRightSubtree = leftSubtree->right;

        leftSubtree->right = root;
        root->left = leftSubtreeRightSubtree;

        leftSubtree->height = max(height(leftSubtree->left), height(leftSubtree->right));
        root->height = max(height(root->left), height(root->right)) + 1;
    }
    else {
        leftSubtree->right = root;
        root->left = NULL;
        leftSubtree->height = max(height(leftSubtree->left), height(leftSubtree->right));
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

        rightSubtree->height = max(height(rightSubtree->left), height(rightSubtree->right));
        root->height = max(height(root->left), height(root->right)) + 1;
    }
    else {
        rightSubtree->left = root;
        root->right = NULL;
        rightSubtree->height = max(height(rightSubtree->left), height(rightSubtree->right));
        root->height = max(height(root->left), height(root->right)) + 1;
    }
    return rightSubtree;
}

Node* insertRecurtion(Node* root, char* key, char* value) {
    if (root == NULL) {
        return getNewNode(key, value);
    }

    if (strcmp(key, root->key) < 0) {
        root->left = insertRecurtion(root->left, key, value);
    }
    else if (strcmp(key, root->key) > 0) {
        root->right = insertRecurtion(root->right, key, value);
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

    else if (balance < -1 && strcmp(key, root->right->key) > 0) {
        return leftRotate(root);
    }

    else if (balance > 1 && strcmp(key, root->left->key) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    else if (balance < -1 && strcmp(key, root->right->key) < 0) {
        root->right = rightRotate(root->left);
        return leftRotate(root);
    }

    return root;
}

void insert(Dictionary* dictionary, char* key, char* value) {
    dictionary->root = insertRecurtion(dictionary->root, key, value);
}

void deleteRecursion(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteRecursion(root->left);
    deleteRecursion(root->right);
    free(root);
}

void deleteDictionary(Dictionary* dictionary) {
    deleteRecursion(dictionary->root);
    free(dictionary);
    return;
}
bool search(Node* root, char* key) {
    if (root == NULL) {
        return false;
    }
    else if (strcmp(key, root->key) > 0) {
        return search(root->right, key);
    }
    else if (strcmp(key, root->key) < 0) {
        return search(root->left, key);
    }
    else {
        return true;
    }
}

bool theKeyExists(Dictionary* dictionary, char* key) {
    return search(dictionary->root, key);
}
Node* findNodeByKey(Node* root, char* key) {
    if (strcmp(root->key, key) == 0) {
        return root;
    }
    else if (strcmp(key, root->key) < 0) {
        return findNodeByKey(root->left, key);
    }
    else {
        return findNodeByKey(root->right, key);
    }
}

void changeData(Dictionary* dictionary, char* key, char* newValue) {
    Node* temp = findNodeByKey(dictionary->root, key);
    temp->value = newValue;
}

char* searchGetValue(Node* root, char* key) {
    if (root == NULL) {
        return "NULL";
    }
    else if (strcmp(root->key, key) == 0) {
        return root->value;
    }
    else if (strcmp(root->key, key) > 0) {
        return searchGetValue(root->left, key);
    }
    else {
        return searchGetValue(root->right, key);
    }
}

char* getValue(Dictionary* dictionary, char* key) {
    return searchGetValue(dictionary->root, key);
}

struct Node* minValueNode(struct  Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteRootRecursion(Node* root, char* key) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(key, root->key) < 0) {
        root->left = deleteRootRecursion(root->left, key);
    }
    else if (strcmp(key, root->key) > 0) {
        root->right = deleteRootRecursion(root->right, key);
    }
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->right : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }
            free(temp);
        }

        else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;

            root->right = deleteRootRecursion(root->right, key);
        }
        return root;
    }

    (root)->height = 1 + max(height((root)->left), height((root)->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        (root)->left = leftRotate((root)->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        (root)->right = rightRotate((root)->right);
        return leftRotate(root);
    }

    return root;
}

void deleteViaKey(Dictionary* dictionary, char* key) {
    deleteRootRecursion(dictionary->root, key);
}