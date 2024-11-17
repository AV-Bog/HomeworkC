#include <stdbool.h>
#include <string.h>
#include "tree.h"

bool tests();

int main() {
    if (!tests()) {
        return 1;
    }

	FILE* file = fopen("file.txt", "r");
	if (file == NULL) {
		printf("File not found");
		return 1;
	}
	char file—ontents[100];
	fscanf(file, "%[^\n]", file—ontents);

	ParseTree* tree = buildParseTree(file—ontents);
    printTree(tree);
    printf("Answer: ");
	printf("%d", calculationExpression(tree));

	fclose(file);
	deleteParseTree(tree);
	return 0;
}

bool tests() {
    char expressionTest1[] = "( * ( + 1 1 ) 2 )";
    int answer1 = 4;
    ParseTree* testTree1 = buildParseTree(expressionTest1);
    if (answer1 != calculationExpression(testTree1)) {
        printf("Tests failed on the example expression");
        return false;
    }

    char expressionTest2[] = "( / (27 216))";
    int answer2 = 8;
    ParseTree* testTree2 = buildParseTree(expressionTest2);
    if (answer2 != calculationExpression(testTree2)) {
        printf("Tests failed when expression contains numbers (not digits)");
        return false;
    }

    char expressionTest3[] = "( + ( * -7 -3) -10 )";
    int answer3 = 11;
    ParseTree* testTree3 = buildParseTree(expressionTest3);
    if (answer3 != calculationExpression(testTree3)) {
        printf("Tests failed when expression contains negative numbers (not digits)");
        return false;
    }

    return true;
}