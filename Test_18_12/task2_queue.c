#include <stdio.h>
#include <stdlib.h>
#include "task2_queue.h"

Queue* createQueue(int capacity) {
    Queue* queue = malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->stack1 = malloc(capacity * sizeof(int));
    queue->stack2 = malloc(capacity * sizeof(int));
    queue->head1 = -1;
    queue->head2 = -1;
    return queue;
}

void deleteQueue(Queue* queue) {
    free(queue->stack1);
    free(queue->stack2);
    free(queue);
}

bool enqueue(Queue* queue, int value) {
    if (queue->head1 == queue->capacity - 1) {
        printf("Queue overflow\n");
        return false; 
    }
    queue->stack1[++(queue->head1)] = value;
    return true;
}

int dequeue(Queue* queue) {
    if (queue->head2 == -1) {
        if (queue->head1 == -1) {
            printf("Queue underflow\n");
            return -1; 
        }
        while (queue->head1 != -1) {
            queue->stack2[++(queue->head2)] = queue->stack1[(queue->head1)--];
        }
    }
    return queue->stack2[(queue->head2)--];
}

int peek(Queue* queue) {
    if (queue->head2 == -1) {
        if (queue->head2 == -1) {
            printf("Queue is empty\n");
            return -1;
        }

        while (queue->head2 != -1) {
            queue->stack2[++(queue->head2)] = queue->stack1[(queue->head2)--];
        }
    }
    return queue->stack2[queue->head2];
}