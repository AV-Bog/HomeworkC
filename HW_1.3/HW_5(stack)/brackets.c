#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

#define SIZE 1000
bool balanceCheck(char string[], int* errorCode);
bool tests();

int main() {
	if (!tests()) {
		return -1;
	}

	int errorCode = 0;
	char* string[SIZE];
	printf("Enter a line to check the balance of the brackets: ");
	scanf("%[^\n]", string);

	bool result = balanceCheck(string, &errorCode);
	if (errorCode < 0) {
		printf("Error\n");
	}
	if (result) {
		printf("in the line balance brackets! (TRUE!)");
	}
	else printf("there is no balance of brackets in the line (FALSE!)");
}

bool balanceCheck(char string[], int* errorCode) {
	Stack* stack = NULL;
	int length = strlen(string);
	for (int i = 0; i < length; i++) {
		switch (string[i]) {
		case '(':
		case '[':
		case '{':
			push(&stack, string[i]);
			break;
		
		case ')':
			if ('(' == peek(stack)) {
				pop(&stack, errorCode);
			}
			else return false;
			break;
		case ']':
			if ('[' == peek(stack)) {
				pop(&stack, errorCode);
			}
			else return false;
			break;
		case '}':
			if ('{' == peek(stack)) {
				pop(&stack, errorCode);
			}
			else return false;
			break;
		}
	}
	bool balance = peek(stack) == '0';
	return balance;
}

bool tests() {
	int errorCode = 0;

	char* str1 = "sdbcslabhdldhbashd";
	if (!balanceCheck(str1, &errorCode)) {
		printf("test on string of alphabetic characters failed");
		return false;
	}

	char* str2 = "main clause (secondary clause). {} - brackets, {} - brackets";
	if (!balanceCheck(str2, &errorCode)) {
		printf("test failed on standard example");
		return false;
	}

	char* str3 = "(aaaaaa{aaaaaaaa[aaaaa[aaa]]a}a)";
	if (!balanceCheck(str3, &errorCode)) {
		printf("the program's nesting check failed");
		return false;
	}

	char* str4 = "[]{}(){]";
	if (balanceCheck(str4, &errorCode)) {
		printf("test failed on standard negative example");
		return false;
	}

	return true;
}