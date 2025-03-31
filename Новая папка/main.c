#include <stdio.h>
#include <stdbool.h>
#include "queue.h"

bool tests();

int main() {
	if (!tests()) {
		return 1;
	}

	Queue* queue = crietedQueue();
	initializationOfTheQueue(queue);
	enqueue(queue, 0);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	enqueue(queue, 5);
	enqueue(queue, 6);
	enqueue(queue, 7);
	enqueue(queue, 8);
	enqueue(queue, 9);

	enqueue(queue, 10000); //we are filling up the queue

	printf("\nElements queue: ");
	printQueue(queue);

	return 0;
}

bool tests() {
	
}