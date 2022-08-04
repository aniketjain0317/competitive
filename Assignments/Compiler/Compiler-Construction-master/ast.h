/*
GROUP - 14
Created By:
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#ifndef COMPILER_AST_H
#define COMPILER_AST_H

#include "parser.h"

ParseTree concatList(ParseTree head1, ParseTree head2);

void createASTHelper(ParseTree parent);

void createAST(ParseTree root);

void printAST(ParseTree node);

void initializeVariableAST();

long int getMemoryAST();

long int getFreeNode();

void traverseAST(ParseTree node);

#endif //COMPILER_AST_H
