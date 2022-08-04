/*
GROUP - 14
Created By:
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#include <malloc.h>
#include "ast.h"
#include <string.h>

long int allocatedMemoryAST;
long int freeNode;

void initializeVariableAST() {
    allocatedMemoryAST = getMemory();
    freeNode = getParseNodes();
}

long int getMemoryAST() {
    return allocatedMemoryAST;
}

long int getFreeNode() {
    return freeNode;
}

void calculateMemoryAST(ParseTree node) {
    allocatedMemoryAST -= sizeof(struct tree_node);
    allocatedMemoryAST -= sizeof(char) * strlen(node->lexeme) + sizeof(char) * strlen(node->tokenName);
    allocatedMemoryAST -= sizeof(char) * strlen(node->nodeSymbol);
    freeNode--;
    free(node);
}

ParseTree concatList(ParseTree head1, ParseTree head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    ParseTree temp = head1;
    while (temp->sibling != NULL) {
        temp = temp->sibling;
    }
    temp->sibling = head2;
    return head1;
}

void createASTHelper(ParseTree parent) {
    if (parent->firstChild == NULL) {
        return;
    }

    ParseTree pointer = parent->firstChild;
    for (int i = 0; i < parent->noOfChildren; i++) {
        createASTHelper(pointer);

        // implementing inherited attributes
        if (parent->ruleno == 56 && i == 0) {
            parent->firstChild->sibling->inh = parent->firstChild->firstChild;
        }
        if (parent->ruleno == 57 && i == 1) {
            parent->firstChild->sibling->sibling->inh = parent->firstChild->firstChild;
            parent->firstChild->firstChild->noOfChildren = 2;
            parent->inh->sibling = parent->firstChild->sibling->firstChild;
            parent->firstChild->firstChild->firstChild = parent->inh;
        }
        if (parent->ruleno == 59 && i == 0) {
            parent->firstChild->sibling->inh = parent->firstChild->firstChild;
        }
        if (parent->ruleno == 60 && i == 1) {
            parent->firstChild->sibling->sibling->inh = parent->firstChild->firstChild;
            parent->firstChild->firstChild->noOfChildren = 2;
            parent->inh->sibling = parent->firstChild->sibling->firstChild;
            parent->firstChild->firstChild->firstChild = parent->inh;
        }
        pointer = pointer->sibling;
    }

    // implementing synthesized attributes
    switch (parent->ruleno) {
        case 1: { // program => otherFunctions mainFunction
            parent->noOfChildren = parent->firstChild->noOfChildren + 1;
            ParseTree temp = concatList(parent->firstChild->firstChild, parent->firstChild->sibling);
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = temp;
            break;
        }
        case 2: { // mainFunction => TK_MAIN stmts TK_END
            parent->noOfChildren = parent->firstChild->sibling->noOfChildren;
            calculateMemoryAST(parent->firstChild->sibling->sibling);
            ParseTree temp = parent->firstChild->sibling;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 3: { // otherFunctions => function otherFunctions
            parent->noOfChildren = 1 + parent->firstChild->sibling->noOfChildren;
            ParseTree temp = parent->firstChild->sibling;
            parent->firstChild->sibling = parent->firstChild->sibling->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 4: { // otherFunctions => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 5: { // function => TK_FUNID input_par output_par TK_SEM stmts TK_END
            ParseTree free1 = parent->firstChild->sibling->sibling->sibling;
            parent->noOfChildren = 5;
            parent->firstChild->sibling->sibling->sibling = free1->sibling;
            calculateMemoryAST(free1);
            break;
        }
        case 6: { // input_par => TK_INPUT TK_PARAMETER TK_LIST TK_SQL parameter_list TK_SQR
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling;
            ParseTree free5 = free4->sibling->sibling;
            parent->firstChild = free4->sibling->firstChild;
            parent->noOfChildren = free4->sibling->noOfChildren;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            calculateMemoryAST(free5);
            break;
        }
        case 7: { // output_par => TK_OUTPUT TK_PARAMETER TK_LIST TK_SQL parameter_list TK_SQR
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling;
            ParseTree free5 = free4->sibling->sibling;
            parent->firstChild = free4->sibling->firstChild;
            parent->noOfChildren = free4->sibling->noOfChildren;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            calculateMemoryAST(free5);
            break;
        }
        case 8: { // output_par => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 9: { // parameter_list => dataType TK_ID remaining_list
            parent->noOfChildren = 2 + parent->firstChild->sibling->sibling->noOfChildren;
            ParseTree free1 = parent->firstChild->sibling->sibling;
            ParseTree free2 = parent->firstChild;
            free2->sibling->sibling = free1->firstChild;
            parent->firstChild = concatList(free2->firstChild, free2->sibling);
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            break;
        }
        case 10: { // dataType => primitiveDatatype
            parent->noOfChildren = 1;
            ParseTree temp = parent->firstChild;
            parent->firstChild = parent->firstChild->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 11: { // dataType => constructedDatatype
            parent->noOfChildren = 1;
            ParseTree temp = parent->firstChild;
            parent->firstChild = parent->firstChild->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 12: { // primitiveDatatype => TK_INT
            break;
        }
        case 13: { // primitiveDatatype => TK_REAL
            break;
        }
        case 14: { // constructiveDatatype => TK_RECORD TK_RECORDID
            parent->noOfChildren = 1;
            ParseTree free1 = parent->firstChild;
            parent->firstChild = free1->sibling;
            calculateMemoryAST(free1);
            break;
        }
        case 15: { // remaining_list => TK_COMMA parameter_list
            parent->noOfChildren = parent->firstChild->sibling->noOfChildren;
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = parent->firstChild->sibling;
            parent->firstChild = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            break;
        }
        case 16: { // remaining_list => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 17: { // stmts => typeDefinitions declarations otherStmts returnStmt
            ParseTree free1 = parent->firstChild->sibling->sibling;
            parent->noOfChildren = 3 + free1->noOfChildren;
            parent->firstChild->sibling->sibling = concatList(free1->firstChild, free1->sibling);
            calculateMemoryAST(free1);
            break;
        }
        case 18: { // typeDefinitions => typeDefinition typeDefinitions
            parent->noOfChildren = 1 + parent->firstChild->sibling->noOfChildren;
            ParseTree temp = parent->firstChild->sibling;
            parent->firstChild->sibling = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 19: { // typeDefinitions => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 20: { // typeDefinition => TK_RECORD TK_RECORDID fieldDefinitions TK_ENDRECORD TK_SEM
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling;
            free1->sibling->sibling = free2->firstChild;
            parent->firstChild = free1->sibling;
            parent->noOfChildren = 1 + free2->noOfChildren;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            break;
        }
        case 21: { // fieldDefinitions => fieldDefinition fieldDefinition moreFields
            ParseTree temp = parent->firstChild->sibling->sibling;
            parent->noOfChildren = 2 + temp->noOfChildren;
            parent->firstChild->sibling->sibling = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 22: { // fieldDefinition => TK_TYPE primitiveDatatype TK_COLON TK_FIELDID TK_SEM
            parent->noOfChildren = 2;
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling->sibling;
            free3->sibling->sibling = NULL;
            free2->firstChild->sibling = free3->sibling;
            parent->firstChild = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            break;
        }
        case 23: { // moreFields => fieldDefinition moreFields
            parent->noOfChildren = 1 + parent->firstChild->sibling->noOfChildren;
            ParseTree temp = parent->firstChild->sibling;
            parent->firstChild->sibling = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 24: { // more_fields => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 25: { // declarations => declaration declarations
            parent->noOfChildren = 1 + parent->firstChild->sibling->noOfChildren;
            ParseTree temp = parent->firstChild->sibling;
            parent->firstChild->sibling = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 26: { // declarations => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 27: { // declaration => TK_TYPE dataType TK_COLON TK_ID global_or_not TK_SEM
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling->sibling;
            ParseTree free5 = free4->sibling;
            free2->firstChild->sibling = free3->sibling;
            free3->sibling->sibling = free4->firstChild;
            parent->noOfChildren = 2 + free4->noOfChildren;
            parent->firstChild = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            calculateMemoryAST(free5);
            break;
        }
        case 28: { // global_or_not => TK_COLON TK_GLOBAL
            parent->noOfChildren = 1;
            ParseTree temp = parent->firstChild;
            parent->firstChild = temp->sibling;
            calculateMemoryAST(temp);
            break;
        }
        case 29: { // global_or_not => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 30: { // otherStmts => stmt otherStmts
            parent->noOfChildren = 1 + parent->firstChild->sibling->noOfChildren;
            ParseTree temp = parent->firstChild->sibling;
            parent->firstChild->sibling = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 31: { // otherStmts => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 32: { // stmt => assignmentStmt
            break;
        }
        case 33: { // stmt => iterativeStmt
            break;
        }
        case 34: { // stmt => conditionalStmt
            break;
        }
        case 35: { // stmt => ioStmt
            break;
        }
        case 36: { // stmt => funCallStmt
            break;
        }
        case 37: { // assignmentStmt => singleOrRecId TK_ASSIGNOP arithmeticExpression TK_SEM
            ParseTree free1 = parent->firstChild->sibling;
            ParseTree free2 = free1->sibling->sibling;
            parent->noOfChildren = 2;
            free1->sibling->sibling = NULL;
            parent->firstChild->sibling = free1->sibling;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            break;
        }
        case 38: { // singleOrRecId => TK_ID new_24
            parent->noOfChildren = 1 + parent->firstChild->sibling->noOfChildren;
            ParseTree temp = parent->firstChild->sibling;
            parent->firstChild->sibling = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 39: { // new_24 => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 40: { // new_24 => TK_DOT TK_FIELDID
            parent->noOfChildren = 1;
            ParseTree temp = parent->firstChild;
            parent->firstChild = temp->sibling;
            calculateMemoryAST(temp);
            break;
        }
        case 41: { // funCallStmt => outputParameters TK_CALL TK_FUNID TK_WITH TK_PARAMETERS inputParameters TK_SEM
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling->sibling;
            ParseTree free4 = free3->sibling;
            ParseTree free5 = free4->sibling;
            ParseTree free6 = free5->sibling;
            parent->noOfChildren = 1 + free1->noOfChildren + free5->noOfChildren;
            ParseTree temp = free2->sibling;
            temp->sibling = free5->firstChild;
            parent->firstChild = concatList(free1->firstChild, temp);
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            calculateMemoryAST(free5);
            calculateMemoryAST(free6);
            break;
        }
        case 42: { // outputParameters => TK_SQL idList TK_SQR TK_ASSIGNOP
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling;
            parent->noOfChildren = free2->noOfChildren;
            parent->firstChild = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            break;
        }
        case 43: { // outputParameters => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 44: { // inputParameters => TK_SQL idList TK_SQR
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            parent->noOfChildren = free2->noOfChildren;
            parent->firstChild = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            break;
        }
        case 45: { // iterativeStmt => TK_WHILE TK_OP booleanExpression TK_CL stmt otherStmts TK_ENDWHILE
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling;
            ParseTree free5 = free4->sibling->sibling;
            parent->noOfChildren = 2 + free3->noOfChildren + free5->noOfChildren;
            free4->sibling->sibling = concatList(free5->firstChild, free5->sibling);
            parent->firstChild = concatList(free3->firstChild, free4->sibling);
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            calculateMemoryAST(free5);
            break;
        }
        case 46: { // conditionalStmt => TK_IF TK_OP booleanExpression TK_CL TK_THEN stmt otherStmts elsePart
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling;
            ParseTree free5 = free4->sibling;
            ParseTree free6 = free5->sibling->sibling;
            parent->noOfChildren = 2 + free3->noOfChildren + free6->noOfChildren;
            free5->sibling->sibling = free6->firstChild;
            free5->sibling = concatList(free5->sibling, free6->sibling);
            parent->firstChild = concatList(free3->firstChild, free5->sibling);
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            calculateMemoryAST(free5);
            calculateMemoryAST(free6);
            break;
        }
        case 47: { // elsePart => TK_ELSE stmt otherStmts TK_ENDIF
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling->sibling;
            ParseTree free3 = free2->sibling;
            parent->noOfChildren = 1 + free2->noOfChildren;
            free1->sibling->sibling = free2->firstChild;
            parent->firstChild = free1->sibling;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            break;
        }
        case 48: { // elsePart => TK_ENDIF
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 49: { // ioStmt => TK_READ TK_OP singleOrRecId TK_CL TK_SEM
            ParseTree free1 = parent->firstChild->sibling;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling;
            parent->noOfChildren = 1 + free2->noOfChildren;
            parent->firstChild->sibling = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            break;
        }
        case 50: { // ioStmt => TK_WRITE TK_OP allVar TK_CL TK_SEM
            ParseTree free1 = parent->firstChild->sibling;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling;
            parent->noOfChildren = 1 + free2->noOfChildren;
            parent->firstChild->sibling = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            break;
        }
        case 51: { // allVar => TK_NUM
            break;
        }
        case 52: { // allVar => TK_RNUM
            break;
        }
        case 53: { // allVar => TK_ID tempvar
            ParseTree temp = parent->firstChild->sibling;
            parent->noOfChildren = 1 + temp->noOfChildren;
            parent->firstChild->sibling = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 54: { // tempvar => TK_DOT TK_FIELDID
            ParseTree temp = parent->firstChild;
            parent->firstChild = temp->sibling;
            parent->noOfChildren = 1;
            calculateMemoryAST(temp);
            break;
        }
        case 55: { // tempvar => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 56: { // arithmeticExpression => term expPrime
            parent->noOfChildren = 1;
            ParseTree temp = parent->firstChild;
            ParseTree free = temp->sibling;
            parent->firstChild = parent->firstChild->sibling->syn;
            parent->firstChild->sibling = NULL;
            calculateMemoryAST(temp);
            calculateMemoryAST(free);
            break;
        }
        case 57: { // expPrime => lowPecedenceOperators term expPrime
            ParseTree temp = parent->firstChild->sibling->sibling;
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            parent->syn = parent->firstChild->sibling->sibling->syn;
            calculateMemoryAST(temp);
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            break;
        }
        case 58: { // expPrime => eps
            parent->syn = parent->inh;
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 59: { // term => factor termPrime
            ParseTree temp = parent->firstChild;
            ParseTree free = temp->sibling;
            parent->firstChild = parent->firstChild->sibling->syn;
            parent->firstChild->sibling = NULL;
            calculateMemoryAST(temp);
            calculateMemoryAST(free);
            break;
        }
        case 60: { // termPrime => highPrecedenceOperators factor termPrime
            ParseTree temp = parent->firstChild->sibling->sibling;
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            parent->syn = parent->firstChild->sibling->sibling->syn;
            calculateMemoryAST(temp);
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            break;
        }
        case 61: { // termPrime => eps
            parent->syn = parent->inh;
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 62: { // factor => TK_OP arithmeticExpression TK_CL
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            parent->noOfChildren = free2->noOfChildren;
            parent->firstChild = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            break;
        }
        case 63: { // factor => all
            break;
        }
        case 64: { // highPrecedenceOperators => TK_MUL
            break;
        }
        case 65: { // highPrecedenceOperators => TK_DIV
            break;
        }
        case 66: { // lowPrecedenceOperators => TK_PLUS
            break;
        }
        case 67: { // lowPrecedenceOperators => TK_MINUS
            break;
        }
        case 68: { // all => TK_NUM
            break;
        }
        case 69: { // all => TK_RNUM
            break;
        }
        case 70: { // all => TK_ID temp
            parent->noOfChildren = 1 + parent->firstChild->sibling->noOfChildren;
            ParseTree temp = parent->firstChild->sibling;
            parent->firstChild->sibling = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 71: { // temp => TK_DOT TK_FIELDID
            ParseTree temp = parent->firstChild;
            parent->firstChild = temp->sibling;
            parent->noOfChildren = 1;
            calculateMemoryAST(temp);
            break;
        }
        case 72: { // temp => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 73: { // booleanExpression => TK_OP booleanExpression TK_CL logicalOp TK_OP booleanExpression TK_CL
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            ParseTree free4 = free3->sibling;
            ParseTree free5 = free4->sibling;
            ParseTree free6 = free5->sibling;
            ParseTree free7 = free6->sibling;
            parent->firstChild = free4->firstChild;
            parent->noOfChildren = 1;
            free4->firstChild->firstChild = concatList(free2->firstChild, free6->firstChild);
            free4->firstChild->noOfChildren = free2->noOfChildren + free6->noOfChildren;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            calculateMemoryAST(free4);
            calculateMemoryAST(free5);
            calculateMemoryAST(free6);
            calculateMemoryAST(free7);
            break;
        }
        case 74: { // booleanExpression => var relationalOp var
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            parent->noOfChildren = 1;
            parent->firstChild = free2->firstChild;
            free1->firstChild->sibling = free3->firstChild;
            parent->firstChild->firstChild = free1->firstChild;
            parent->firstChild->noOfChildren = 2;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            break;
        }
        case 75: { // booleanExpression => TK_NOT TK_OP booleanExpression TK_CL
            ParseTree free1 = parent->firstChild->sibling;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            parent->firstChild->firstChild = free2->firstChild;
            parent->firstChild->sibling = NULL;
            parent->noOfChildren = 1;
            parent->firstChild->noOfChildren = free2->noOfChildren;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            break;
        }
        case 76: { // var => TK_ID
            break;
        }
        case 77: { // var => TK_NUM
            break;
        }
        case 78: { // var => TK_RNUM
            break;
        }
        case 79: { // logicalOp => TK_AND
            break;
        }
        case 80: { // logicalOp => TK_OR
            break;
        }
        case 81: { // relationalOp => TK_LT
            break;
        }
        case 82: { // relationalOp => TK_LE
            break;
        }
        case 83: { // relationalOp => TK_EQ
            break;
        }
        case 84: { // relationalOp => TK_GT
            break;
        }
        case 85: { // relationalOp => TK_GE
            break;
        }
        case 86: { // relationalOp => TK_NE
            break;
        }
        case 87: { // returnStmt => TK_RETURN optionalReturn TK_SEM
            ParseTree free1 = parent->firstChild->sibling;
            ParseTree free2 = free1->sibling;
            parent->noOfChildren = free1->noOfChildren + 1;
            parent->firstChild->sibling = free1->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            break;
        }
        case 88: { // optionalReturn => TK_SQL idList TK_SQR
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            ParseTree free3 = free2->sibling;
            parent->noOfChildren = free2->noOfChildren;
            parent->firstChild = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            calculateMemoryAST(free3);
            break;
        }
        case 89: { // optionalReturn => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        case 90: { // idList => TK_ID more_ids
            ParseTree temp = parent->firstChild->sibling;
            parent->noOfChildren = 1 + temp->noOfChildren;
            parent->firstChild->sibling = temp->firstChild;
            calculateMemoryAST(temp);
            break;
        }
        case 91: { // more_ids => TK_COMMA idList
            ParseTree free1 = parent->firstChild;
            ParseTree free2 = free1->sibling;
            parent->noOfChildren = free2->noOfChildren;
            parent->firstChild = free2->firstChild;
            calculateMemoryAST(free1);
            calculateMemoryAST(free2);
            break;
        }
        case 92: { // more_ids => eps
            parent->noOfChildren = 0;
            calculateMemoryAST(parent->firstChild);
            parent->firstChild = NULL;
            break;
        }
        default:
            break;
    }
}

void traverseAST(ParseTree node) {
    if (node->firstChild == NULL) {
        return;
    }
    ParseTree child = node->firstChild;
    for (int i = 0; i < node->noOfChildren; i++) {
        child->parent = node;
        traverseAST(child);
        child = child->sibling;
    }
}

void createAST(ParseTree root) {
    if (root == NULL) {
        return;
    }
    createASTHelper(root);
    traverseAST(root);
}


void printAST(ParseTree node) {
    if (node == NULL) {
        return;
    }
    printf("%s -> ", node->id < 98 ? node->lexeme : node->nodeSymbol);
    ParseTree pointer = node->firstChild;
    for (int i = 0; i < node->noOfChildren; i++) {
        printf("%s ", pointer->id < 98 ? pointer->lexeme : pointer->nodeSymbol);
        pointer = pointer->sibling;
    }
    printf("\n");
    pointer = node->firstChild;
    for (int i = 0; i < node->noOfChildren; i++) {
        printAST(pointer);
        pointer = pointer->sibling;
    }
}


