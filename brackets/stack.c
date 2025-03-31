#include "stack.h"

bool push(Stack** head, char element) {
    Stack* temp = malloc(sizeof(Stack));
    if (temp == NULL) {
        return false;
    }
    temp->element = element;
    temp->next = *head;
    *head = temp;
    return true;
}

void pop(Stack** head, int *errorCode) {
    if (*head == NULL) {
        *errorCode = 6;
        return "0";
    }

    *errorCode = 0;
    char value = (*head)->element;

    Stack* temp = (*head)->next;
    free(*head);
    *head = temp;
    return value;
}

bool isEmpty(Stack* head) {
    return head == NULL;
}

char* peek(Stack* head, int* errorCode) {
    if (isEmpty(head)) {
        *errorCode = 6;
        return NULL;
    }

    *errorCode = 0;
    return head->element;
}

void cleanUpStack(Stack **head) {
    while (!isEmpty(*head)) {
        Stack* temp = *head;
        *head = (*head)->next;
        free(temp);        
    }
}