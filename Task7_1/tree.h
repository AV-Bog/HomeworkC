#pragma once

// Declaring the tree structure
typedef struct ParseTree ParseTree;

// Builds a parse tree from the given string expression
ParseTree* buildParseTree(char string[]);

// Calculates the result of the expression represented by the parse tree
int calculationExpression(ParseTree* tree);

// Frees the memory used by the parse tree
void deleteParseTree(ParseTree* ParseTree);

// Prints the structure of the parse tree
void printTree(ParseTree* ParseTree);