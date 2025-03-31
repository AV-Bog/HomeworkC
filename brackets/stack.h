#pragma once

typedef struct Stack {
	char element;
	struct Stack* next;
} Stack;

// Pushes a new element onto the stack
bool push(Stack** head, char element);

// Pops the top element from the stack
void pop(Stack** head, int* errorCode);

// Checks if the stack is empty
bool isEmpty(Stack* head);

// Returns the top element of the stack
char* peek(Stack* head, int* errorCode);

// Frees all the elements in the stack and resets the head
void cleanUpStack(Stack **head);