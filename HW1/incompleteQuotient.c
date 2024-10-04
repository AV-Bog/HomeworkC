#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int division(int dividend, int divisor);

bool testCorrect() {
	return ((division(78, 33) == 2) && (division(-9, -13) == 1) && (division(32, -10) == -3) && (division(-78, 33) == -3) && (division(5, 5) == 1));
}

int main(void) {
	if (testCorrect) printf("tests failed\n");

	int dividend = 0, divisor = 0;
	printf("enter the dividend: ");
	int result = scanf("%d", &dividend);
	printf("enter the divisor: ");
	int result1 = scanf("%d", &divisor);

	if (dividend == 0) {
		printf("incomplete quotient = 0");
	}
	if (divisor == 0) {
		printf("your request is incorrect (the divisor cannot be zero)");
	}

	int incompleteQuotient = division(dividend, divisor);
	printf("incomplete quotient = %d\n", incompleteQuotient);
}

int division(int dividend, int divisor) {
	int incompleteQuotient = 0;

	bool dividendNegativ = false;
	bool divisorNegativ = false;

	if (dividend < 0) {
		dividendNegativ = true;
		dividend *= -1;
	}

	if (divisor < 0) {
		divisorNegativ = true;
		divisor *= -1;
	}

	while (dividend >= divisor) {
		dividend -= divisor;
		incompleteQuotient++;
	}

	if (!dividendNegativ && divisorNegativ) {
		return -incompleteQuotient;
	}
	else if (dividend != 0) {
		return -incompleteQuotient - 1;
	}
	else return -incompleteQuotient;


	return (dividendNegativ && divisorNegativ) ? incompleteQuotient + 1 : incompleteQuotient;
}