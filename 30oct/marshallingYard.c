#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

#define SIZE 1000

Stack* infixToPostfix(char infixExpression[]);
//bool tests();

int main() {
	//if (!tests()) {
	//	return -1;
	//}

	int errorCode = 0;
	char* expression[SIZE];
	printf("Enter the expression in infix form: ");
	scanf("%[^\n]", expression);

	printf("Result: ");
    Stack* rez = infixToPostfix(expression);
	displayStack(rez);
}

Stack* infixToPostfix(char infixExpression[]) {
	int length = strlen(infixExpression);
	Stack* mainStack = NULL;
	Stack* auxillaryStack = NULL;

    for (int i = 0; i < length; i++) {
        if (infixExpression[i] != ' ' && infixExpression[i] != '\0') {
            switch (infixExpression[i]) {
                case '(':
                    push(&auxillaryStack, infixExpression[i]);
                    break;
                case ')': {
                    int errorCode = 0;
                    while (peek(auxillaryStack) != '(') {
                        char character = peek(auxillaryStack);
                        push(&mainStack, character);
                        pop(&auxillaryStack, &errorCode);
                    }
                    pop(&auxillaryStack, &errorCode);
                    break;
                    }
                case '*':
                case '/':
                    if (peek(auxillaryStack) == '+' || peek(auxillaryStack) == '-' || peek(auxillaryStack) == '(') {
                        push(&auxillaryStack, infixExpression[i]);
                    }
                    else {
                        int errorCode = 0;
                        push(&mainStack, pop(&auxillaryStack, &errorCode));
                        push(&auxillaryStack, infixExpression[i]);
                    }
                    break;
                case '+':
                case '-':
                    if ((peek(auxillaryStack) != '*' && peek(auxillaryStack) != '/')) {
                        push(&auxillaryStack, infixExpression[i]);
                    }
                    else {
                        int errorCode = 0;
                        push(&mainStack, pop(&auxillaryStack, &errorCode));
                        push(&auxillaryStack, infixExpression[i]);
                    }
                    break;
                default:
                    push(&mainStack, infixExpression[i]);
                    break;
            }
        }
    }
    while (!isEmpty(auxillaryStack)) {
        int errorCode = 0;
        push(&mainStack, pop(&auxillaryStack, &errorCode));
    }


    Stack* reversedStack = NULL;
    while (!isEmpty(mainStack)) {
        int errorCode = 0;
        push(&reversedStack, pop(&mainStack, &errorCode));
    }
    return reversedStack;

}

