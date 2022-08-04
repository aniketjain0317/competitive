#ifndef COMPILER_ICG_H
#define COMPILER_ICG_H

#include "parserDef.h"
#include "lexer.h"

typedef enum {
    VAR, CONST
} type;

typedef struct {
    type type;
    int value;
} data;

/**
 * Intermediate Code will be a linked list of quadruples
 */
typedef struct quadruple{
    char operator; // 'T', '+', '-', '*', '/', '=', 'L', 'G', 'I', 'R', 'W'
    int condOp;
    data arg1;
    data arg2;
    data result;
    struct quadruple* next;
} quadruple;

typedef struct quadruple* iCode;

iCode createiCode(char op);

iCode concat(quadruple* q1, quadruple* q2);

iCode getIntermediateCode(ParseTreeNode* root, int* maxVariableName);
iCode gcfProgram(ParseTreeNode* node);
iCode gcfMainFunction(ParseTreeNode* node);

iCode gcfDeclarations(ParseTreeNode* node);
iCode gcfDeclaration(ParseTreeNode* node);

iCode gcfArithmeticExpr(ParseTreeNode *node, int variableName);
iCode gcfRecordArithmeticExpr(ParseTreeNode *node, int numOfVariables, int* variableNames);
iCode gcfBooleanExpr(ParseTreeNode* node, int labelTrue, int labelFalse);

iCode gcfStatement(ParseTreeNode* node);
iCode gcfAssignmentStatement(ParseTreeNode* node);
iCode gcfIterativeStatement(ParseTreeNode* node);
iCode gcfIOStatement(ParseTreeNode* node);
iCode gcfConditionalStatement(ParseTreeNode* node);

void removeRedundantAssignment(iCode code);

void printiCode(iCode code);
#endif //COMPILER_ICG_H
