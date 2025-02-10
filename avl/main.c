#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

void options(void);
bool checkingRotates(void);
bool functionCheck(void);

bool tests() {
    return checkingRotates() && functionCheck();
}

int main() {
    if (!tests()) {
        return 1;
    }

    Dictionary* dictionary = createDictionary();

    int choice = -1;
    const valueBuffer[256] = { '\0' };
    const keyBuffer[256] = { '\0' };

    do {
        options();
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            break;
        case 1:
            printf("Enter a key: ");
            scanf("%s", keyBuffer);
            printf("Enter the value: ");
            scanf("%s", valueBuffer);
            insert(dictionary, keyBuffer, valueBuffer);
            printf("Value and its corresponding key have been successfully added!\n");
            printf("\n");
            break;
        case 2:
            printf("Enter key: ");
            scanf("%s", keyBuffer);
            printf("The value is %s\n", getValue(dictionary, keyBuffer));
            printf("\n");
            break;
        case 3:
            printf("Enter a key: ");
            scanf("%s", keyBuffer);
            if (theKeyExists(dictionary, keyBuffer)) {
                printf("There is such a key in the dictionary\n");
            }
            else {
                printf("There is no such a key in the dictionary\n");
            }
            break;
        case 4:
            printf("Enter a key: ");
            scanf("%s", keyBuffer);
            if (theKeyExists(dictionary, keyBuffer)) {
                deleteViaKey(dictionary, keyBuffer);
                printf("The key and its corresponding value were successfully deleted\n");
            }
            else {
                printf("The key is not in the dictionary\n");
            }
            break;
        default:
            printf("Invalid input\n");
            deleteDictionary(dictionary);
            break;
        }
    } while (choice != 0);

    deleteDictionary(dictionary);
    return 1;
}

void options(void) {
    printf("Options\n");
    printf("0 - Exit\n");
    printf("1 - Add a value with a correlating key\n");
    printf("2 - Get a value via a key\n");
    printf("3 - Check to see if there's a key in the dictionary\n");
    printf("4 - Delete a key and a corresponding value\n");
    printf("Enter a corresponding digit to choose an option: ");
}

bool checkBalanceHelper(Node* node) {
    if (node == NULL) {
        return true;
    }

    int balance = getBalance(node);

    if (balance < -1 || balance > 1) {
        printf("Balance invariant violated at node with key: %s\n", node->key);
        return false;
    }

    return checkBalanceHelper(node->left) && checkBalanceHelper(node->right);
}

bool checkingBalanceInvariant(Dictionary* dictionary) {
    return checkBalanceHelper(dictionary->root);
}

bool checkingRotates(void) {
    Dictionary* testDictionary0 = createDictionary();
    insert(testDictionary0, "4", "a");
    insert(testDictionary0, "3", "b");
    insert(testDictionary0, "2", "c");
    insert(testDictionary0, "1", "d");
    if (!checkingBalanceInvariant(testDictionary0)) {
        deleteDictionary(testDictionary0);
        return false;
    }
    deleteDictionary(testDictionary0);

    Dictionary* testDictionary2 = createDictionary();
    insert(testDictionary2, "7", "a");
    insert(testDictionary2, "8", "d");
    insert(testDictionary2, "3", "b");
    insert(testDictionary2, "2", "c");
    insert(testDictionary2, "5", "d");
    if (!checkingBalanceInvariant(testDictionary2)) {
        deleteDictionary(testDictionary2);
        return false;
    }
    deleteDictionary(testDictionary2);

    Dictionary* testDictionary3 = createDictionary();
    insert(testDictionary3, "7", "a");
    insert(testDictionary3, "3", "b");
    insert(testDictionary3, "2", "c");
    insert(testDictionary3, "5", "d");
    if (!checkingBalanceInvariant(testDictionary3)) {
        deleteDictionary(testDictionary3);
        return false;
    }
    deleteDictionary(testDictionary3);

    return true;
}

bool functionCheck(void) {
    Dictionary* testDictionary = createDictionary();
    insert(testDictionary, "7", "q");
    insert(testDictionary, "3", "w");
    insert(testDictionary, "2", "e");
    insert(testDictionary, "5", "r");
    insert(testDictionary, "6", "6");
    insert(testDictionary, "14", "ty");

    if (!theKeyExists(testDictionary, "2")) {
        printf("Existing key not found\n");
        deleteDictionary(testDictionary);
        return false;
    }
    if (theKeyExists(testDictionary, "10")) {
        printf("Non-existent key found\n");
        deleteDictionary(testDictionary);
        return false;
    }
    if (strcmp(getValue(testDictionary, "14"), "ty") != 0) {
        printf("Error searching for value by existing key\n");
        deleteDictionary(testDictionary);
        return false;
    }
    if (strcmp(getValue(testDictionary, "13"), "NULL") != 0) {
        printf("Get value function failed on trying to get a value of a nonexistent key\n");
        deleteDictionary(testDictionary);
        return false;
    }
    deleteViaKey(testDictionary, "2");
    if (theKeyExists(testDictionary, "2")) {
        printf("Error deleting key with its corresponding value\n");
        deleteDictionary(testDictionary);
        return false;
    }

    return true;
}
