#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack {
	char element;
	struct Stack* next;
} Stack;

char* push(Stack** head, char* element);

char* pop(Stack** head2, int *errorCode);

bool isEmpty(Stack* head);

char* peek(Stack* head);

void clear(Stack** head);