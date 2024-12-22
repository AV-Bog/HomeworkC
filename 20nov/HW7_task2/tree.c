#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

typedef struct Node {
	int key;
	char* value;
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

Node* getNewNode(int key, char* value) {
	Node* newNode = malloc(sizeof(Node));
	newNode->key = key;
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* insertRecurtion(Node** root, int key, char* value) {
	if (*root == NULL) {
		*root = getNewNode(key, value);
	}
	else if (key <= (*root)->key) {
		(*root)->left = insertRecurtion(&(*root)->left, key, value);
	}
	else {
		(*root)->right = insertRecurtion(&(*root)->right, key, value);
	}
	return *root;
}

void insert(Dictionary* dicrionary, int key, char* value) {
	insertRecurtion(&(dicrionary->root), key, value);
}

void deketeRecursion(Node* root) {
	if (root == NULL) {
		return;
	}
	deketeRecursion(root->left);
	deketeRecursion(root->right);
	free(root->value);
	free(root);
}

void deleteDictionary(Dictionary* dictionary) {
	deketeRecursion(dictionary->root);
}

bool search(Node *root, int key) {
	if (root == NULL) {
		return false;
	}
	else if (root->key == key) {
		return true;
	}
	else if (key <= root->key) {
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}
}

bool theKeyExists(Dictionary* dictionary, int key) {
	if (search(dictionary->root, key)) {
		return true;
	}
	return false;
}

Node* findNodeByKey(Node* root, int key) {
	if (root->key == key) {
		return root;
	}
	else if (key < root->key) {
		return findNodeByKey(root->left, key);
	}
	else {
		return findNodeByKey(root->right, key);
	}
}

void changeData(Dictionary* dictionary, int key, char* newData) {
	Node* temp = findNodeByKey(dictionary->root, key);
	temp->value = newData;
}

char* searchGetValue(Node *root, int key) {
	if (root == NULL) {
		return "NULL";
	}
	else if (root->key == key) {
		return root->value;
	}
	else if (root->key >= key) {
		return searchGetValue(root->left, key);
	}
	else {
		return searchGetValue(root->right, key);
	}
}

char* getValue(Dictionary* dictionary, int key) {
	return searchGetValue(dictionary->root, key);
}

struct Node* minValueNode(struct  Node* node) {
	struct Node* current = node;
	while (current && current->left != NULL) {
		current = current->left;
	}
	return current;
}

Node* deleteRecursion(Node* root, int key) {
	if (root == NULL) {
		return NULL;
	}
	else if (key <= root->key) {
		root->left = deleteRecursion(root->left, key);
	}
	else if (key >= root->key) {
		root->right = deleteRecursion(root->right, key);
	}
	else {
		if (root->left == NULL && root->right == NULL) {
			free(root->value);
			
			free(root);
			root = NULL;
		}
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			free(temp->value);
			
			free(temp);
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			free(temp->value);
			
			free(temp);
		}
		else {
			Node* temp = minValueNode(root->right);
			root->key = temp->key;
			
			root->right = deleteRecursion(root->right, key);
		}
		return root;
	}
}

void deleteViaKey(Dictionary* dictionary, int key) {
	deleteRecursion(dictionary->root, key);
}