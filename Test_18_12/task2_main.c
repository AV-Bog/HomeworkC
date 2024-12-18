#include <stdio.h>
#include <stdbool.h>
#include "task2_queue.h"

bool test();

int main() {
    if (!test()) {
        return 1;
    }

    Queue* queue = createQueue(5);  // Create a queue with a capacity of 5

    enqueue(queue, 1);
    enqueue(queue, 22);
    enqueue(queue, 3);

    printf("Dequeued: %d\n", dequeue(queue)); // 1
    printf("Dequeued: %d\n", dequeue(queue)); // 22

    enqueue(queue, 400);
    enqueue(queue, 5);

    printf("Dequeued: %d\n", dequeue(queue)); // 3
    printf("Dequeued: %d\n", dequeue(queue)); // 400
    printf("Dequeued: %d\n", dequeue(queue)); // 5

    // Trying to pop an element from an empty queue
    printf("Dequeued: %d\n", dequeue(queue));
    deleteQueue(queue);

    return 0;
}

bool test() {
    Queue* queue = createQueue(5);  
    if (!enqueue(queue, 10)) {
        printf("Error: empty queue overflow");
        return false;
    }

    if (dequeue(queue) == -1) {
        printf("error: queue is empty (while trying to pop an existing item from the queue)");
        return false;
    }

    return true;
}