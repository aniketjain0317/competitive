/*
GROUP - 14
Created By:   
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#include "symbol.h"

// TermSymbol stores all the tokens according to specifications
char *TermSymbol[] = {"TK_ASSIGNOP","TK_COMMENT","TK_FIELDID","TK_ID","TK_NUM","TK_RNUM","TK_FUNID","TK_RECORDID",
                      "TK_WITH","TK_PARAMETERS","TK_END","TK_WHILE","TK_INT","TK_REAL","TK_TYPE","TK_MAIN","TK_GLOBAL","TK_PARAMETER",
                      "TK_LIST","TK_SQL","TK_SQR","TK_INPUT","TK_OUTPUT","TK_SEM","TK_COLON","TK_DOT","TK_COMMA","TK_ENDWHILE","TK_OP",
                      "TK_CL","TK_IF","TK_THEN","TK_ENDIF","TK_READ","TK_WRITE","TK_RETURN","TK_PLUS","TK_MINUS","TK_MUL","TK_DIV",
                      "TK_CALL","TK_RECORD","TK_ENDRECORD","TK_ELSE","TK_AND","TK_OR","TK_NOT","TK_LT","TK_LE","TK_EQ","TK_GT","TK_GE",
                      "TK_NE", "eps", "TK_UNDEFINED", "TK_ERROR","TK_NULL","TK_BOOLEAN"};

// NonTermSymbol stores all the non-terminals occuring in the grammar
char *NonTermSymbol[] = {"program","mainFunction","otherFunctions","function","input_par","output_par","parameter_list",
                         "dataType","primitiveDatatype","constructedDatatype","remaining_list","stmts","typeDefinitions","typeDefinition",
                         "fieldDefinitions","fieldDefinition","moreFields","declarations","declaration","global_or_not","otherStmts","stmt",
                         "assignmentStmt","singleOrRecId","new_24","funCallStmt","outputParameters","inputParameters","iterativeStmt",
                         "conditionalStmt","elsePart","ioStmt","allVar","arithmeticExpression","expPrime","term","termPrime","factor",
                         "highPrecedenceOperators","lowPrecedenceOperators","all","temp","booleanExpression","var","logicalOp","relationalOp",
                         "returnStmt","optionalReturn","idList","more_ids","tempvar"};
