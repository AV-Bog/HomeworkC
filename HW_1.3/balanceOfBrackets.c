#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool countStr(const char* str);

int main() {
	const char* str[1001];
	printf("enter a string (max 1000 symbols): \n");
	int rez = scanf("%s", &str);

	str[1000] = '\0';

	if (countStr(str) == 0) printf("balance");
	else printf("not balance");
}

bool countStr(const char* str) {
	int i = 0;
	int count = 0;

	while (str[i] != '\0') {
		if (str[i] == '(') count++;
		if (str[i] == ')') count--;
		if (count < 0) {
			return 1;
			break;
		}
		i++;
	}
	if (count != 0) return 1;
	else return 0;
}