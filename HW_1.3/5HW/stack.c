#include "stack.h"

char* push(Stack** head, char* element) {
    Stack* temp = malloc(sizeof(Stack));
    if (temp == NULL) {
        printf("Out of memory");
        return "-1";
    }
    temp->element = element;
    temp->next = *head;
    *head = temp;
    return (*head)->element;
}

char* pop(Stack** head, int *errorCode) {
    if (*head == NULL) {
        *errorCode = -1;
        return "0";
    }

    *errorCode = 0;
    char* value = (*head)->element;

    Stack* temp;
    temp = (*head)->next;
    free(*head);
    (*head) = temp;
    return value;
}

bool isEmpty(Stack* head) {
    return head == NULL;
}

char* peek(Stack* head) {
    if (isEmpty(head)) {
        return '0';
    }
    return head->element;
}

void clear(Stack **head) {
    while (!isEmpty(*head)) {
        int errorCode = 0;
        pop(head, &errorCode);
        if (errorCode < 0) {
            break;
        }
    }
}

//void displayStack(Stack* stack) {
//    while (stack != NULL) {
//        printf("%d", stack->element);
//        stack = stack->next;
//    }
//}