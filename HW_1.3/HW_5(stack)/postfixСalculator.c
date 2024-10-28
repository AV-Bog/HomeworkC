#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

#define SIZE 1000

bool operation(char operand, Stack** postfixMachine);
int calculator(char expression[], int* errorCode);
bool tests();

int main() {
	if (!tests()) {
		return -1;
	}

	int errorCode = 0;
	char* expression[SIZE];
	printf("Enter the expression in postfix form: ");
	scanf("%[^\n]", expression);
	int result = calculator(expression, &errorCode);
	(errorCode < 0) ? printf("Error\n") : printf("Result = %d", result);
}

bool operation(char operand, Stack **postfixMachine) {
	int errorCode = 0;
	int topElement = pop(postfixMachine, &errorCode);
	int deeperElement = pop(postfixMachine, &errorCode);
	if (errorCode < 0) {
		return false;
	}

	switch (operand) {
		case '-': {
			int tempResult = deeperElement - topElement;
			push(postfixMachine, tempResult);
			break;
		}
		case '+': {
			int tempResult = deeperElement + topElement;
			push(postfixMachine, tempResult);
			break;
		}
		case '*': {
			int tempResult = deeperElement * topElement;
			push(postfixMachine, tempResult);
			break;
		}
		case '/': {
			int tempResult = deeperElement / topElement;
			push(postfixMachine, tempResult);
			break;
		}
	}
	return true;
}

int calculator(char expression[], int* errorCode) {
	Stack *stacks = NULL;
	int length = strlen(expression);
	for (int i = 0; i < length; i++) {
		switch (expression[i]) {
			case ' ':
				break;
			case '/':
				operation(expression[i], &stacks);
				break;
			case '*':
				operation(expression[i], &stacks);
				break;
			case '+':
				operation(expression[i], &stacks);
				break;
			case '-':
				operation(expression[i], &stacks);
				break;
			default: {
				int errorCode = 0;
				push(&stacks, expression[i] - '0');
				break;
			}
		}
	}
	int errorCodePeek = 0;
	int result = peek(stacks);
	if (errorCodePeek < 0 || stacks->next != NULL) {
		*errorCode = -1;
	}
	return result;
}

bool tests() {
	int errorCode = 0;

	char* expr1 = "99-";
	if (0 != calculator(expr1, &errorCode)) {
		printf("test failed on standard example");
		return false;
	}

	char* expr2 = "9 6 - 1 2 + *";
	if (9 != calculator(expr2, &errorCode)) {
		printf("test failed on standard example");
		return false;
	}

	return true;
}