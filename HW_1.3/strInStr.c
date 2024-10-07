#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int countEntry(char srti[], char subs[]);
bool tests();

int main() {
	if (!tests()) return 1;

	char stri[1000], subs[999];
	printf("enter a string: \n");
	int result = scanf("%s", &stri);
	printf("enter substring: \n");
	int result2 = scanf("%s", &subs);

	int count = countEntry(&stri, &subs);

	printf("%d", count);
	return 0;
}

int countEntry(char stri[], char subs[]) {
	int lenStri = strlen(stri);
	int lenSubs = strlen(subs);

	int count = 0;
	for (int i = 0; i < (lenStri - lenSubs + 1); i++) {
		bool entry = true;
		for (int j = 0; j < lenSubs; j++) {
			if (stri[i+j] != subs[j]) {
				entry = false;
				break;
			}
		}
		if (entry) count++;
	}
	return count;
}

bool tests() {
	char s10[] = "asdasdasdf";
	char s11[] = "as";
	if (countEntry(s10, s11) != 3) {
		printf("tests failed");
		return false;
	}

	char s20[] = "aaaaaaaaaa";
	char s21[] = "a";
	if (countEntry(s20, s21) != 10) {
		printf("tests failed");
		return false;
	}
	return true;
}