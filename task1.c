#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int reverseNum(int number) {
    int rev = 0;
    while (number > 0) {
        int dig = number % 10;
        rev = rev * 10 + dig;
        number /= 10;
    }
    return rev;
}

bool isPnumberlindrome(int number) {
    if (number != reverseNum(number)) {
        return false;
    }
    return true;
}

bool test() {
    int num1 = 123321;
    if (!isPnumberlindrome(num1)) {
        printf("the test failed on the standard example");
    }

    int num2 = 1234321;
    if (!isPnumberlindrome(num2)) {
        printf("the test failed on the standard example");
    }

    int num1 = 1321;
    if (isPnumberlindrome(num1)) {
        printf("the test failed on the standard example");
    }
}