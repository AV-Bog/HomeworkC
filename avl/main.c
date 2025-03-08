#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "tree.h"

void options(void);
bool checkRotations(void);
bool runFunctionTests(void);

bool tests(void) {
    return checkRotations() && runFunctionTests();
}

int main(void) {
    if (!tests()) {
        return 1;
    }

    Dictionary* dictionary = createDictionary();
    if (dictionary == NULL) {
        printf("Faild to create dictionary\n");
        return 1;
    }

    int choice = -1;
    const valueBuffer[256] = { '\0' };
    const keyBuffer[256] = { '\0' };
    bool errorCode = true;

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

            errorCode = true;
            if (!insert(dictionary, keyBuffer, valueBuffer, errorCode)) {
                if (!errorCode) {
                    printf("Memory allocation failed during insertion!\n\n");
                }
                else {
                    printf("Failed to insert key-value pair!\n\n");
                }
                
            }
            else {
                printf("Value and its corresponding key have been successfully added!\n\n");
            }
            break;
        case 2:
            printf("Enter key: ");
            scanf("%s", keyBuffer);
            char* value = getValue(dictionary, keyBuffer);
            if (value != NULL) {
                printf("The value is %s\n\n", value);
            }
            else {
                printf("Key not found\n\n");
            }
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
                deleteViaKey(dictionary, keyBuffer, errorCode);
                printf("The key and its corresponding value were successfully deleted\n");
            }
            else {
                printf("The key is not in the dictionary\n");
            }
            break;
        default:
            printf("Invalid input\n");
            deleteDictionary(dictionary);
            return 1;
        }
    } while (choice != 0);

    deleteDictionary(dictionary);
    return 0;
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

bool checkRotations(void) {
    Dictionary* testDictionary0 = createDictionary();
    bool errorCode = true;

    if (!insert(testDictionary0, "4", "a", &errorCode) || !errorCode ||
        !insert(testDictionary0, "3", "b", & errorCode) || !errorCode ||
        !insert(testDictionary0, "2", "c", &errorCode) || !errorCode ||
        !insert(testDictionary0, "1", "d", &errorCode) || !errorCode) {
        printf("Failed to insert into testDictionary0\n");
        deleteDictionary(testDictionary0);
        return false;
    }
    if (!checkBalance(testDictionary0)) {
        deleteDictionary(testDictionary0);
        return false;
    }
    deleteDictionary(testDictionary0);

    Dictionary* testDictionary2 = createDictionary();
    if (!insert(testDictionary2, "7", "a", &errorCode) || !errorCode ||
        !insert(testDictionary2, "8", "d", &errorCode) || !errorCode ||
        !insert(testDictionary2, "3", "b", &errorCode) || !errorCode ||
        !insert(testDictionary2, "2", "c", &errorCode) || !errorCode ||
        !insert(testDictionary2, "5", "d", &errorCode) || !errorCode) {
        printf("Failed to insert into testDictionary2\n");
        deleteDictionary(testDictionary2);
        return false;
    }
    if (!checkBalance(testDictionary2)) {
        deleteDictionary(testDictionary2);
        return false;
    }
    deleteDictionary(testDictionary2);


    Dictionary* testDictionary3 = createDictionary();
    if (!insert(testDictionary3, "7", "a", &errorCode) || !errorCode ||
        !insert(testDictionary3, "3", "b", &errorCode) || !errorCode ||
        !insert(testDictionary3, "2", "c", &errorCode) || !errorCode ||
        !insert(testDictionary3, "5", "d", &errorCode) || !errorCode) {
        printf("Failed to insert into testDictionary3\n");
        deleteDictionary(testDictionary3);
        return false;
    }

    if (!checkBalance(testDictionary3)) {
        deleteDictionary(testDictionary3);
        return false;
    }
    deleteDictionary(testDictionary3);

    return true;
}

bool runFunctionTests(void) {
    Dictionary* testDictionary = createDictionary();
    bool errorCode = true;

    if (!insert(testDictionary, "7", "q", &errorCode) || !errorCode ||
        !insert(testDictionary, "3", "w", &errorCode) || !errorCode ||
        !insert(testDictionary, "2", "e", &errorCode) || !errorCode ||
        !insert(testDictionary, "5", "r", &errorCode) || !errorCode ||
        !insert(testDictionary, "6", "6", &errorCode) || !errorCode ||
        !insert(testDictionary, "14", "ty", &errorCode) || !errorCode) {
        printf("Failed to insert into testDictionary\n");
        deleteDictionary(testDictionary);
        return false;
    }
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
    if (getValue(testDictionary, "13") != NULL) {
        printf("Get value function failed on trying to get a value of a nonexistent key\n");
        deleteDictionary(testDictionary);
        return false;
    }

    deleteViaKey(testDictionary, "2", &errorCode);
    if (!errorCode) {
        printf("Error deleting key with its corresponding value\n");
        deleteDictionary(testDictionary);
        return false;
    }
    if (theKeyExists(testDictionary, "2")) {
        printf("Key was not deleted properly\n");
        deleteDictionary(testDictionary);
        return false;
    }

    deleteDictionary(testDictionary);
    return true;
}