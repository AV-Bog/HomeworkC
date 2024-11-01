#include <stdio.h>
#include <stdbool.h>

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

bool test() {
    FILE* file1 = fopen("testFile1.txt", "r");
    char character;
    char previousSymbol = "";

    char correctAnswer = "afgba";
    char answer[100];
    int i = 0;
    while (!feof(file1)) {
        char receivedSymbol = fgetc(file1);
        if (previousSymbol != receivedSymbol) {
            previousSymbol = receivedSymbol;
            answer[i] = receivedSymbol;
        }
    }

    fclose(file1);
    return true;
}