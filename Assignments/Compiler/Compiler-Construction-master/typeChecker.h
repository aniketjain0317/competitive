/*
GROUP - 14
Created By:
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#ifndef COMPILER_TYPECHECKER_H
#define COMPILER_TYPECHECKER_H

#include "ast.h"

void buildSymbolTableHelper(symbolTable parentSymbolTable, symbolTable globalSymbolTable, ParseTree astNode,int* offset,ParseTree func,bool toPrint);

symbolTable buildSymbolTable(ParseTree astNode,bool toPrint);

void printVariable(symbolTable currSymbolTable, symbolTable globalSymbolTable, ParseTree node, char *scope, char* offset);

void printTableHelper(ParseTree node, symbolTable currSymbolTable, symbolTable globalSymbolTable, char *scope,
                      char *offsetString);

void printTable(ParseTree root, symbolTable globalSymbolTable);

void printFunctionWidthHelper(ParseTree node, symbolTable globalSymbolTable);

void printFunctionWidth(ParseTree root, symbolTable globalSymbolTable);

void printGlobalVarHelper(ParseTree node, symbolTable globalSymbolTable);

void printGlobalVar(ParseTree root, symbolTable globalSymbolTable);

void printRecord(symbolTable globalSymbolTable, ParseTree node);

void printRecordDefinitionsHelper(ParseTree node, symbolTable globalSymbolTable);

void printRecordDefinitions(ParseTree root, symbolTable globalSymbolTable);

void checkInList(hashList *list, char *checkAgainst, bool *array);

void putInTable(hashtableInt *table, ParseTree node);

void handleIterativeSemantics(ParseTree astNode, bool *array, hashList *list,bool toPrint);

void computeType(ParseTree astNode, symbolTable parentSymbolTable, symbolTable globalSymbolTable, hashtableInt *hashTable,bool toPrint);

void misMatchError(ParseTree node, bool toPrint);

void typeChecker(ParseTree astNode, symbolTable parentSymbolTable, symbolTable globalSymbolTable, ParseTree output,
                 bool assigned[], bool isOutermostWhile, hashtableInt *table,bool toPrint);

bool getErrorStatus();

#endif //COMPILER_TYPECHECKER_H

// width and offset to be included