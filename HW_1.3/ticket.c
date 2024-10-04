#include <stdio.h>

int main(void) {
	char summ[28] = { 0 };
	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			for (int c = 0; c < 10; c++) {
				int sum3 = a + b + c;
				summ[sum3]++;
			}
		}
	}
	int count = 0;
	for (int j = 0; j < 28; j++) {
		count += summ[j] * summ[j];
	}
	printf("%d", count);
}