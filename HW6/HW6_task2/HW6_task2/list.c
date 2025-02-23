#include "list.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* createList() {
    LinkedList* linkedlist = malloc(sizeof(LinkedList));
    if (linkedlist == NULL) {
        return NULL;
    }
    linkedlist->head = NULL;
    return linkedlist;
}

LinkedList* createCircle(int n) {
    Node* head = NULL;
    LinkedList* circle = createList();
    for (int i = n; i > 0; i--) {
        Node* warrior = malloc(sizeof(Node));
        if (warrior == NULL) {
            return NULL;
        }
        warrior->data = i;
        warrior->next = head;
        head = warrior;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    circle->head = head;
    return circle;
}

void deleteCircleList(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        return;
    }

    Node* current = list->head;
    Node* nextNode = NULL;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != list->head);

    free(list);
}

int count(LinkedList* circularList, int m) {
    Node* killer = circularList->head;
    Node* victim = circularList->head;
    while (killer->next->next != killer->next) {
        int count = 1;
        while (count != m) {
            victim = victim->next;
            count++;
        }
        while (killer->next->data != victim->data) {
            killer = killer->next;
        }
        killer->next = victim->next;
        free(victim);
        victim = killer->next;
    }
    return killer->data;
}
