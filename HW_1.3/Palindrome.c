#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPall(char str[], int len);
bool tests();

int main() {
    if (!tests()) return 1;

    int len = 10;
    char srt[] = "qwerttrewq";
    if (isPall(srt, len)) printf("Palindrome!!!");
    return 0;
}

bool isPall(char str[], int len) {
    int i = 0;
    int j = len - i - 1;
    bool isNorm = false;
    while (i != j || i + 1 != j) {
        if (str[i] == " ") {
            i++;
            continue;
        }
        if (str[j] == " ") {
            j++;
            continue;
        }
        if (str[i] == str[j]) return true;
    }
    return isNorm;
}

bool tests() {
    char test10[] = "qweewq";
    int test11 = 6;
    if (!isPall(test10, test11)) {
        printf("test failed");
        return false;
    }

    char test20[] = "qweAewq";
    int test21 = 7;
    if (!isPall(test20, test21)) {
        printf("test failed");
        return false;
    }

    char test30[] = "1234321";
    int test31 = 7;
    if (!isPall(test30, test31)) {
        printf("test failed");
        return false;
    }

    return true;
}