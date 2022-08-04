/*
GROUP - 14
Created By:   
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#include "typeChecker.h"
#include "symbol.h"
#include "icg.h"
#include "CodeGenerator.h"
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    printf("LEVEL 4: Symbol table/ AST/ Semantic Rules modules work.\n\n");
    if (argc < 3) {
        printf("Not enough arguments passed => Run again\n");
        return 0;
    }
    int x;
    symbolTable table = initializeSymbolTable();
    while (true) {
        hasErrors = false;
        initialize();
        printf("\nChoose option:\n");
        printf("0: For exit \n");
        printf("1: Printing Token List \n");
        printf("2: Printing Parse Tree and Errors \n");
        printf("3: Printing Abstract Syntax Tree \n");
        printf("4: Allocated Memory and Number of Nodes\n");
        printf("5: Print Symbol Table \n");
        printf("6: Global Variables \n");
        printf("7: Total Memory Requirement \n");
        printf("8: Record Definitions \n");
        printf("9: Calculating Time of Code\n");
        printf("10: Generate Assembly Code\n");
        scanf("%d", &x);
        printf("\n");
        switch (x) {
            case 0: {
                printf("\n*******************Exit from the loop************************\n\n");
                exit(0);
            }
            case 1: {
                printf("\n*******************Printing Token List************************\n\n");
                FILE *fp2 = fopen(argv[1], "r");
                printTokens(table, fp2, true);
                fclose(fp2);
                printf("\n");
                break;
            }
            case 2: {
                printf("\n*******************Printing Parse Tree and Errors************************\n\n");
                ParseTree root = printParserLexer(table, "grammar.txt", argv[1], true, false);
                break;
            }
            case 3: {
                printf("\n*******************Printing Abstract Syntax Tree************************\n\n");
                ParseTree root = printParserLexer(table, "grammar.txt", argv[1], false, false);
                if (!hasErrors) {
                    createAST(root);
                    printf("Printing the Abstract Syntax Tree in Pre Order Traversal\n");
                    printf("Sample print: Parent Node -> All its children in the same line\n");
                    printf("\n");
                    printAST(root);
                }
                printf("\n");
                break;
            }
            case 4: {
                printf("\n*******************Allocated Memory and Number of Nodes************************\n\n");
                initializeVariablesParser();
                ParseTree root = printParserLexer(table, "grammar.txt", argv[1], false, true);
                initializeVariableAST();
                long int memoryParseTree = getMemory();
                printf("Number of nodes in Parse Tree : %ld\n", getParseNodes());
                printf("Allocated memory for Parse Tree : %ld\n", memoryParseTree);
                createAST(root);
                long int memoryAST = getMemoryAST();
                printf("Number of nodes in Abstract Syntax Tree : %ld\n", getFreeNode());
                printf("Allocated memory for Abstract Syntax Tree : %ld\n", memoryAST);
                double percentage = ((memoryParseTree - memoryAST) * 100.0) / (memoryParseTree);
                printf("Compression percentage : %.3lf%%\n", percentage);
                break;
            }

            case 5: {
                printf("\n*******************Print Symbol Table************************\n\n");
                ParseTree root = printParserLexer(table, "grammar.txt", argv[1], false, true);
                createAST(root);
                symbolTable SymbolTable = buildSymbolTable(root, false);
                printTable(root, SymbolTable);
                break;
            }

            case 6: {
                printf("\n*******************Global Variables************************\n\n");
                ParseTree root = printParserLexer(table, "grammar.txt", argv[1], false, true);
                createAST(root);
                symbolTable SymbolTable = buildSymbolTable(root, false);
                printGlobalVar(root, SymbolTable);
                break;
            }

            case 7: {
                printf("\n*******************Total Memory Requirement************************\n\n");
                ParseTree root = printParserLexer(table, "grammar.txt", argv[1], false, true);
                createAST(root);
                symbolTable SymbolTable = buildSymbolTable(root, false);
                printFunctionWidth(root, SymbolTable);
                break;
            }

            case 8: {
                printf("\n*******************Record Definitions************************\n\n");
                ParseTree root = printParserLexer(table, "grammar.txt", argv[1], false, true);
                createAST(root);
                symbolTable SymbolTable = buildSymbolTable(root, false);
                printRecordDefinitions(root, SymbolTable);
                break;
            }

            case 9: {
                printf("\n*******************Calculating Time of Code************************\n\n");
                clock_t begin, end;
                double totalTime, totalTime_in_sec;
                begin = clock();
                ParseTree root = printParserLexer(table, "grammar.txt", argv[1], true, true);
                if (!hasErrors) {
                    createAST(root);
                    symbolTable SymbolTable = buildSymbolTable(root, true);
                    bool getStatus = getErrorStatus();
                    printf("The input source code is semantically %s.\n", !getStatus ? "correct" : "incorrect");
                    printf("Code compiles successfully..........\n");
                    if (!getStatus) {
                        int maxVariableName;
                        iCode code = getIntermediateCode(root, &maxVariableName);
                        generateAssemblyFile(code, maxVariableName, argv[2]);
                    }
                }
                end = clock();
                totalTime = (double) (end - begin);
                totalTime_in_sec = totalTime / CLOCKS_PER_SEC;
                printf("totalTime : %lf , totalTimeInSeconds : %lf", totalTime, totalTime_in_sec);
                printf("\n");
                break;
            }
            case 10: {
                printf("\n*******************Generate Assembly Code************************\n\n");
                ParseTree root = printParserLexer(table, "grammar.txt", argv[1], true, true);
                if (!hasErrors) {
                    createAST(root);
                    symbolTable SymbolTable = buildSymbolTable(root, true);
                    bool getStatus = getErrorStatus();
                    printf("Code compiles successfully..........\n");
                    if (!getStatus) {
                        int maxVariableName;
                        iCode code = getIntermediateCode(root, &maxVariableName);
                        generateAssemblyFile(code, maxVariableName, argv[2]);
                    }
                }
                break;
            }
        }
    }
}
