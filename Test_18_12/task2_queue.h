#pragma once
#include <stdbool.h>

// Structure for storing a queue with two stacks, their tops and capacity
typedef struct Queue {
    int* stack1;    
    int* stack2;    
    int head1;
    int head2;
    int capacity;   
} Queue;

// Creating a queue
Queue* createQueue(int capacity);

// Delete queue
void deleteQueue(Queue* q);

// Adding an element to a queue
bool enqueue(Queue* q, int value);

// Remove item from queue
int dequeue(Queue* q);

// Get item from queue without removing
int peek(Queue* q);