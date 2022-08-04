/*
GROUP - 14
Created By:
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/


#include "typeChecker.h"
#include "stdlib.h"
#include "symbol.h"
#include <string.h>

#define INITIAL_CAPACITY 2

int recordNumber = 200;
int currentCapacity = INITIAL_CAPACITY;
char **mappingRecordNumberToType;
int capacity = INITIAL_CAPACITY;
int globalOffset = 0;
bool hasSemanticErrors = false;

void checkInList(hashList *list, char *checkAgainst, bool *array) {
    hashList *temp = list;
    while (temp != NULL) {
        hashtableInt *hashTable = temp->head;
        int val = hash_getInt(hashTable, checkAgainst);
        if (val != -1) {
            array[temp->iterativeScope] = true;
        }
        temp = temp->next;
    }
}

void putInTable(hashtableInt *table, ParseTree node) {
    if (node->firstChild == NULL) {
        hash_putInt(table, node->lexeme, 0);
        return;
    }
    ParseTree child = node->firstChild;
    for (int i = 0; i < node->noOfChildren; i++) {
        putInTable(table, child);
        child = child->sibling;
    }
}

void handleIterativeSemantics(ParseTree astNode, bool *array, hashList *list, bool toPrint) {
    if (astNode->firstChild == NULL) {
        return;
    }

    if (astNode->id == 122) {   //"assignmentStmt"
        char *checkAgainst = astNode->firstChild->firstChild->lexeme;
        checkInList(list, checkAgainst, array);
    } else if (astNode->id == 125) {   //"funCallStmt"
        ParseTree temp = astNode->firstChild;
        while (temp->id != TK_FUNID) {
            checkInList(list, temp->lexeme, array);
            temp = temp->sibling;
        }
    } else if (astNode->id == 131) {   //"ioStmt"
        if (astNode->firstChild->id == TK_WRITE) {
            return;
        }
        checkInList(list, astNode->firstChild->sibling->lexeme, array);
    } else if (astNode->id == 128) {   //"iterativeStmt"
        hashList *temp = (hashList *) malloc(sizeof(hashList));
        temp->head = createHashtableInt(101);
        temp->iterativeScope = list != NULL ? list->iterativeScope + 1 : 0;
        if (temp->iterativeScope == currentCapacity) {
            array = (bool *) realloc(array, sizeof(bool) * currentCapacity * 2);
            currentCapacity *= 2;
        }
        temp->next = list;
        list = temp;
        putInTable(temp->head, astNode->firstChild);
        ParseTree child = astNode->firstChild->sibling;
        int endLine = 0;
        for (int i = 0; i < astNode->noOfChildren - 1; i++) {
            handleIterativeSemantics(child, array, list, toPrint);
            if (i == astNode->noOfChildren - 2) {
                endLine = child->lineno;
            }
            child = child->sibling;
        }
        //error reporting
        if (!array[temp->iterativeScope]) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Lines %d-%d : None of the variables participating in the iterations of the "
                       "while loop gets updated.\n", astNode->firstChild->lineno, endLine);
        }
        hashList *freeNode = list;
        list = list->next;
        free(freeNode);
        array[temp->iterativeScope] = false;
    } else if (astNode->id == 129) {   //"conditionalStmt"
        ParseTree child = astNode->firstChild->sibling;
        while (child->id != 130) {
            handleIterativeSemantics(child, array, list, toPrint);
            child = child->sibling;
        }
        ParseTree temp = child->firstChild;
        for (int i = 0; i < child->noOfChildren; i++) {
            handleIterativeSemantics(temp, array, list, toPrint);
            temp = temp->sibling;
        }
    } else {
        ParseTree temp = astNode->firstChild;
        for (int i = 0; i < astNode->noOfChildren; i++) {
            handleIterativeSemantics(temp, array, list, toPrint);
            temp = temp->sibling;
        }
    }

}

void
computeType(ParseTree astNode, symbolTable parentSymbolTable, symbolTable globalSymbolTable, hashtableInt *hashTable,
            bool toPrint) {
    symbolTable table = NULL;
    if (astNode->id == 4) {
        astNode->dataType = TK_INT;
    } else if (astNode->id == 5) {
        astNode->dataType = TK_REAL;
    } else if (astNode->id == 3) {
        symbolTable inputSymbolTable = getAttributeValue(parentSymbolTable, "input_par", "inputParScope");
        SymbolTableEntry *entry = NULL;
        if (inputSymbolTable != NULL) {
            entry = getSymbolTableEntry(inputSymbolTable, astNode->lexeme);
            if (entry == NULL) {
                symbolTable outputSymbolTable = getAttributeValue(parentSymbolTable, "output_par", "outputParScope");
                if (outputSymbolTable->symbolTableCapacity != 0) {
                    entry = getSymbolTableEntry(outputSymbolTable, astNode->lexeme);
                    if (entry != NULL) {
                        table = outputSymbolTable;
                    }
                }
            } else {
                table = inputSymbolTable;
            }
        }
        if (entry == NULL) {
            entry = getSymbolTableEntry(parentSymbolTable, astNode->lexeme);
            if (entry == NULL) {
                entry = getSymbolTableEntry(globalSymbolTable, astNode->lexeme);
                if (entry == NULL) {
                    if (hash_getInt(hashTable, astNode->lexeme) == -1) {
                        hasSemanticErrors = true;
                        if (toPrint)
                            printf("Line %d : Variable %s is not declared.\n", astNode->lineno, astNode->lexeme);
                    }
                    hash_putInt(hashTable, astNode->lexeme, astNode->lineno);
                    astNode->dataType = TK_ERROR;
                    return;
                } else {
                    table = globalSymbolTable;
                }
            } else {
                table = parentSymbolTable;
            }
        }
        int val = *(int *) getAttributeValue(table, astNode->lexeme, "dataType");
        if (val == 7) {   //TK_RECORDID
            char *recordid = (char *) getAttributeValue(table, astNode->lexeme, "recordType");
            if (astNode->sibling != NULL && astNode->sibling->id == TK_FIELDID) {
                symbolTable recordScopeTable = (symbolTable) getAttributeValue(globalSymbolTable, recordid,
                                                                               "recordScope");
                astNode->dataType = *(int *) getAttributeValue(recordScopeTable, astNode->sibling->lexeme, "dataType");
            } else {
                astNode->dataType = *(int *) getAttributeValue(globalSymbolTable, recordid, "recordNumber");
            }
        } else {
            astNode->dataType = val;
        }
    }
}

void checkIfAssigned(char *lexeme, ParseTree output, bool assigned[]) {
    ParseTree outPar = NULL;
    if (output != NULL) {
        outPar = output->firstChild;
    }
    int i = 0;
    while (outPar != NULL) {
        if (strcmp(outPar->sibling->lexeme, lexeme) == 0) {
            assigned[i] = true;
            break;
        }
        i++;
        outPar = outPar->sibling->sibling;
    }
}

void
buildSymbolTableHelper(symbolTable parentSymbolTable, symbolTable globalSymbolTable, ParseTree astNode, int *offset,
                       ParseTree func, bool toPrint) {
    if (astNode->firstChild == NULL && astNode->id != 105) {
        return;
    }

    if (astNode->id == 103) {   //"function"
        symbolTable funcSymbolTable = initializeSymbolTable();
        if (globalSymbolTable->table != NULL &&
            getSymbolTableEntry(globalSymbolTable, astNode->firstChild->lexeme) != NULL) {
            return;
        }
        putInSymbolTable(globalSymbolTable, astNode->firstChild->lexeme, TK_FUNID);
        addAttribute(globalSymbolTable, astNode->firstChild->lexeme, "funcScope", funcSymbolTable);
        ParseTree child = astNode->firstChild;
        int *pointer = (int *) malloc(sizeof(int));
        *pointer = 0;
        for (int i = 0; i < astNode->noOfChildren; i++) {
            buildSymbolTableHelper(funcSymbolTable, globalSymbolTable, child, pointer, astNode, toPrint);
            child = child->sibling;
        }
        addAttribute(globalSymbolTable, astNode->firstChild->lexeme, "offset", pointer);
        return;
    }

    if (astNode->id == 113) {   //"typeDefinition"
        if (getSymbolTableEntry(globalSymbolTable, astNode->firstChild->lexeme) != NULL) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : Multiple definition of %s.\n", astNode->firstChild->lineno,
                       astNode->firstChild->lexeme);
            return;
        }
        putInSymbolTable(globalSymbolTable, astNode->firstChild->lexeme, TK_RECORD);
        symbolTable recordSymbolTable = initializeSymbolTable();
        addAttribute(globalSymbolTable, astNode->firstChild->lexeme, "recordScope", recordSymbolTable);
        int *pointer = (int *) malloc(sizeof(int));
        *pointer = recordNumber;
        addAttribute(globalSymbolTable, astNode->firstChild->lexeme, "recordNumber", pointer);
        if (recordNumber == capacity - 1) {
            mappingRecordNumberToType = (char **) realloc(mappingRecordNumberToType, capacity * 2 * sizeof(char *));
            capacity *= 2;
        }
        mappingRecordNumberToType[recordNumber - 200] = astNode->firstChild->lexeme;
        recordNumber++;
        int *array = (int *) malloc(sizeof(int) * (astNode->noOfChildren - 1));
        memset(array, -1, sizeof(int) * (astNode->noOfChildren - 1));
        ParseTree fieldDefinition = astNode->firstChild->sibling;
        int i = 0;
        while (fieldDefinition != NULL) {
            putInSymbolTable(recordSymbolTable, fieldDefinition->firstChild->sibling->lexeme, TK_FIELDID);
            addAttribute(recordSymbolTable, fieldDefinition->firstChild->sibling->lexeme, "dataType",
                         &fieldDefinition->firstChild->id);
            array[i] = fieldDefinition->firstChild->id;
            fieldDefinition = fieldDefinition->sibling;
            i++;
        }
        addAttribute(globalSymbolTable, astNode->firstChild->lexeme, "fieldTypes", array);
        return;
    }

    if (astNode->id == 118) {  //"declaration"
        symbolTable table = parentSymbolTable;
        if (astNode->noOfChildren == 3) {   //global
            table = globalSymbolTable;
        }
        if (table->symbolTableCapacity != 0 &&
            getSymbolTableEntry(table, astNode->firstChild->sibling->lexeme) != NULL) {
            if (table == globalSymbolTable) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Variable %s being a global variable, cannot be declared more than once.\n",
                           astNode->firstChild->sibling->lineno, astNode->firstChild->sibling->lexeme);

            } else {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : The identifier %s is declared more than once.\n",
                           astNode->firstChild->sibling->lineno, astNode->firstChild->sibling->lexeme);

            }
            return;
        } else if (table->symbolTableCapacity != 0 && table == parentSymbolTable &&
                   getSymbolTableEntry(globalSymbolTable, astNode->firstChild->sibling->lexeme) != NULL) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : Identifier declared globally cannot be declared anywhere else in function definition.\n",
                       astNode->firstChild->sibling->lineno);
            return;
        } else if (table->symbolTableCapacity != 0 && table == globalSymbolTable &&
                   parentSymbolTable->symbolTableCapacity != 0
                   && getSymbolTableEntry(parentSymbolTable, astNode->firstChild->sibling->lexeme) != NULL) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : Identifier declared locally cannot be again declared globally.\n",
                       astNode->firstChild->sibling->lineno);
            return;
        }
        if (func != NULL) {
            ParseTree inputPar = func->firstChild->sibling;
            ParseTree outputPar = inputPar->sibling;
            ParseTree temp = inputPar->firstChild;
            for (int i = 0; i < inputPar->noOfChildren / 2; i++) {
                if (strcmp(temp->sibling->lexeme, astNode->firstChild->sibling->lexeme) == 0) {
                    hasSemanticErrors = true;
                    if (toPrint)
                        printf("Line %d : Multiple declaration of %s.\n", astNode->firstChild->sibling->lineno,
                               astNode->firstChild->sibling->lexeme);
                    return;
                }
                temp = temp->sibling->sibling;
            }
            temp = outputPar->firstChild;
            for (int i = 0; i < outputPar->noOfChildren / 2; i++) {
                if (strcmp(temp->sibling->lexeme, astNode->firstChild->sibling->lexeme) == 0) {
                    hasSemanticErrors = true;
                    if (toPrint)
                        printf("Line %d : Multiple declaration of %s.\n", astNode->firstChild->sibling->lineno,
                               astNode->firstChild->sibling->lexeme);
                    return;
                }
                temp = temp->sibling->sibling;
            }
        }

        char *offsetString = (char *) malloc(sizeof(char) * 4);
        if (astNode->noOfChildren == 3) {   //"global"
            strcpy(offsetString, "-");
            if (astNode->firstChild->id == TK_RECORDID &&
                getSymbolTableEntry(globalSymbolTable, astNode->firstChild->lexeme) == NULL) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Type %s is undefined.\n", astNode->firstChild->lineno,
                           astNode->firstChild->lexeme);
                int *val = (int *) malloc(sizeof(int));
                *val = TK_ERROR;
                putInSymbolTable(table, astNode->firstChild->sibling->lexeme, TK_ID);
                addAttribute(table, astNode->firstChild->sibling->lexeme,
                             "dataType", val);
                return;
            }

            int offset = 0;
            if (astNode->firstChild->id == TK_INT) {
                offset += 2;
            } else if (astNode->firstChild->id == TK_REAL) {
                offset += 4;
            } else {
                int *recordType = (int *) getAttributeValue(globalSymbolTable, astNode->firstChild->lexeme,
                                                            "fieldTypes");
                symbolTable recordScope = (symbolTable) getAttributeValue(globalSymbolTable,
                                                                          astNode->firstChild->lexeme,
                                                                          "recordScope");
                for (int i = 0; i < recordScope->symbolTableSize; i++) {
                    if (recordType[i] == TK_INT) {
                        offset += 2;
                    } else {
                        offset += 4;
                    }
                }
            }
            putInSymbolTable(table, astNode->firstChild->sibling->lexeme, TK_ID);
            char *off = (char *) malloc(sizeof(char) * 4);
            sprintf(off, "%d", globalOffset);
            globalOffset += offset;
            addAttribute(globalSymbolTable, astNode->firstChild->sibling->lexeme, "globalOffset", off);
        } else {
            int temp = *offset;
            if (astNode->firstChild->id == TK_INT) {
                *offset += 2;
            } else if (astNode->firstChild->id == TK_REAL) {
                *offset += 4;
            } else {
                if (getSymbolTableEntry(globalSymbolTable, astNode->firstChild->lexeme) == NULL) {
                    hasSemanticErrors = true;
                    if (toPrint)
                        printf("Line %d : Type %s is undefined.\n", astNode->firstChild->lineno,
                               astNode->firstChild->lexeme);
                    int *val = (int *) malloc(sizeof(int));
                    *val = TK_ERROR;
                    putInSymbolTable(table, astNode->firstChild->sibling->lexeme, TK_ID);
                    addAttribute(table, astNode->firstChild->sibling->lexeme,
                                 "dataType", val);
                    return;
                }
                int *recordType = (int *) getAttributeValue(globalSymbolTable, astNode->firstChild->lexeme,
                                                            "fieldTypes");
                symbolTable recordScope = (symbolTable) getAttributeValue(globalSymbolTable,
                                                                          astNode->firstChild->lexeme,
                                                                          "recordScope");
                for (int i = 0; i < recordScope->symbolTableSize; i++) {
                    if (recordType[i] == TK_INT) {
                        *offset += 2;
                    } else {
                        *offset += 4;
                    }
                }
            }
            sprintf(offsetString, "%d", temp);
            putInSymbolTable(table, astNode->firstChild->sibling->lexeme, TK_ID);
        }
        addAttribute(table, astNode->firstChild->sibling->lexeme,
                     "dataType", &astNode->firstChild->id);
        addAttribute(table, astNode->firstChild->sibling->lexeme, "recordType",
                     astNode->firstChild->lexeme);
        addAttribute(table, astNode->firstChild->sibling->lexeme, "offset", offsetString);
        return;
    }

    if (astNode->id == 101) { //"mainFunction"
        symbolTable funcSymbolTable = initializeSymbolTable();
        putInSymbolTable(parentSymbolTable, "_main", TK_MAIN);
        addAttribute(parentSymbolTable, "_main", "funcScope", funcSymbolTable);
        ParseTree child = astNode->firstChild;
        int *pointer = (int *) malloc(sizeof(int));
        *pointer = 0;
        for (int i = 0; i < astNode->noOfChildren; i++) {
            buildSymbolTableHelper(funcSymbolTable, globalSymbolTable, child, pointer, NULL, toPrint);
            child = child->sibling;
        }
        addAttribute(globalSymbolTable, "_main", "offset", pointer);
        return;
    }

    //recursive calls to children
    ParseTree child = astNode->firstChild;
    for (int i = 0; i < astNode->noOfChildren; i++) {
        buildSymbolTableHelper(parentSymbolTable, globalSymbolTable, child, offset, func, toPrint);
        child = child->sibling;
    }
}

void misMatchError(ParseTree node, bool toPrint) {
    ParseTree astNodeLeft, astNodeRight = node->firstChild->sibling;
    int lineno;
    char *op;
    if (node->id == 122) {
        astNodeLeft = node->firstChild->firstChild;
        lineno = astNodeLeft->lineno;
        op = strdup("<---");
    } else {
        astNodeLeft = node->firstChild;
        lineno = node->lineno;
        op = strdup(node->lexeme);
    }
    int type1 = astNodeLeft->dataType;
    int type2 = astNodeRight->dataType;
    char *recordType1, *recordType2;
    if (type1 >= 200) {
        recordType1 = mappingRecordNumberToType[type1 - 200];
    }
    if (type2 >= 200) {
        recordType2 = mappingRecordNumberToType[type2 - 200];
    }

    if (type1 >= 200) {
        hasSemanticErrors = true;
        if (toPrint)
            printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                   lineno, recordType1, type2 >= 200 ? recordType2 : TermSymbol[type2], op);
    } else if (type2 >= 200) {
        hasSemanticErrors = true;
        if (toPrint)
            printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                   lineno, type1 >= 200 ? recordType1 : TermSymbol[type1], recordType2, op);
    } else {
        hasSemanticErrors = true;
        if (toPrint)
            printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                   lineno, TermSymbol[type1], TermSymbol[type2], op);
    }
}


void typeChecker(ParseTree astNode, symbolTable parentSymbolTable, symbolTable globalSymbolTable, ParseTree output,
                 bool assigned[], bool isOutermostWhile, hashtableInt *table, bool toPrint) {
    if (astNode->firstChild == NULL) {
        computeType(astNode, parentSymbolTable, globalSymbolTable, table, toPrint);
        return;
    }

    if (astNode->id == 113 || astNode->id == 118) { //"typeDefinition","declaration"
        return;
    }


    if (astNode->id == 104) {   //"input_par"
        symbolTable inputParSymbolTable = initializeSymbolTable();
        putInSymbolTable(parentSymbolTable, "input_par", TK_NULL);
        addAttribute(parentSymbolTable, "input_par", "inputParScope", inputParSymbolTable);
        ParseTree child = astNode->firstChild;
        char **array = (char **) malloc(sizeof(char *) * astNode->noOfChildren / 2);
        int count = 0;
        int totalOffset = 0;
        while (child != NULL) {
            int offset = 0;
            if (inputParSymbolTable->symbolTableSize != 0 &&
                getSymbolTableEntry(inputParSymbolTable, child->sibling->lexeme) != NULL) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Multiple declaration of %s.\n", child->sibling->lineno, child->sibling->lexeme);
                child = child->sibling->sibling;
                continue;
            }
            if (getSymbolTableEntry(globalSymbolTable, child->sibling->lexeme) != NULL) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Global variable %s cannot be declared as an input parameter.\n", child->lineno,
                           child->sibling->lexeme);
                child = child->sibling->sibling;
                continue;
            }
            if (child->id == TK_RECORDID && getSymbolTableEntry(globalSymbolTable, child->lexeme) == NULL) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Type %s undefined.\n", child->lineno, child->lexeme);
                putInSymbolTable(inputParSymbolTable, child->sibling->lexeme, TK_ID);
                int *val = (int *) malloc(sizeof(int));
                *val = TK_ERROR;
                addAttribute(inputParSymbolTable, child->sibling->lexeme, "dataType", val);
            } else {
                putInSymbolTable(inputParSymbolTable, child->sibling->lexeme, TK_ID);
                addAttribute(inputParSymbolTable, child->sibling->lexeme, "dataType", &child->id);
                addAttribute(inputParSymbolTable, child->sibling->lexeme, "recordType",
                             child->lexeme);
                if (child->id == TK_INT) {
                    offset += 2;
                } else if (child->id == TK_REAL) {
                    offset += 4;
                } else {
                    int *recordType = (int *) getAttributeValue(globalSymbolTable, astNode->firstChild->lexeme,
                                                                "fieldTypes");
                    symbolTable recordScope = (symbolTable) getAttributeValue(globalSymbolTable,
                                                                              astNode->firstChild->lexeme,
                                                                              "recordScope");
                    for (int i = 0; i < recordScope->symbolTableSize; i++) {
                        if (recordType[i] == TK_INT) {
                            offset += 2;
                        } else {
                            offset += 4;
                        }
                    }
                }
                array[count] = strdup(child->lexeme);
                count++;
            }
            char *offString = (char *) malloc(sizeof(char) * 4);
            sprintf(offString, "%d", totalOffset);
            totalOffset += offset;
            addAttribute(inputParSymbolTable, child->sibling->lexeme, "offset", offString);
            child = child->sibling->sibling;
        }
        addAttribute(parentSymbolTable, "input_par", "parameterTypes", array);
        char *offString = (char *) malloc(sizeof(char) * 4);
        sprintf(offString, "%d", totalOffset);
        addAttribute(parentSymbolTable, "input_par", "offset", offString);
        return;
    }

    if (astNode->id == 105) {   //"output_par"
        symbolTable outputParSymbolTable = initializeSymbolTable();
        putInSymbolTable(parentSymbolTable, "output_par", TK_NULL);
        addAttribute(parentSymbolTable, "output_par", "outputParScope", outputParSymbolTable);
        ParseTree child = astNode->firstChild;
        char **array = (char **) malloc(sizeof(char *) * astNode->noOfChildren / 2);
        int count = 0;
        int totalOffset = atoi((char *) getAttributeValue(parentSymbolTable, "input_par", "offset"));
        while (child != NULL) {
            int offset = 0;
            if ((outputParSymbolTable->symbolTableSize != 0 &&
                 getSymbolTableEntry(outputParSymbolTable, child->sibling->lexeme) != NULL) ||
                (getSymbolTableEntry((symbolTable) getAttributeValue(parentSymbolTable, "input_par", "inputParScope"),
                                     child->sibling->lexeme) != NULL)) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Multiple declaration of %s.\n", child->sibling->lineno, child->sibling->lexeme);
                child = child->sibling->sibling;
                continue;
            }
            if (getSymbolTableEntry(globalSymbolTable, child->sibling->lexeme) != NULL) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Global variable %s cannot be declared as an output parameter.\n", child->lineno,
                           child->sibling->lexeme);
                child = child->sibling->sibling;
                continue;
            }
            if (child->id == TK_RECORDID && getSymbolTableEntry(globalSymbolTable, child->lexeme) == NULL) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Type %s undefined.\n", child->lineno, child->lexeme);
                putInSymbolTable(outputParSymbolTable, child->sibling->lexeme, TK_ID);
                int *val = (int *) malloc(sizeof(int));
                *val = TK_ERROR;
                addAttribute(outputParSymbolTable, child->sibling->lexeme, "dataType", val);
            } else {
                putInSymbolTable(outputParSymbolTable, child->sibling->lexeme, TK_ID);
                addAttribute(outputParSymbolTable, child->sibling->lexeme, "dataType", &child->id);
                addAttribute(outputParSymbolTable, child->sibling->lexeme, "recordType",
                             child->lexeme);
                if (child->id == TK_INT) {
                    offset += 2;
                } else if (child->id == TK_REAL) {
                    offset += 4;
                } else {
                    int *recordType = (int *) getAttributeValue(globalSymbolTable, astNode->firstChild->lexeme,
                                                                "fieldTypes");
                    symbolTable recordScope = (symbolTable) getAttributeValue(globalSymbolTable,
                                                                              astNode->firstChild->lexeme,
                                                                              "recordScope");
                    for (int i = 0; i < recordScope->symbolTableSize; i++) {
                        if (recordType[i] == TK_INT) {
                            offset += 2;
                        } else {
                            offset += 4;
                        }
                    }
                }
                array[count] = strdup(child->lexeme);
                count++;
            }
            char *offString = (char *) malloc(sizeof(char) * 4);
            sprintf(offString, "%d", totalOffset);
            totalOffset += offset;
            addAttribute(outputParSymbolTable, child->sibling->lexeme, "offset", offString);
            child = child->sibling->sibling;
        }
        addAttribute(parentSymbolTable, "output_par", "parameterTypes", array);
        char *offString = (char *) malloc(sizeof(char) * 4);
        sprintf(offString, "%d", totalOffset);
        addAttribute(parentSymbolTable, "output_par", "offset", offString);
        return;
    }

    if (astNode->id == 103) {   //"function"
        symbolTable funcSymbolTable = (symbolTable) getAttributeValue(globalSymbolTable, astNode->firstChild->lexeme,
                                                                      "funcScope");
        void *value = getAttributeValue(globalSymbolTable, astNode->firstChild->lexeme, "isOverloaded");
        if (value != NULL && strcmp((char *) value, "True") == 0) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : Function (%s) overloading not allowed.\n", astNode->firstChild->lineno,
                       astNode->firstChild->lexeme);
            return;
        }
        addAttribute(globalSymbolTable, astNode->firstChild->lexeme, "isOverloaded", "True");
        ParseTree child = astNode->firstChild;
        ParseTree output_par = astNode->firstChild->sibling->sibling;
        int noOfOutputPar = (output_par->noOfChildren) / 2;
        bool assignedPar[noOfOutputPar];
        memset(assignedPar, 0, sizeof(bool) * noOfOutputPar);
        int endLine = 0;
        hashtableInt *newTable = createHashtableInt(101);
        for (int i = 0; i < astNode->noOfChildren; i++) {
            typeChecker(child, funcSymbolTable, globalSymbolTable, output_par, assignedPar, isOutermostWhile, newTable,
                        toPrint);
            if (i == astNode->noOfChildren - 1) {
                endLine = child->lineno;
            }
            child = child->sibling;
        }

        ParseTree outPar = output_par->firstChild;
        for (int i = 0; i < noOfOutputPar; i++) {
            if (!assignedPar[i]) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Lines %d-%d : Output parameter %s is not assigned any value in function %s\n",
                           astNode->firstChild->lineno, endLine, outPar->sibling->lexeme,
                           astNode->firstChild->lexeme);
            }
            outPar = outPar->sibling->sibling;
        }
        return;
    }

    if (astNode->id == 101) { //"mainFunction"
        symbolTable funcSymbolTable = (symbolTable) getAttributeValue(globalSymbolTable, "_main", "funcScope");
        ParseTree child = astNode->firstChild;
        hashtableInt *newTable = createHashtableInt(101);
        for (int i = 0; i < astNode->noOfChildren; i++) {
            typeChecker(child, funcSymbolTable, globalSymbolTable, NULL, NULL, isOutermostWhile, newTable, toPrint);
            child = child->sibling;
        }
        return;
    }

    if (astNode->id == 128 && isOutermostWhile) { //"iterativeStmt"
        ParseTree child = astNode->firstChild;
        for (int i = 0; i < astNode->noOfChildren; i++) {
            typeChecker(child, parentSymbolTable, globalSymbolTable, output, assigned, false, table, toPrint);
            child = child->sibling;
        }
        bool *array = (bool *) malloc(sizeof(bool) * INITIAL_CAPACITY);
        memset(array, false, sizeof(bool) * INITIAL_CAPACITY);
        handleIterativeSemantics(astNode, array, NULL, toPrint);
        return;
    }

    //recursive calls to children
    ParseTree child = astNode->firstChild;
    for (int i = 0; i < astNode->noOfChildren; i++) {
        typeChecker(child, parentSymbolTable, globalSymbolTable, output, assigned, isOutermostWhile, table, toPrint);
        child = child->sibling;
    }

    // type checking
    if (astNode->id == 140 || astNode->id == 133 ||
        astNode->id == 123) { // "all"|"arithmeticExpression"|"singleOrRecId"
        astNode->dataType = astNode->firstChild->dataType;
    }

    if (astNode->id == TK_PLUS || astNode->id == TK_MINUS) {
        int type1 = astNode->firstChild->dataType;
        int type2 = astNode->firstChild->sibling->dataType;
        if (type1 == TK_ERROR && type2 == TK_ERROR) {
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 == TK_ERROR || type2 == TK_ERROR) {
            astNode->dataType = TK_ERROR;
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                       astNode->lineno, type1 >= 200 ? mappingRecordNumberToType[type1 - 200] : TermSymbol[type1],
                       type2 >= 200 ? mappingRecordNumberToType[type2 - 200] : TermSymbol[type2], astNode->lexeme);
            return;
        }
        if (type1 != type2) {
            misMatchError(astNode, toPrint);
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 == TK_BOOLEAN) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type TK_BOOLEAN cannot be used with the operator %s.\n",
                       astNode->lineno, astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        astNode->dataType = type1;
    }

    if (astNode->id == TK_MUL) {
        int type1 = astNode->firstChild->dataType;
        int type2 = astNode->firstChild->sibling->dataType;
        if (type1 == TK_ERROR && type2 == TK_ERROR) {
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 == TK_ERROR || type2 == TK_ERROR) {
            astNode->dataType = TK_ERROR;
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                       astNode->lineno, type1 >= 200 ? mappingRecordNumberToType[type1 - 200] : TermSymbol[type1],
                       type2 >= 200 ? mappingRecordNumberToType[type2 - 200] : TermSymbol[type2], astNode->lexeme);
            return;
        }
        if ((type1 >= 200 && (type2 == TK_INT || type2 == TK_REAL)) ||
            (type2 >= 200 && (type1 == TK_INT || type1 == TK_REAL))) {
            astNode->dataType = type1 > type2 ? type1 : type2;
            return;
        }
        if (type1 >= 200 && type2 >= 200) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type TK_RECORD cannot be used with the operator %s.\n",
                       astNode->lineno, astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 != type2) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                       astNode->lineno, TermSymbol[type1], TermSymbol[type2], astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 == TK_BOOLEAN) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type TK_BOOLEAN cannot be used with the operator %s.\n",
                       astNode->lineno, astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        astNode->dataType = type1;
    }

    if (astNode->id == TK_DIV) {
        int type1 = astNode->firstChild->dataType;
        int type2 = astNode->firstChild->sibling->dataType;
        if (type1 == TK_ERROR && type2 == TK_ERROR) {
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 == TK_ERROR || type2 == TK_ERROR) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                       astNode->lineno, type1 >= 200 ? mappingRecordNumberToType[type1 - 200] : TermSymbol[type1],
                       type2 >= 200 ? mappingRecordNumberToType[type2 - 200] : TermSymbol[type2], astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type2 >= 200) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type TK_RECORD cannot be used on the right side of operator %s.\n",
                       astNode->lineno, astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        if ((type1 >= 200 && (type2 == TK_INT || type2 == TK_REAL))) {
            astNode->dataType = type1;
            return;
        }
        if (type1 != type2) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                       astNode->lineno, TermSymbol[type1], TermSymbol[type2], astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 == TK_BOOLEAN) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type TK_BOOLEAN cannot be used with the operator %s.\n",
                       astNode->lineno, astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        astNode->dataType = type1;
    }

    if (astNode->id == 131) { // "ioStmt"
        if (astNode->firstChild->id == TK_WRITE) {
            return;
        }
        checkIfAssigned(astNode->firstChild->sibling->lexeme, output, assigned);
        return;
    }

    if (astNode->id == 122) { // "assignmentStmt"
        checkIfAssigned(astNode->firstChild->firstChild->lexeme, output, assigned);

        int type1 = astNode->firstChild->dataType;
        int type2 = astNode->firstChild->sibling->dataType;
        if (type1 == TK_ERROR && type2 == TK_ERROR) {
            return;
        }
        if (type2 == TK_ERROR) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type %s on the left side does not match with the type %s on the right side of <---.\n",
                       astNode->firstChild->firstChild->lineno,
                       type1 >= 200 ? mappingRecordNumberToType[type1 - 200] : TermSymbol[type1],
                       TermSymbol[type2]);
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 != type2) {
            misMatchError(astNode, toPrint);
            astNode->dataType = TK_ERROR;
            return;
        }
        astNode->dataType = type1;
    }

    if (astNode->id == TK_LE || astNode->id == TK_LT || astNode->id == TK_GE || astNode->id == TK_GT
        || astNode->id == TK_NE || astNode->id == TK_EQ) {  //"relational Operator"
        int type1 = astNode->firstChild->dataType;
        int type2 = astNode->firstChild->sibling->dataType;
        if (type1 == TK_ERROR && type2 == TK_ERROR) {
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 == TK_ERROR || type2 == TK_ERROR) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                       astNode->lineno, TermSymbol[type1], TermSymbol[type2], astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        if ((type1 == TK_INT || type1 == TK_REAL) && (type2 == TK_INT || type2 == TK_REAL)) {
            if (type1 != type2) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                           astNode->lineno, TermSymbol[type1], TermSymbol[type2], astNode->lexeme);
                astNode->dataType = TK_ERROR;
                return;
            } else {
                astNode->dataType = TK_BOOLEAN;
            }
        } else {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type TK_RECORD cannot be used with the operator %s.\n",
                       astNode->lineno, astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
    }

    if (astNode->id == TK_AND || astNode->id == TK_OR) {    //"logical Operator"
        int type1 = astNode->firstChild->dataType;
        int type2 = astNode->firstChild->sibling->dataType;
        if (type1 == TK_ERROR && type2 == TK_ERROR) {
            astNode->dataType = TK_ERROR;
            return;
        }
        if (type1 == TK_ERROR || type2 == TK_ERROR) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type %s on the left side does not match with the type %s on the right side of operator %s.\n",
                       astNode->lineno, TermSymbol[type1], TermSymbol[type2], astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        astNode->dataType = TK_BOOLEAN;
    }

    if (astNode->id == TK_NOT) {
        if (astNode->firstChild->dataType != TK_BOOLEAN) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The type %s cannot be used with the operator %s.\n",
                       astNode->lineno, TermSymbol[astNode->firstChild->dataType], astNode->lexeme);
            astNode->dataType = TK_ERROR;
            return;
        }
        astNode->dataType = TK_BOOLEAN;
    }

    if (astNode->id == 125) {   //"funCallStmt"
        ParseTree temp = astNode->firstChild;
        int noOfInput = 0;
        int noOfOutput = 0;
        while (temp->id != TK_FUNID) {
            noOfOutput++;
            checkIfAssigned(temp->lexeme, output, assigned);
            temp = temp->sibling;
        }
        if (getSymbolTableEntry(globalSymbolTable, temp->lexeme) == NULL) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : Implicit declaration of function %s.\n", temp->lineno, temp->lexeme);
            return;
        }
        symbolTable funcSymbolTable = (symbolTable) getAttributeValue(globalSymbolTable, temp->lexeme, "funcScope");
        if (funcSymbolTable == parentSymbolTable) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : Function cannot be invoked recursively.\n", temp->lineno);
            return;
        }
        char **inputParameterTypes = (char **) getAttributeValue(funcSymbolTable, "input_par", "parameterTypes");
        char **outputParameterTypes = (char **) getAttributeValue(funcSymbolTable, "output_par", "parameterTypes");
        int noOfInputPar = ((symbolTable) getAttributeValue(funcSymbolTable, "input_par",
                                                            "inputParScope"))->symbolTableSize;
        int noOfOutputPar = ((symbolTable) getAttributeValue(funcSymbolTable, "output_par",
                                                             "outputParScope"))->symbolTableSize;
        temp = temp->sibling;
        while (temp != NULL) {
            noOfInput++;
            temp = temp->sibling;
        }
        temp = astNode->firstChild;
        int counterInput = 0, counterOutput = 0;
        if (noOfInput != noOfInputPar) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : Number of actual parameters must be same as number of formal parameters.\n",
                       temp->lineno);
            return;
        } else if (noOfOutput != noOfOutputPar) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : Expected %d output parameter(s), got %d.\n", temp->lineno,
                       noOfOutputPar, noOfOutput);
            return;
        }

        while (counterOutput < noOfOutputPar) {
            char *type = outputParameterTypes[counterOutput];
            int dataType;
            if (strcmp(type, "int") != 0 && strcmp(type, "real") != 0) {
                dataType = *(int *) getAttributeValue(globalSymbolTable, type, "recordNumber");
            } else {
                dataType = strcmp(type, "int") == 0 ? TK_INT : TK_REAL;
            }
            if (temp->dataType != dataType) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Parameter types do not match for %s.\n", temp->lineno, temp->lexeme);
                return;
            }
            temp = temp->sibling;
            counterOutput++;
        }
        temp = temp->sibling;
        while (counterInput < noOfInputPar) {
            char *type = inputParameterTypes[counterInput];
            int dataType;
            if (strcmp(type, "int") != 0 && strcmp(type, "real") != 0) {
                dataType = *(int *) getAttributeValue(globalSymbolTable, type, "recordNumber");
            } else {
                dataType = strcmp(type, "int") == 0 ? TK_INT : TK_REAL;
            }
            if (temp->dataType != dataType) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Parameter types do not match for %s.\n", temp->lineno, temp->lexeme);
                return;
            }
            temp = temp->sibling;
            counterInput++;
        }
    }

    if (astNode->id == 146) { //"returnStmt"
        ParseTree child = astNode->firstChild->sibling;
        ParseTree outPar = output == NULL ? NULL : output->firstChild;
        int noOfReturned = astNode->noOfChildren - 1;
        int noOfOutput = output == NULL ? 0 : output->noOfChildren / 2;
        if (noOfReturned != noOfOutput && output != NULL) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : The number of parameters (%d) being returned does not match with the number of formal output parameters (%d)\n",
                       astNode->firstChild->lineno, noOfReturned, noOfOutput);
            return;
        }
        if (noOfReturned != noOfOutput && output == NULL) {
            hasSemanticErrors = true;
            if (toPrint)
                printf("Line %d : Main Function cannot return variables\n", child->lineno);
            return;
        }
        while (outPar != NULL) {
            if (strcmp(child->lexeme, outPar->sibling->lexeme) != 0) {
                hasSemanticErrors = true;
                if (toPrint)
                    printf("Line %d : Variable %s being returned does not match with the formal output parameter %s\n",
                           child->lineno, child->lexeme, outPar->sibling->lexeme);
            }
            outPar = outPar->sibling->sibling;
            child = child->sibling;
        }
    }
}

symbolTable buildSymbolTable(ParseTree astNode, bool toPrint) {
    if (astNode == NULL) {
        return initializeSymbolTable();
    }
    mappingRecordNumberToType = (char **) malloc(sizeof(char *) * INITIAL_CAPACITY);
    symbolTable globalSymbolTable = initializeSymbolTable();
    buildSymbolTableHelper(globalSymbolTable, globalSymbolTable, astNode, 0, NULL, toPrint);
    typeChecker(astNode, globalSymbolTable, globalSymbolTable, NULL, NULL, true, NULL, toPrint);
    return globalSymbolTable;
}

void
printVariable(symbolTable currSymbolTable, symbolTable globalSymbolTable, ParseTree node, char *scope, char *offset) {
    ParseTree child = node->sibling;
    void *value = getAttributeValue(currSymbolTable, child->lexeme, "isMultiplyDeclared");
    if (value == NULL) {
        char *type = (char *) malloc(50 * sizeof(char));
        if (node->id == 7) {
            int *array = (int *) getAttributeValue(globalSymbolTable, node->lexeme, "fieldTypes");
            symbolTable recordSymbolTable = (symbolTable) getAttributeValue(globalSymbolTable, node->lexeme,
                                                                            "recordScope");
            int size = recordSymbolTable->symbolTableSize;
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    strcpy(type, array[i] == TK_INT ? "int" : "real");
                } else {
                    type = strcat(type, array[i] == TK_INT ? ",int" : ",real");
                }
            }
        } else {
            strcpy(type, node->id == TK_INT ? "int" : "real");
        }
        int val = 0;
        char *offsetString = (char *) getAttributeValue(currSymbolTable, child->lexeme, "offset");
        if (strcmp(offsetString, "-") == 0) {
            printf("%30s |%30s |%30s |%10s\n", child->lexeme, type, "global", "-");
        } else {
            if (offset == NULL) {
                val = atoi(offsetString);
            } else {
                val = atoi(offsetString) + atoi(offset);
            }
            printf("%30s |%30s |%30s |%10d\n", child->lexeme, type, scope, val);
        }
        addAttribute(currSymbolTable, child->lexeme, "isMultiplyDeclared", "True");
    }
}

void printTableHelper(ParseTree node, symbolTable currSymbolTable, symbolTable globalSymbolTable, char *scope,
                      char *offsetString) {
    if (node->firstChild == NULL) {
        return;
    }
    if (node->id == 103) {  //"function"
        ParseTree child = node->firstChild;
        for (int i = 0; i < node->noOfChildren; i++) {
            symbolTable functionTable = (symbolTable) getAttributeValue(globalSymbolTable, node->firstChild->lexeme,
                                                                        "funcScope");
            printTableHelper(child, functionTable, globalSymbolTable, node->firstChild->lexeme,
                             (char *) getAttributeValue(functionTable, "output_par", "offset"));
            child = child->sibling;
        }
        return;
    }

    if (node->id == 118) {  //"declaration"
        ParseTree child = node->firstChild;
        if (node->noOfChildren == 3) {
            void *type = getAttributeValue(globalSymbolTable, child->sibling->lexeme, "dataType");
            if (getSymbolTableEntry(currSymbolTable, child->sibling->lexeme) == NULL && type != NULL &&
                *(int *) type != TK_ERROR) {
                printVariable(globalSymbolTable, globalSymbolTable, child, scope,
                              strcmp(scope, "_main") == 0 ? NULL : offsetString);
            }
        } else {
            void *type = getAttributeValue(currSymbolTable, child->sibling->lexeme, "dataType");
            if (getSymbolTableEntry(globalSymbolTable, child->sibling->lexeme) == NULL && type != NULL &&
                *(int *) type != TK_ERROR) {
                printVariable(currSymbolTable, globalSymbolTable, child, scope,
                              strcmp(scope, "_main") == 0 ? NULL : offsetString);
            }
        }
        return;
    }

    if (node->id == 104) {  //"input_par"
        symbolTable inputTable = (symbolTable) getAttributeValue(currSymbolTable, "input_par", "inputParScope");
        ParseTree child = node->firstChild;
        while (child != NULL) {
            void *type = getAttributeValue(inputTable, child->sibling->lexeme, "dataType");
            if (type != NULL && *(int *) type != TK_ERROR) {
                printVariable(inputTable, globalSymbolTable, child, scope, "0");
            }
            child = child->sibling->sibling;
        }
        return;
    }

    if (node->id == 105) {  //"output_par"
        symbolTable outputTable = (symbolTable) getAttributeValue(currSymbolTable, "output_par", "outputParScope");
        ParseTree child = node->firstChild;
        while (child != NULL) {
            void *type = getAttributeValue(outputTable, child->sibling->lexeme, "dataType");
            if (type != NULL && *(int *) type != TK_ERROR) {
                printVariable(outputTable, globalSymbolTable, child, scope, "0");
            }
            child = child->sibling->sibling;
        }
        return;
    }

    if (node->id == 101) {
        ParseTree child = node->firstChild;
        for (int i = 0; i < node->noOfChildren; i++) {
            symbolTable functionTable = (symbolTable) getAttributeValue(globalSymbolTable, "_main", "funcScope");
            printTableHelper(child, functionTable, globalSymbolTable, "_main", NULL);
            child = child->sibling;
        }
        return;
    }

    ParseTree child = node->firstChild;
    for (int i = 0; i < node->noOfChildren; i++) {
        printTableHelper(child, currSymbolTable, globalSymbolTable, scope, offsetString);
        child = child->sibling;
    }
}

void printTable(ParseTree root, symbolTable globalSymbolTable) {
    if (root == NULL) {
        return;
    }
    printf("%30s |%30s |%30s |%10s\n", "Lexeme", "Type", "Scope", "Offset");
    printf("%30s |%30s |%30s |%10s\n", "", "", "", "");
    printTableHelper(root, globalSymbolTable, globalSymbolTable, "global", NULL);
}

void printFunctionWidthHelper(ParseTree node, symbolTable globalSymbolTable) {
    if (node->firstChild == NULL) {
        return;
    }
    if (node->id == 103) {  //"function"
        if (strcmp((char *) getAttributeValue(globalSymbolTable, node->firstChild->lexeme, "isOverloaded"), "True") ==
            0) {
            addAttribute(globalSymbolTable, node->firstChild->lexeme, "isOverloaded", "False");
            void *off = getAttributeValue(globalSymbolTable, node->firstChild->lexeme, "offset");
            symbolTable funcTable = (symbolTable) getAttributeValue(globalSymbolTable, node->firstChild->lexeme,
                                                                    "funcScope");
            int offset = atoi((char *) getAttributeValue(funcTable, "output_par", "offset")) + *(int *) off;
            printf("%30s |%30d\n", node->firstChild->lexeme, offset);
        }
        return;
    }

    if (node->id == 101) {  //"mainFunction"
        void *off = getAttributeValue(globalSymbolTable, "_main", "offset");
        int offset = *(int *) off;
        printf("%30s |%30d\n", "_main", offset);
        return;
    }

    ParseTree child = node->firstChild;
    for (int i = 0; i < node->noOfChildren; i++) {
        printFunctionWidthHelper(child, globalSymbolTable);
        child = child->sibling;
    }
}

void printFunctionWidth(ParseTree root, symbolTable globalSymbolTable) {
    if (root == NULL) {
        return;
    }
    printf("%30s |%30s\n", "Function", "Width");
    printf("%30s |%30s\n", "", "");
    printFunctionWidthHelper(root, globalSymbolTable);
}

void printVariableGlobal(symbolTable globalSymbolTable, ParseTree node) {
    ParseTree child = node->sibling;
    void *value = getAttributeValue(globalSymbolTable, child->lexeme, "isMultiplyDeclared");
    if (value == NULL) {
        char *type = (char *) malloc(50 * sizeof(char));
        if (node->id == 7) {
            int *array = (int *) getAttributeValue(globalSymbolTable, node->lexeme, "fieldTypes");
            symbolTable recordSymbolTable = (symbolTable) getAttributeValue(globalSymbolTable, node->lexeme,
                                                                            "recordScope");
            int size = recordSymbolTable->symbolTableSize;
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    strcpy(type, array[i] == TK_INT ? "int" : "real");
                } else {
                    type = strcat(type, array[i] == TK_INT ? ",int" : ",real");
                }
            }
        } else {
            strcpy(type, node->id == TK_INT ? "int" : "real");
        }
        printf("%30s |%30s |%30s\n", child->lexeme, type,
               (char *) getAttributeValue(globalSymbolTable, child->lexeme, "globalOffset"));

        addAttribute(globalSymbolTable, child->lexeme, "isMultiplyDeclared", "True");
    }
}


void printGlobalVarHelper(ParseTree node, symbolTable globalSymbolTable) {
    if (node->firstChild == NULL) {
        return;
    }

    if (node->id == 118) {  //"declaration"
        if (node->noOfChildren == 3) {
            void *val = getAttributeValue(globalSymbolTable, node->firstChild->sibling->lexeme, "dataType");
            if (val != NULL && *(int *) val != TK_ERROR) {
                printVariableGlobal(globalSymbolTable, node->firstChild);
            }
        }
        return;
    }

    ParseTree child = node->firstChild;
    for (int i = 0; i < node->noOfChildren; i++) {
        printGlobalVarHelper(child, globalSymbolTable);
        child = child->sibling;
    }
}

void printGlobalVar(ParseTree root, symbolTable globalSymbolTable) {
    if (root == NULL) {
        return;
    }
    printf("%30s |%30s |%30s\n", "Lexeme", "Type", "Offset");
    printf("%30s |%30s |%30s\n", "", "", "");
    printGlobalVarHelper(root, globalSymbolTable);
}

void printRecord(symbolTable globalSymbolTable, ParseTree node) {
    ParseTree child = node->firstChild;
    void *value = getAttributeValue(globalSymbolTable, child->lexeme, "isMultiplyDeclared");
    if (value == NULL) {
        char *type = (char *) malloc(50 * sizeof(char));
        int *array = (int *) getAttributeValue(globalSymbolTable, child->lexeme, "fieldTypes");
        symbolTable recordSymbolTable = (symbolTable) getAttributeValue(globalSymbolTable, child->lexeme,
                                                                        "recordScope");
        int offset = 0;
        int size = recordSymbolTable->symbolTableSize;
        for (int i = 0; i < size; i++) {
            offset += array[i] == TK_INT ? 2 : 4;
            if (i == 0) {
                strcpy(type, array[i] == TK_INT ? "int" : "real");
            } else {
                type = strcat(type, array[i] == TK_INT ? ",int" : ",real");
            }
        }
        printf("%30s |%30s |%30d\n", child->lexeme, type, offset);
        addAttribute(globalSymbolTable, child->lexeme, "isMultiplyDeclared", "True");
    }
}

void printRecordDefinitionsHelper(ParseTree node, symbolTable globalSymbolTable) {
    if (node->firstChild == NULL) {
        return;
    }
    if (node->id == 113) { // "Type definition"
        printRecord(globalSymbolTable, node);
        return;
    }

    ParseTree child = node->firstChild;
    for (int i = 0; i < node->noOfChildren; i++) {
        printRecordDefinitionsHelper(child, globalSymbolTable);
        child = child->sibling;
    }

}

void printRecordDefinitions(ParseTree root, symbolTable globalSymbolTable) {
    if (root == NULL) {
        return;
    }
    printf("%30s |%30s |%30s\n", "Lexeme", "Type", "Width");
    printf("%30s |%30s |%30s\n", "", "", "");
    printRecordDefinitionsHelper(root, globalSymbolTable);
}

bool getErrorStatus() {
    return hasSemanticErrors;
}