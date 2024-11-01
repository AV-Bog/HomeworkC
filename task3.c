#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool test();

int main() {
    if (!test()) {
        return 1;
    }
    FILE* file = fopen("file.txt", "r");
    char previousSymbol = "";
   
    while (!feof(file)) {
        char receivedSymbol = fgetc(file);
        if (previousSymbol != receivedSymbol) {
            previousSymbol = receivedSymbol;
            printf("%c", receivedSymbol);
        }
    }
    fclose(file);
    return 0;
}

bool test(void) {
    FILE* file1 = fopen("testFile1.txt", "r");
    char previousSymbol = "";

    char correctAnswer[] = "afgba";
    char answer[] = "qwert";
    int i = 0;
    while (!feof(file1)) {
        char receivedSymbol = fgetc(file1);
        if (previousSymbol != receivedSymbol) {
            previousSymbol = receivedSymbol;
            answer[i] = receivedSymbol;
            i++;
        }
    }

    fclose(file1);
    for (int j = 0; j < 5; j++) {
        if (correctAnswer[i] != answer[i]) {
            return false;
            printf("the test failed on the standard example");
        }
    }
    return true;
}