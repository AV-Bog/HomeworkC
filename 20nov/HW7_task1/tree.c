#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

typedef struct Node {
	int data;
	char operation;
	struct Node *left;
	struct Node *right;
} Node;

typedef struct ParseTree {
	Node *root;
} ParseTree;

ParseTree* createParseTree() {
	ParseTree* tree = malloc(sizeof(ParseTree));
	if (tree == NULL) {
		printf("Out of memory!\n");
		exit(1);
	}
	tree->root = NULL;
	return tree;
}

bool nextIsDigit(char string[], int position) {
	return (string[position + 1] != ' ' && string[position + 1] != '+' && string[position + 1] != '*' && string[position + 1] != '/' && string[position + 1] != '(' && string[position + 1] != ')');
}

Node* parseTreeRecursion(char string[], int *position) {
	(*position) += 1;
	while (string[*position] == ' ' || string[*position] == '(' || string[*position] == ')') {
		(*position) += 1;
	}

	Node* root = malloc(sizeof(Node));
	if (root == NULL) {
		printf("Out of memory\n");
		exit(1);
	}

	if (string[*position] == '+' || string[*position] == '-' || string[*position] == '*' || string[*position] == '/') {
		//handling negative numbers
		if (string[*position] == '-' && nextIsDigit(string, *position)) {
			char* number = malloc(sizeof(char) * 8);
			int i = 2;
			number[0] = '-';
			number[1] = string[(*position) + 1];
			(*position) += 1;

			while (nextIsDigit(string, *position)) {
				number[i] = string[(*position) + 1];
				(*position) += 1;
				i++;
			}
			int intNumber = atoi(number);

			root->data = intNumber;
			root->operation = NULL;
		}
		else {
			root->operation = string[*position];
			root->data = NULL;
			root->right = parseTreeRecursion(string, position);
			root->left = parseTreeRecursion(string, position);
		}
	}

	else {
		char* number = malloc(sizeof(char) * 8);
		int i = 1;
		
		number[0] = string[*position];
		while (nextIsDigit(string, *position)) {
			number[i] = string[(*position) + 1];
			(*position) += 1;
			i++;
		}
		int intNumber = atoi(number);
		root->data = intNumber;
		root->operation = NULL;
		
	}
	return root;
}

ParseTree* buildParseTree(char string[]) {
	ParseTree* temp = createParseTree();
	int position = 0;
	temp->root = parseTreeRecursion(string, &position);
	return temp;
}

int calculateExpressionRecursion(Node* root) {
	if (root->operation == '+') {
		return calculateExpressionRecursion(root->left) + calculateExpressionRecursion(root->right);
	}
	else if (root->operation == '-') {
		return calculateExpressionRecursion(root->left) - calculateExpressionRecursion(root->right);
	}	
	else if (root->operation == '*') {
		return calculateExpressionRecursion(root->left) * calculateExpressionRecursion(root->right);
	}	
	else if (root->operation == '/') {
		return calculateExpressionRecursion(root->left) / calculateExpressionRecursion(root->right);
	}

	else {
		return root->data;
	}
}

int calculationExpression(ParseTree* tree) {
	return calculateExpressionRecursion(tree->root);
}

void printRoot(Node* node) {
	if (node == NULL) {
		printf("empty tree");
	}
	if (node->data == NULL) {
		printf(" (");
		printf("%c", node->operation);
		printRoot(node->right);
		printRoot(node->left);
		
		printf(" ) ");
	}
	else {
		printf(" %d", node->data);
	}
}

void printTree(ParseTree* ParseTree) {
	printf("Expression: ");
	printRoot(ParseTree->root);
	printf("\n");
}

void postorderRecursionDelete(Node* root) {
	if (root == NULL) {
		return;
	}
	postorderRecursionDelete(root->left);
	postorderRecursionDelete(root->right);
	free(root);
}

void deleteParseTree(ParseTree* ParseTree) {
	postorderRecursionDelete(ParseTree->root);
}