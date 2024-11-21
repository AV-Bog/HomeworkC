#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ParseTree ParseTree;
ParseTree* buildParseTree(char string[]);
int calculationExpression(ParseTree* tree);
void deleteParseTree(ParseTree* ParseTree);
void printTree(ParseTree* ParseTree);