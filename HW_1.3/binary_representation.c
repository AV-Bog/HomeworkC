#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#define BITS 32

bool tests();
void decInBin(int num, int numBin[]);
int binInDec(int num[]);
void sumBin(int num1[], int num2[], int ansver[]);
void displayBinary(int array[]);

int main() {
	if (tests()) return 1;
	
	setlocale(LC_ALL, "Rus");
	int number1, number2;

	printf("введите первое число: ");
	int rez1 = scanf("%d", &number1);
	printf("введите второе число: ");
	int rez2 = scanf("%d", &number2);

	int number1Bin[BITS] = { 0 };
	int number2Bin[BITS] = { 0 };

	decInBin(number1, number1Bin);
	decInBin(number2, number2Bin);

	printf("первое число в двоичной системе счисления: ");
	displayBinary(number1Bin);
	printf("\nвторое число в двоичной системе счисления: ");
	displayBinary(number2Bin);

	int sum[BITS] = { 0 };
	sumBin(number1Bin, number2Bin, sum);
	printf("\nсумма чисел в двоичной системе счисления: ");
	displayBinary(sum);

	printf("\nсумма чисел в десятичной системе счисления: %d", binInDec(sum));
}

void decInBin(int num, int numBin[]) {
	int bit = 1;
	for (int i = BITS - 1; i >= 0; i--) {
		numBin[i] = ((num & bit) ? 1 : 0);
		num >>= 1;
	}
}

void displayBinary(int array[]) {
	for (int i = 0; i < BITS; i++) {
		printf("%d", array[i]);
	}
}

int binInDec(int num[]) {
	int ansver = 0;
	int currentExp = 1;
	for (int i = BITS - 1; i >= 0; i--) {
		ansver += num[i] * currentExp;
		currentExp *= 2;
	}
	return ansver;
}

void sumBin(int num1[], int num2[], int ansver[]) {
	int buf = 0;

	for (int i = BITS - 1; i >= 0; i--) {
		int internRez = num1[i] + num2[i] + buf;

		switch (internRez) {
			case 0:
				ansver[i] = 0;
				buf = 0;
				break;
			case 1:
				ansver[i] = 1;
				buf = 0;
				break;
			case 2:
				buf = 1;
				ansver[i] = 0;
				break;
			case 3:
				buf = 1;
				ansver[i] = 1;
				break;
			default:
				printf("Unexpected error\n");
		}
	}
	return ansver;
}

bool tests() {
	return 0;
}