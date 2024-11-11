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
    linkedlist->head = NULL;
    return linkedlist;
}

LinkedList* createCircle(int n) {
    Node* head = NULL;
    LinkedList* circle = createList();
    for (int i = n; i > 0; i--) {
        Node* warrior = malloc(sizeof(Node));

        warrior->data = i;
        warrior->next = head;
        head = warrior;
    }
    Node* temp1 = head;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = head;
    circle->head = head;
    return circle;
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
        killer = victim->next;
        victim = victim->next;
    }
    return(killer->data);
}
