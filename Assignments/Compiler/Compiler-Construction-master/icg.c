#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "lexerDef.h"
#include "icg.h"
#include "parserDef.h"

#define ATTRIBUTE_KEY_NUM_OF_FIELDS "@numOfFields"
#define ATTRIBUTE_KEY_MAPPED_NAME "@mappedName"
#define ATTRIBUTE_KEY_RECORD_TYPE_ENTRY "@recordTypeEntry"

/*
 * --> Real operations are in different set of variables
 * --> Integer variables i1, i2, i3...
 * --> Labels will be l1, l2, l3...
 * --> v denotes a variable
 * --> a denotes an atomic expression (variable or a constant)
 * --> t denotes type of variable (int/#record)
 *
 * Types of operations supported in Intermediate Language
 *
 *                                                          Quadruple representation
 *
 *                                                      op  |  arg1  |  arg2  |  result
 *                                                      --------------------------------
 *  1. t v                    variable declaration      T   |   t    |   v    |    -
 *  2. v = v1 op a            op is binary operator     op  |   v1   |   a    |    v
 *  3. v = a                  copy instruction          =   |   a    |   -    |    v
 *  4. L                      Label                     L   |   -    |   -    |    L
 *  5. goto L                 unconditional jump to L   G   |   -    |   -    |    L
 *  6. if v relop a goto L    conditional jump to L     I   |   v    |   a    |    L
 *  7. read v                 read into variable v      R   |   v    |        |
 *  8. write v                write from variable v     W   |   v    |        |
 */

symbolTable mapping;
int i = 0, l = 0;

iCode createiCode(char op) {
    iCode code = (iCode) malloc(sizeof(quadruple));
    code->operator = op;
    code->next = NULL;
    return code;
}

iCode concat(iCode q1, iCode q2) {
    if (q1 == NULL)
        return q2;

    if (q2 == NULL)
        return q1;

    iCode curr = q1;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = q2;
    return q1;
}

void storeTypeDefinitionsInfo(ParseTreeNode* typeDefinitions) {
    ParseTreeNode* typeDefinition = typeDefinitions->firstChild;

    while (typeDefinition != NULL) {
        SymbolTableEntry* sEntry = putInSymbolTable(mapping, typeDefinition->firstChild->lexeme, TK_RECORDID);
        int noOfFields = typeDefinition->noOfChildren - 1;

        ParseTreeNode* fieldDefinition = typeDefinition->firstChild->sibling;

        while (fieldDefinition != NULL) {
            //add field definition entry
            addAttributeInEntryi(sEntry, fieldDefinition->firstChild->sibling->lexeme, TK_INT);
            fieldDefinition = fieldDefinition->sibling;
        }

        addAttributeInEntryi(sEntry, ATTRIBUTE_KEY_NUM_OF_FIELDS, noOfFields);
        typeDefinition = typeDefinition->sibling;
    }
}

iCode getIntermediateCode(ParseTreeNode* root, int* maxVariableName) {
    mapping = initializeSymbolTable();
    storeTypeDefinitionsInfo(root->firstChild->firstChild);
    iCode program = gcfProgram(root);
    *maxVariableName = i - 1;
    return program;
}

iCode gcfProgram(ParseTreeNode* node) {
    return gcfMainFunction(node->firstChild);
}

iCode gcfMainFunction(ParseTreeNode* node) {
    iCode final = NULL;

    final = concat(final, gcfDeclarations(node->firstChild->sibling));

    ParseTreeNode* stmtNode = node->firstChild->sibling->sibling;
    while (stmtNode->ruleno != 87) { // 87 corresponds to return
        final = concat(final, gcfStatement(stmtNode));
        stmtNode = stmtNode->sibling;
    }

    return final;
}

iCode gcfDeclarations(ParseTreeNode* node) {
    iCode final = NULL;

    ParseTreeNode* declaration = node->firstChild;
    while (declaration != NULL) {
        iCode d = gcfDeclaration(declaration);
        final = concat(final, d);
        declaration = declaration->sibling;
    }

    return final;
}

iCode gcfDeclaration(ParseTreeNode* node) {
    iCode final = NULL;
    Token type = node->firstChild->id;
    char* variableName = node->firstChild->sibling->lexeme;

    if (type == TK_RECORDID) {
        char* recordName = node->firstChild->lexeme;
        SymbolTableEntry* sEntry = getSymbolTableEntry(mapping, recordName);
        SymbolTableEntry* recordTypeEntry = sEntry;
        int numOfFields = getAttributeValueFromEntryi(sEntry, ATTRIBUTE_KEY_NUM_OF_FIELDS);
        Attribute* attributes = sEntry->attributes;

        for (int j = 0; j < numOfFields; j++) {
            iCode code = createiCode('T');
            code->arg2.value = i++;
            final = concat(final, code);

            sEntry = putInSymbolTable(mapping, variableName, TK_RECORDID);
            addAttributeInEntryi(sEntry, attributes->key, code->arg2.value); //use the field name as key
            attributes = attributes->next;
        }

        addAttributeInEntry(sEntry, ATTRIBUTE_KEY_RECORD_TYPE_ENTRY, recordTypeEntry);

    } else if (type == TK_INT) {
        iCode code = createiCode('T');
        code->arg2.value = i++;
        final = concat(final, code);

        SymbolTableEntry* sEntry = putInSymbolTable(mapping, node->firstChild->sibling->lexeme, TK_INT);
        addAttributeInEntryi(sEntry, ATTRIBUTE_KEY_MAPPED_NAME, code->arg2.value);
    }

    return final;
}

int evaluateValuei(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

iCode gcfArithmeticExpr(ParseTreeNode *node, int variableName) {
    if (node->ruleno == 56) { // node is arithmeticExpression

        return gcfArithmeticExpr(node->firstChild, variableName);

    } else if (node->ruleno == 68) { // child is TK_NUM

        iCode nodeCode = createiCode('=');
        nodeCode->arg1.type = CONST;
        nodeCode->arg1.value = (int) strtol(node->firstChild->lexeme, NULL, 0);
        nodeCode->result.type = VAR;
        nodeCode->result.value = variableName;
        return nodeCode;

    } else if (node->ruleno == 70) { // child is TK_ID (noOfChildren == 1 => normal identifier & noOfChildren == 2 => record identifier)

        if (node->noOfChildren == 1) {

            iCode nodeCode = createiCode('=');
            nodeCode->result.type = VAR;
            nodeCode->result.value = variableName;
            nodeCode->arg1.type = VAR;
            nodeCode->arg1.value = getAttributeValuei(mapping, node->firstChild->lexeme, ATTRIBUTE_KEY_MAPPED_NAME);

            return nodeCode;

        } else if (node->noOfChildren == 2) {

            iCode nodeCode = createiCode('=');
            nodeCode->result.type = VAR;
            nodeCode->result.value = variableName;
            nodeCode->arg1.type = VAR;
            nodeCode->arg1.value = getAttributeValuei(mapping, node->firstChild->lexeme, node->firstChild->sibling->lexeme);

            return nodeCode;
        }

    } else { // some other node (+, -, *, /)
        char operator = node->lexeme[0];

        ParseTreeNode* leftChild = node->firstChild;
        ParseTreeNode* rightChild = node->firstChild->sibling;

        iCode leftChildCode = gcfArithmeticExpr(leftChild, i++);

        iCode lastL = leftChildCode;
        while (lastL->next != NULL)
            lastL = lastL->next;

        if ((lastL->operator == '=') && lastL->arg1.type == CONST) {
            /**
             * left side child has a constant number. Discard the variable in which it is stored
             * we can now give the 'node variable' to right child and if it turns out to be variable,
             * we can interchange left and right child codes (this has to be done because of intermediate language format chosen)
             * This will help creating 'immediate value accepting' type instructions
             *
             * if right is a constant too then we can simply evaluate the expression at compile time and assign the result
             * to the 'node variable'
             */


            iCode rightChildCode = gcfArithmeticExpr(rightChild, i++);

            iCode lastR = rightChildCode;
            while (lastR->next != NULL)
                lastR = lastR->next;

            if ((lastR->operator == '=') && lastR->arg1.type == CONST) {
                /**
                 * Right child is also a constant number. Discard the variable in which it is stored, evaluate the result
                 * using both left and right child and make current node equals an assignment of constant to 'node variable'
                 * 
                 * result -> v
                 * arg1 -> a
                 * 
                 * discard v
                 */

                int evaluatedValue = evaluateValuei(operator, lastL->arg1.value, lastR->arg1.value);
                iCode nodeCode = createiCode('=');
                nodeCode->arg1.type = CONST;
                nodeCode->arg1.value = evaluatedValue;
                nodeCode->result.type = VAR;
                nodeCode->result.value = variableName;

                return nodeCode;
                
            } else {
                /**
                 * left child is a constant but
                 * right child is not a constant. Swap left and right child codes to abide by the intermediate code rules
                 */

                //setup node code
                iCode nodeCode = createiCode(operator);
                nodeCode->arg1.type = VAR;
                nodeCode->arg1.value = lastR->result.value;
                nodeCode->arg2.type = CONST;
                nodeCode->arg2.value = lastL->arg1.value;
                nodeCode->result.type = VAR;
                nodeCode->result.value = variableName;


                return concat(rightChildCode, nodeCode);
            }
        } else {
            /**
             * left child is not a constant. So it doesn't matter if right is constant or not.
             * Create a new variable for the right child and create the code.
             */

            //setup right child variables
            iCode rightChildCode = gcfArithmeticExpr(rightChild, i++);

            iCode lastR = rightChildCode;
            while (lastR->next != NULL)
                lastR = lastR->next;
            
            //setup node code
            iCode nodeCode = createiCode(operator);
            nodeCode->arg1.type = VAR;
            nodeCode->arg1.value = lastL->result.value;
            nodeCode->result.type = VAR;
            nodeCode->result.value = variableName;
            
            if (lastR->operator == '=' && lastR->arg1.type == CONST) { //right child is a constant

                nodeCode->arg2.type = CONST;
                nodeCode->arg2.value = lastR->arg1.value;
                return concat(leftChildCode, nodeCode);

            } else { //right is also a variable

                nodeCode->arg2.type = VAR;
                nodeCode->arg2.value = lastR->result.value;
                return concat(concat(leftChildCode, rightChildCode), nodeCode);

            }
        }
    }
}

int* getVariablesVector(int numOfVariables) {
    int* variables = malloc(sizeof(int) * numOfVariables);
    for (int x = 0; x < numOfVariables; x++) {
        variables[x] = i++;
    }
    return variables;
}

iCode gcfRecordArithmeticExpr(ParseTreeNode *node, int numOfVariables, int* variableNames) {

    /*for (int x = 0; x < numOfVariables; x++) {
        printf("i%d ", variableNames[x]);
    }
    printf("\n");*/

    if (node->ruleno == 70) { // variable vector
        iCode nodeCode = NULL;

        SymbolTableEntry* sEntry = getSymbolTableEntry(mapping, node->firstChild->lexeme);
        Attribute* attributes = sEntry->attributes;

        int x = 0;
        while (attributes->next != NULL) {
            iCode code = createiCode('=');
            code->arg1.type = VAR;
            code->result.type = VAR;

            code->arg1.value = (int) attributes->value;
            code->result.value = variableNames[x];

            nodeCode = concat(nodeCode, code);
            attributes = attributes->next;
            x++;
        }

        return nodeCode;
    }

    if (node->id == TK_PLUS || node->id == TK_MINUS) {
        char operator = (node->id == TK_PLUS) ? '+' : '-';
        int* leftVector = getVariablesVector(numOfVariables);
        int* rightVector = getVariablesVector(numOfVariables);

        iCode leftCode = gcfRecordArithmeticExpr(node->firstChild, numOfVariables, leftVector);
        iCode rightCode = gcfRecordArithmeticExpr(node->firstChild->sibling, numOfVariables, rightVector);
        iCode nodeCode = NULL;

        for (int x = 0; x < numOfVariables; x++) {
            iCode code = createiCode(operator);
            code->arg1.type = VAR;
            code->arg2.type = VAR;
            code->result.type = VAR;

            code->arg1.value = leftVector[x];
            code->arg2.value = rightVector[x];
            code->result.value = variableNames[x];

            nodeCode = concat(nodeCode, code);
        }

        return concat(concat(leftCode, rightCode), nodeCode);
    }

    if (node->id == TK_MUL || node->id == TK_DIV) {
        char operator = (node->id == TK_MUL) ? '*' : '/';
        int* variablesVector = getVariablesVector(numOfVariables);

        bool isConst = (node->firstChild->ruleno == 68) || (node->firstChild->sibling->ruleno == 68);
        int value;
        int y;

        if (isConst) {
            y = node->firstChild->dataType == 68; //y == 0 implies vector variable is at the left side and therefore constant is at the right side
            value = (int) ((y == 0) ? strtol(node->firstChild->sibling->firstChild->lexeme, NULL, 0) : strtol(node->firstChild->firstChild->lexeme, NULL, 0));
        } else {
            y = node->firstChild->dataType == 12; // y == 0 implies vector variable is at the left side and therefore scalar is at the right side
            value = getAttributeValuei(mapping, node->firstChild->firstChild->lexeme, ATTRIBUTE_KEY_MAPPED_NAME);
        }

        iCode childCode = gcfRecordArithmeticExpr((y == 0) ? node->firstChild : node->firstChild->sibling, numOfVariables, variablesVector);
        iCode nodeCode = NULL;

        for (int x = 0; x < numOfVariables; x++) {
            iCode code = createiCode(operator);
            code->arg1.type = VAR;
            code->arg2.type = isConst ? CONST : VAR;
            code->result.type = VAR;

            code->arg1.value = variablesVector[x];
            code->arg2.value = value;
            code->result.value = variableNames[x];

            nodeCode = concat(nodeCode, code);
        }

        return concat(childCode, nodeCode);
    }
}

iCode gcfBooleanExpr(ParseTreeNode* node, int labelTrue, int labelFalse) {

    if (node->id == TK_AND) {
        int newLabel = l++;
        iCode leftCondition = gcfBooleanExpr(node->firstChild, newLabel, labelFalse);
        iCode rightCondition = gcfBooleanExpr(node->firstChild->sibling, labelTrue, labelFalse);
        iCode nodeCode = createiCode('L');
        nodeCode->result.value = newLabel;
        return concat(concat(leftCondition, nodeCode), rightCondition);
    }

    if (node->id == TK_OR) {
        int newLabel = l++;
        iCode leftCondition = gcfBooleanExpr(node->firstChild, labelTrue, newLabel);
        iCode rightCondition = gcfBooleanExpr(node->firstChild->sibling, labelTrue, labelFalse);
        iCode nodeCode = createiCode('L');
        nodeCode->result.value = newLabel;
        return concat(concat(leftCondition, nodeCode), rightCondition);
    }

    if (node->id == TK_NOT) {
        return gcfBooleanExpr(node->firstChild, labelFalse, labelTrue);
    }

    if (node->firstChild->id == TK_NUM && node->firstChild->sibling->id == TK_ID) {
        int firstNum = (int) strtol(node->firstChild->lexeme, NULL, 0);
        int secondVar = getAttributeValuei(mapping, node->firstChild->sibling->lexeme, ATTRIBUTE_KEY_MAPPED_NAME);

        iCode nodeCode = createiCode('I');
        nodeCode->condOp = node->id;
        nodeCode->arg1.type = VAR;
        nodeCode->arg1.value = secondVar;
        nodeCode->arg2.type = CONST;
        nodeCode->arg2.value = firstNum;
        nodeCode->result.value = labelTrue;

        iCode nodeCodeJump = createiCode('G');
        nodeCodeJump->result.value = labelFalse;

        return concat(nodeCode, nodeCodeJump);
    }

    if (node->firstChild->id == TK_ID && node->firstChild->sibling->id == TK_NUM) {
        int firstVar = getAttributeValuei(mapping, node->firstChild->lexeme, ATTRIBUTE_KEY_MAPPED_NAME);
        int secondNum = (int) strtol(node->firstChild->sibling->lexeme, NULL, 0);

        iCode nodeCode = createiCode('I');
        nodeCode->condOp = node->id;
        nodeCode->arg1.type = VAR;
        nodeCode->arg1.value = firstVar;
        nodeCode->arg2.type = CONST;
        nodeCode->arg2.value = secondNum;
        nodeCode->result.value = labelTrue;

        iCode nodeCodeJump = createiCode('G');
        nodeCodeJump->result.value = labelFalse;

        return concat(nodeCode, nodeCodeJump);
    }

    if (node->firstChild->id == TK_ID && node->firstChild->sibling->id == TK_ID) {
        int firstVar = getAttributeValuei(mapping, node->firstChild->lexeme, ATTRIBUTE_KEY_MAPPED_NAME);
        int secondVar = getAttributeValuei(mapping, node->firstChild->sibling->lexeme, ATTRIBUTE_KEY_MAPPED_NAME);

        iCode nodeCode = createiCode('I');
        nodeCode->condOp = node->id;
        nodeCode->arg1.type = VAR;
        nodeCode->arg1.value = firstVar;
        nodeCode->arg2.type = VAR;
        nodeCode->arg2.value = secondVar;
        nodeCode->result.value = labelTrue;

        iCode nodeCodeJump = createiCode('G');
        nodeCodeJump->result.value = labelFalse;

        return concat(nodeCode, nodeCodeJump);
    }

    if (node->firstChild->id == TK_NUM && node->firstChild->sibling->id == TK_NUM) {
        int firstNum = (int) strtol(node->firstChild->lexeme, NULL, 0);
        int secondNum = (int) strtol(node->firstChild->sibling->lexeme, NULL, 0);

        int jumpLabel;

        switch (node->id) {
            case TK_LT: jumpLabel = (firstNum < secondNum) ? labelTrue : labelFalse; break;
            case TK_LE: jumpLabel = (firstNum <= secondNum) ? labelTrue : labelFalse; break;
            case TK_EQ: jumpLabel = (firstNum == secondNum) ? labelTrue : labelFalse; break;
            case TK_NE: jumpLabel = (firstNum != secondNum) ? labelTrue : labelFalse; break;
            case TK_GT: jumpLabel = (firstNum > secondNum) ? labelTrue : labelFalse; break;
            case TK_GE: jumpLabel = (firstNum >= secondNum) ? labelTrue : labelFalse; break;
        }

        iCode nodeCode = createiCode('G');
        nodeCode->result.value = jumpLabel;
        return nodeCode;
    }
}

iCode gcfStatement(ParseTreeNode* node) {
    switch (node->ruleno) { //see grammar
        case 32: return gcfAssignmentStatement(node->firstChild);
        case 33: return gcfIterativeStatement(node->firstChild);
        case 34: return gcfConditionalStatement(node->firstChild);
        case 35: return gcfIOStatement(node->firstChild);
        default: return NULL;
    }
}

iCode gcfAssignmentStatement(ParseTreeNode* node) {
    int variableName = 0;

    SymbolTableEntry* sEntry = getSymbolTableEntry(mapping, node->firstChild->firstChild->lexeme);

    if (node->firstChild->noOfChildren == 1 && sEntry->token == TK_INT) { //simple identifier
        variableName = getAttributeValueFromEntryi(sEntry, ATTRIBUTE_KEY_MAPPED_NAME);
    } else if (node->firstChild->noOfChildren == 1 && sEntry->token == TK_RECORDID) {

        sEntry = getSymbolTableEntry(mapping, node->firstChild->firstChild->lexeme);
        Attribute* attributes = sEntry->attributes;
        int* variables = (int*) malloc(sizeof(int) * (sEntry->noOfAttributes - 1));

        int x = 0;
        while (attributes->next != NULL) {
            variables[x++] = (int)attributes->value;
            attributes = attributes->next;
        }

        return gcfRecordArithmeticExpr(node->firstChild->sibling->firstChild, sEntry->noOfAttributes - 1, variables);
    } else if (node->firstChild->noOfChildren == 2) { //record identifier
        variableName = getAttributeValueFromEntryi(sEntry, node->firstChild->firstChild->sibling->lexeme);
    }

    return gcfArithmeticExpr(node->firstChild->sibling, variableName);
}

iCode gcfIterativeStatement(ParseTreeNode* node) {
    int labelRepeat = l++;
    int labelTrue = l++;
    int labelFalse = l++;

    iCode booleanExpression = gcfBooleanExpr(node->firstChild, labelTrue, labelFalse);

    iCode whileStatements = NULL;
    ParseTreeNode* stmt = node->firstChild->sibling;
    for (int x = 1; x < node->noOfChildren - 1; x++, stmt = stmt->sibling) {
        whileStatements = concat(whileStatements, gcfStatement(stmt));
    }

    iCode gotoLabelRepeat = createiCode('G');
    gotoLabelRepeat->result.value = labelRepeat;

    iCode trueLabel = createiCode('L');
    trueLabel->result.value = labelTrue;

    iCode falseLabel = createiCode('L');
    falseLabel->result.value = labelFalse;

    iCode repeatLabel = createiCode('L');
    repeatLabel->result.value = labelRepeat;

    return concat(concat(concat(concat(concat(
            repeatLabel, booleanExpression), trueLabel), whileStatements), gotoLabelRepeat), falseLabel);

}

iCode gcfIOStatement(ParseTreeNode* node) {
    iCode nodeCode;
    int variableName;

    SymbolTableEntry* sEntry = getSymbolTableEntry(mapping, node->firstChild->sibling->lexeme);

    if (node->noOfChildren == 2 && sEntry->token == TK_INT) {
        nodeCode = createiCode((node->firstChild->id == TK_READ) ? 'R' : 'W');
        variableName = getAttributeValuei(mapping, node->firstChild->sibling->lexeme, ATTRIBUTE_KEY_MAPPED_NAME);
    } else if (node->noOfChildren == 2 && sEntry->token == TK_RECORDID) {
        SymbolTableEntry* sEntry = getSymbolTableEntry(mapping, node->firstChild->sibling->lexeme);
        Attribute* attributes = sEntry->attributes;

        iCode final = NULL;

        while (attributes->next != NULL) {
            nodeCode = createiCode((node->firstChild->id == TK_READ) ? 'R' : 'W');
            nodeCode->arg1.value = (int) attributes->value;
            final = concat(final, nodeCode);
            attributes = attributes->next;
        }

        return final;

    } else {
        nodeCode = createiCode((node->firstChild->id == TK_READ) ? 'R' : 'W');;
        variableName = getAttributeValuei(mapping, node->firstChild->sibling->lexeme, node->firstChild->sibling->sibling->lexeme);

    }

    nodeCode->arg1.value = variableName;
    return nodeCode;
}

iCode gcfConditionalStatement(ParseTreeNode* node) {
    int labelTrue = l++;
    int labelFalse = l++;
    iCode booleanExpression = gcfBooleanExpr(node->firstChild, labelTrue, labelFalse);

    iCode ifStatements = NULL;
    iCode elseStatements = NULL;

    ParseTreeNode* stmt = node->firstChild->sibling;
    for (int x = 1; x < node->noOfChildren - 1; x++, stmt = stmt->sibling) {
        ifStatements = concat(ifStatements, gcfStatement(stmt));
    }

    stmt = stmt->firstChild;
    while (stmt != NULL) {
        elseStatements = concat(elseStatements, gcfStatement(stmt));
        stmt = stmt->sibling;
    }

    int labelCont = l++;

    iCode gotoLabelCont = createiCode('G');
    gotoLabelCont->result.value = labelCont;

    iCode trueLabel = createiCode('L');
    trueLabel->result.value = labelTrue;

    iCode falseLabel = createiCode('L');
    falseLabel->result.value = labelFalse;

    iCode contLabel = createiCode('L');
    contLabel->result.value = labelCont;

    return concat(concat(concat(concat(concat(concat
    (booleanExpression, trueLabel), ifStatements), gotoLabelCont), falseLabel), elseStatements), contLabel);
}

void removeRedundantAssignment(iCode code) {
    iCode curr = code;

    while (curr != NULL) {
        if (curr->operator == '=' && curr->arg1.type == VAR && curr->arg1.value == curr->result.value)
            curr->operator = 'x';
        curr = curr->next;
    }
}

void printiCode(iCode code) {
    while (code != NULL) {

        if (code->operator == 'T') {

            printf("int i%d\n", code->arg2.value);

        } else if (code->operator == '=') {

            printf("i%d = ", code->result.value);
            if (code->arg1.type == VAR)
                printf("i%d\n", code->arg1.value);
            else
                printf("%d\n", code->arg1.value);

        } else if (code->operator == '*' || code->operator == '/' || code->operator == '+' || code->operator == '-') {

            printf("i%d = i%d %c ", code->result.value, code->arg1.value, code->operator);
            if (code->arg2.type == VAR)
                printf("i%d\n", code->arg2.value);
            else
                printf("%d\n", code->arg2.value);
        } else if (code->operator == 'G') {

            printf("GOTO L%d\n", code->result.value);
        } else if (code->operator == 'L') {

            printf("L%d:\n", code->result.value);
        } else if (code->operator == 'I') {

            printf("if i%d ", code->arg1.value);

            switch (code->condOp) {
                case TK_LT: printf("<"); break;
                case TK_LE: printf("<=");break;
                case TK_EQ: printf("==");break;
                case TK_NE: printf("!=");break;
                case TK_GT: printf(">");break;
                case TK_GE: printf(">=");break;
            }

            if (code->arg2.type == VAR) {
                printf(" i%d GOTO L%d\n", code->arg2.value, code->result.value);
            } else {
                printf(" %d GOTO L%d\n", code->arg2.value, code->result.value);
            }
        } else if (code->operator == 'R') {

            printf("read(i%d)\n", code->arg1.value);
        } else if (code->operator == 'W') {

            printf("write(i%d)\n", code->arg1.value);
        }

        code = code->next;
    }
}