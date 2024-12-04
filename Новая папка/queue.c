#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#define MAX_SIZE 10

typedef struct Queue {
	int data[MAX_SIZE];
	int head;
	int tail;
	int size;
} Queue;

Queue* crietedQueue() { 
	Queue* queue = malloc(sizeof(Queue));
	return queue;
}

void initializationOfTheQueue(Queue* queue) {
	queue->head = 0;
	queue->tail = 0;
	queue->size = 0;
}

void enqueue(Queue* queue, int element) {
	if (queue->size == MAX_SIZE) {
		printf("the queue is overcrowded\n");
		return;
	}
	queue->data[queue->tail] = element;
	queue->tail = (queue->tail + 1) % MAX_SIZE;
	++(queue->size);
}

int dequeue(Queue* queue) {
	if (queue->size == NULL) {
		printf("the queue is empty\n");
		return -1;
	}
	int element = queue->data[queue->head];
	queue->head = (queue->head + 1) % MAX_SIZE;
	(queue->size)--;
	return element;
}

void printQueue(Queue* queue) {
	int lenght = queue->size;
	for (int i = 0; i < lenght; i++) {
		printf("%d ", dequeue(queue));
	}
}