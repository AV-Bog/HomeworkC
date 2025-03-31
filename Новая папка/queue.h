#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct Queue Queue;

//create a queue
Queue* crietedQueue(); 

//initialization a queue
void initializationOfTheQueue(Queue* q); 

//adds an element to the tail and increments the tail index
void enqueue(Queue* q, int data);

//takes an element from the head and increases the head index
int dequeue(Queue* q);

//print a queue
void printQueue(Queue* q); 