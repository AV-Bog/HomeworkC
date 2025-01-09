﻿#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "searchTree.h"

void displayOperations() {
    printf("Choose an operation:\n");
    printf("0 - Exit\n");
    printf("1 - Add a key-value pair to the dictionary\n");
    printf("2 - Retrieve the value associated with a key\n");
    printf("3 - Check if a key exists in the dictionary\n");
    printf("4 - Remove a key-value pair from the dictionary\n");
}

int main() {
    displayOperations();

    int errorCode = 0;
    char* initialValue = calloc(20, sizeof(char));
    if (initialValue == NULL) {
        printf("Error: Failed to allocate memory for the initial value.\n");
        return 1;
    }

    NodeValue rootNodeValue = { 1, initialValue };
    Node* tree = createTreeNode(rootNodeValue, &errorCode);

    if (errorCode == 1) {
        printf("Error: Failed to create the root node.\n");
        free(initialValue);
        return 1;
    }

    int operation = -1;
    while (operation != 0) {
        printf("Please enter the operation number: ");
        scanf_s("%d", &operation);

        switch (operation) {
        case 0:
            deleteTree(tree);
            printf("Exiting the program.\n");
            return 0;

        case 1: {
            int key = 0;
            char* value = malloc(100 * sizeof(char));
            if (value == NULL) {
                printf("Error: Memory allocation failed for value.\n");
                free(tree);
                free(initialValue);
                return 1;
            }
            printf("Enter key: ");
            scanf_s("%d", &key);
            getchar();
            printf("Enter value: ");
            fgets(value, 99, stdin);
            value[strcspn(value, "\n")] = 0;

            NodeValue newNodeValue = { key, value };
            insertNode(tree, newNodeValue, &errorCode);
            if (errorCode == 1) {
                printf("Error: Failed to insert the new key-value pair.\n");
            }
            break;
        }

        case 2: {
            int key = 0;
            printf("Enter key to retrieve value: ");
            scanf_s("%d", &key);

            Node* node = findElementByKey(tree, key);
            if (node != NULL) {
                NodeValue nodeValue = getNodeValue(node);
                printf("Value associated with key %d: %s\n", key, nodeValue.value);
            }
            else {
                printf("Key %d not found.\n", key);
            }

            break;
        }

        case 3: {
            int key = 0;
            printf("Enter key to check its presence: ");
            scanf_s("%d", &key);

            if (isNodePresent(tree, key)) {
                printf("Key %d is present in the dictionary.\n", key);
            }
            else {
                printf("Key %d is not present in the dictionary.\n", key);
            }

            break;
        }

        case 4: {
            int key = 0;
            printf("Enter key to delete: ");
            scanf_s("%d", &key);

            deleteNodeByKey(tree, key);
            printf("Node with key %d deleted.\n", key);
            break;
        }

        default:
            printf("Invalid operation number. Please try again.\n");
        }
    }

    free(initialValue);
    deleteTree(tree);
    return 0;
}