#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

void options();
bool checkingRotates();
bool functionCheck();

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
                printf("the key and its corresponding value were successfully deleted");
            }
            else {
                printf("the key is not in the dictionary");
            }
            break;
        default:
            printf("Invalid input");
            deleteDictionary(dictionary);
            break;
        }
    } while (choice != 0);

    deleteDictionary(dictionary);
    return 1;
}

void options() {
    printf("Options\n");
    printf("0 - Exit\n");
    printf("1 - Add a value with a correlating key\n");
    printf("2 - Get a value via a key\n");
    printf("3 - Check to see if there's a key in the dictionary\n");
    printf("4 - Delete a key and acorrelating value\n");
    printf("Enter a corresponding digit to choose an aption: ");
}

bool checkingBalanceInvariant(Dictionary* dictionary) {
    return checkBalanceHelper(dictionary->root);
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

bool checkingRotates() {
    Dictionary* testDictinary0 = createDictionary();
    insert(testDictinary0, "4", "a");
    insert(testDictinary0, "3", "b");
    insert(testDictinary0, "2", "c");
    insert(testDictinary0, "1", "d");
    if (!checkingBalanceInvariant(testDictinary0)) {
        deleteDictionary(testDictinary0);
        return false;
    }
    //left rotate provocation
    deleteDictionary(testDictinary0);

    Dictionary* testDictinary2 = createDictionary();
    insert(testDictinary2, "7", "a");
    insert(testDictinary2, "8", "d");
    insert(testDictinary2, "3", "b");
    insert(testDictinary2, "2", "c");
    insert(testDictinary2, "5", "d");
    if (!checkingBalanceInvariant(testDictinary2)) {
        deleteDictionary(testDictinary2);
        return false;
    }
    //provocation of left rotate then right
    deleteDictionary(testDictinary2);

    Dictionary* testDictinary3 = createDictionary();
    insert(testDictinary3, "7", "a");
    insert(testDictinary3, "3", "b");
    insert(testDictinary3, "2", "c");
    insert(testDictinary3, "5", "d");
    if (!checkingBalanceInvariant(testDictinary3)) {
        deleteDictionary(testDictinary3);
        return false; 
    }
    //provocation of left rotate then right. absent right son at the root
    deleteDictionary(testDictinary3);

    return true;
}

bool functionCheck() {
    Dictionary* testDictionary = createDictionary();
    insert(testDictionary, "7", "q");
    insert(testDictionary, "3", "w");
    insert(testDictionary, "2", "e");
    insert(testDictionary, "5", "r");
    insert(testDictionary, "6", "6");
    insert(testDictionary, "14", "ty");

    if (!theKeyExists(testDictionary, "2")) {
      printf("existing key not found");
      deleteDictionary(testDictionary);
      return false;
    }
    if (theKeyExists(testDictionary, "10")) {
      printf("non-existent key found");
      deleteDictionary(testDictionary);
      return false;
    }
    if (getValue(testDictionary, "14") != "ty") {
      printf("error searching for value by existing key");
      deleteDictionary(testDictionary);
      return false;
    }
    if (strcmp(getValue(testDictionary, "13"), "NULL") != 0) {
      printf("Get value function failed on trying to get a value of a nonexistent key");
      deleteDictionary(testDictionary);
      return false;
    }
    deleteViaKey(testDictionary, "2");
     if (theKeyExists(testDictionary, "2")) {
       printf("error deleting key with its corresponding value");
       deleteDictionary(testDictionary);
       return false;
     };

    return true;
}