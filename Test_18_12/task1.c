#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool tests();
int binaryToDecimal(char* binary[], int lenght);

int main() {
	if (!tests()) {
		return 1;
	}
	char bin_number[] = { '1' };
	int length = strlen(bin_number);
	int dec_number = binaryToDecimal(bin_number, length);
}

int binaryToDecimal(char* binary[], int length) {
	int decimalValue = 0;

	for (int i = 0; i < length; i++) {
		if (strcmp(binary[i], '1') == 0) {
			decimalValue += (1 << (length - 1 - i));
		}
	}

	return decimalValue;
}

bool tests() {
	char* a = { '10' };
	int answerA = 2;
	if (binaryToDecimal(a, 2) != answerA) {
		printf("the test failed on the standard example");
		return 1;
	}

	char* b = { '1000' };
	int answerB = 8;
	if (binaryToDecimal(b, 4) != answerA) {
		printf("the test failed on the standard example");
		return 1;
	}

	return 0;
}
