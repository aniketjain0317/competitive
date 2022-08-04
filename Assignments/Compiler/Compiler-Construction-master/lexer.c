/*
GROUP - 14
Created By:   
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#include "lexer.h"
#include "symbol.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define BLOCK_SIZE 4096
#define LEX_BUFFER_INITIAL_SIZE 16
#define SYMBOL_TABLE_INITIAL_CAPACITY 30

/**
 * Load threshold is the load after which rehashing is triggered
 */
#define SYMBOL_TABLE_LOAD_THRESHOLD 0.75

/**
 * This buffer is used for efficient file IO
 */
char buf[BLOCK_SIZE];

/**
 * Maintains pointer to position in buffer to read character from
 */
int currBufPtr;

/**
 * As the pattern matching progress, each character is put into lexBuffer to make a lexeme when a pattern
 * matches completely
 *
 * lexBufferPtr points to the position where the next character should go into lexBuffer
 *
 * lexBufferCapacity contains the current capacity of lexBuffer
 *
 * These variables should not be accessed directly and corresponding functions should be used which manages the
 * lexBufferPtr and memory
 */
char *lexBuffer;
int lexBufferPtr;
int lexBufferCapacity;

/**
 * keep track of current line number
 */
int lineNumber;

/**
 * SymbolTable is implemented as a Hash table.
 *
 * keywordsInserted tells if the keywords are inserted into the symbol table.
 * This needs to be done only once so this keeps a check.
 *
 * symbolTableSize contains the number of entries currently in symbol table
 *
 * symbolTableCapacity is the total capacity of the hash table (the array)
 */

bool keywordsInserted = false;

void putInLexBuffer(char c) {
    if (lexBufferCapacity == 0) {
        //initialize
        lexBuffer = (char *) malloc(sizeof(char) * LEX_BUFFER_INITIAL_SIZE);
        memset(lexBuffer, 0, sizeof(char) * LEX_BUFFER_INITIAL_SIZE);
        lexBufferCapacity = LEX_BUFFER_INITIAL_SIZE;
        lexBufferPtr = 0;
    }

    if (lexBufferPtr >= lexBufferCapacity) {
        lexBuffer = (char *) realloc(lexBuffer, sizeof(char) * lexBufferCapacity * 2);
        lexBufferCapacity *= 2;
    }

    lexBuffer[lexBufferPtr++] = c;
}

char getChar(FILE *file, bool toLexBuffer) {
    if (currBufPtr < 0 || currBufPtr >= BLOCK_SIZE) {
        //get next data
        size_t noOfChars = fread(buf, sizeof(char), BLOCK_SIZE / sizeof(char), file);
        if (noOfChars * sizeof(char) != BLOCK_SIZE) {
            buf[noOfChars * sizeof(char)] = EOF;
        }
        currBufPtr = 0;
    }

    if (toLexBuffer) putInLexBuffer(buf[currBufPtr]);
    return buf[currBufPtr++];
}

void retractOneChar(bool fromLexBuffer) {
    currBufPtr--;
    if (fromLexBuffer)
        lexBufferPtr--;
}

bool isPrime(int num) {
    int k, root;

    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    root = (int) sqrt(num);

    for (k = 5; k <= root; k += 6) {
        if (num % k == 0) {
            return false;
        }
    }

    for (k = 7; k <= root; k += 6) {
        if (num % k == 0) {
            return false;
        }
    }

    return true;
}


int hashIt(char *string, int mod) {
    int hash = 5387;
    int d;

    while ((d = *string++) != 0) {
        hash = ((hash << 5) + hash) + d;
    }

    hash = hash % mod;
    return hash > 0 ? hash : -hash;
}

symbolTable initializeSymbolTable() {
    symbolTable table = (symbolTable) malloc(sizeof(ST));
    table->symbolTableSize = 0;
    table->symbolTableCapacity = 0;
    table->table = NULL;
    return table;
}

SymbolTableEntry *putInSymbolTable(symbolTable table, char *lexeme, Token token) {

    if (table->symbolTableSize == 0) {
        //initialize
        table->table = (SymbolTable) malloc(sizeof(SymbolTableEntry *) * SYMBOL_TABLE_INITIAL_CAPACITY);
        table->symbolTableCapacity = SYMBOL_TABLE_INITIAL_CAPACITY;

        for (int i = 0; i < SYMBOL_TABLE_INITIAL_CAPACITY; ++i) {
            table->table[i] = NULL;
        }
    }
    
    SymbolTableEntry* sEntry = getSymbolTableEntry(table, lexeme);
    if (sEntry != NULL)
        return sEntry;

    if (table->symbolTableSize > table->symbolTableCapacity * SYMBOL_TABLE_LOAD_THRESHOLD) {
        /**
         * increase the table capacity and rehash
         * Table capacity will be increased to the prime number which is just greater than
         * twice the current capacity
         */

        int newCapacity = table->symbolTableCapacity * 2;

        newCapacity++;
        while (true) {
            if (isPrime(newCapacity))
                break;
            newCapacity++;
        }

        SymbolTable newTable = malloc(sizeof(SymbolTableEntry *) * newCapacity);
        for (int j = 0; j < newCapacity; ++j) {
            newTable[j] = NULL;
        }

        for (int k = 0; k < table->symbolTableCapacity; ++k) {
            SymbolTableEntry *curr = table->table[k];


            while (curr != NULL) {
                SymbolTableEntry *nextCurr = curr->next;

                //insert this entry into the new table
                int hashValue = hashIt(curr->lexeme, newCapacity);
                if (newTable[hashValue] == NULL) {
                    newTable[hashValue] = curr;
                } else {
                    SymbolTableEntry *newTableCurr = newTable[hashValue];
                    while (newTableCurr->next != NULL) {
                        newTableCurr = newTableCurr->next;
                    }
                    newTableCurr->next = curr;
                }
                curr->next = NULL;
                curr = nextCurr;
            }
        }

        //deallocate previous table
        free(table->table);

        table->table = newTable;
        table->symbolTableCapacity = newCapacity;
    }

    SymbolTableEntry *symbolTableEntry = (SymbolTableEntry *) malloc(sizeof(SymbolTableEntry));
    symbolTableEntry->lexeme = lexeme;
    symbolTableEntry->token = token;
    symbolTableEntry->attributes = NULL;
    symbolTableEntry->next = NULL;

    int hashValue = hashIt(symbolTableEntry->lexeme, table->symbolTableCapacity);
    if (table->table[hashValue] == NULL) {
        table->table[hashValue] = symbolTableEntry;
    } else {
        SymbolTableEntry *curr = table->table[hashValue];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = symbolTableEntry;
    }
    symbolTableEntry->next = NULL;
    table->symbolTableSize++;

    return symbolTableEntry;
}

SymbolTableEntry *getSymbolTableEntry(symbolTable table, char *lexeme) {
    SymbolTableEntry *curr = table->table[hashIt(lexeme, table->symbolTableCapacity)];
    while (curr != NULL) {
        if (strcmp(lexeme, curr->lexeme) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void addAttributei(symbolTable table, char *lexeme, char *key, int value) {
    addAttribute(table, lexeme, key, (void*) value);
}

void addAttribute(symbolTable table, char *lexeme, char *key, void *value) {
    SymbolTableEntry *symbolTableEntry = getSymbolTableEntry(table, lexeme);
    addAttributeInEntry(symbolTableEntry, key, value);
}

void addAttributeInEntryi(SymbolTableEntry* symbolTableEntry, char *key, int value) {
    addAttributeInEntry(symbolTableEntry, key, (void*) value);
}

void addAttributeInEntry(SymbolTableEntry* symbolTableEntry, char *key, void *value) {
    if (symbolTableEntry != NULL) {
        Attribute *attribute = (Attribute *) malloc(sizeof(Attribute));
        attribute->key = key;
        attribute->value = value;
        attribute->next = NULL;


        if (symbolTableEntry->attributes == NULL) {
            symbolTableEntry->attributes = attribute;
        } else {
            Attribute *currAttr = symbolTableEntry->attributes;
            while (currAttr->next != NULL) {
                if (strcmp(currAttr->key, key) == 0) {
                    currAttr->value = value;
                    return;
                }
                currAttr = currAttr->next;
            }
            if (strcmp(currAttr->key, key) == 0) {
                currAttr->value = value;
                return;
            }
            currAttr->next = attribute;
        }

        symbolTableEntry->noOfAttributes++;

    }
}

void *getAttributeValue(symbolTable table, char *lexeme, char *key) {
    SymbolTableEntry *symbolTableEntry = getSymbolTableEntry(table, lexeme);
    return getAttributeValueFromEntry(symbolTableEntry, key);
}

int getAttributeValuei(symbolTable table, char *lexeme, char *key) {
    return (int) getAttributeValue(table, lexeme, key);
}

void *getAttributeValueFromEntry(SymbolTableEntry* symbolTableEntry, char *key) {
    if (symbolTableEntry != NULL) {
        Attribute *curr = symbolTableEntry->attributes;
        while (curr != NULL) {
            if (strcmp(curr->key, key) == 0) {
                return curr->value;
            }
            curr = curr->next;
        }
    } else return NULL;
    return NULL;
}

int getAttributeValueFromEntryi(SymbolTableEntry* symbolTableEntry, char *key) {
    return (int) getAttributeValueFromEntry(symbolTableEntry, key);
}

void printSymbolTable(symbolTable table) {
    printf("\n");
    printf("%p\n", table);
    for (int i = 0; i < table->symbolTableCapacity; ++i) {
        if (table->table[i] == NULL) {
            printf("NULL\n");
        } else {
            SymbolTableEntry *curr = table->table[i];
            while (curr->next != NULL) {
                printf("%s : ", curr->lexeme);
                Attribute *temp = curr->attributes;
                while (temp != NULL) {
                    if (strcmp(temp->key, "dataType") == 0) {
                        printf("%s %s", temp->key, TermSymbol[*(int *) temp->value]);
                    } else if (strcmp(temp->key, "funcScope") == 0 || strcmp(temp->key, "recordScope") == 0 ||
                               strcmp(temp->key, "inputParScope") == 0 || strcmp(temp->key, "outputParScope") == 0) {
                        printSymbolTable(temp->value);
                    } else {
                        printf("%s %p", temp->key, temp->value);
                    }
                    temp = temp->next;
                }
                printf(" ---> ");
                curr = curr->next;
            }
            printf("%s : ", curr->lexeme);
            Attribute *temp = curr->attributes;
            while (temp != NULL) {
                if (strcmp(temp->key, "dataType") == 0) {
                    printf("%s %s", temp->key, TermSymbol[*(int *) temp->value]);
                } else if (strcmp(temp->key, "funcScope") == 0 || strcmp(temp->key, "recordScope") == 0 ||
                           strcmp(temp->key, "inputParScope") == 0 || strcmp(temp->key, "outputParScope") == 0) {
                    printf("%s %p", temp->key, temp->value);
                    printSymbolTable(temp->value);
                } else {
                    printf("%s %p", temp->key, temp->value);
                }
                temp = temp->next;
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("End of current scope\n");
}

Token getToken(symbolTable table, char *lexeme) {
    SymbolTableEntry *symbolTableEntry = getSymbolTableEntry(table, lexeme);
    if (symbolTableEntry != NULL) {
        return symbolTableEntry->token;
    } else return TK_UNDEFINED;
}

TokenData *createTokenData(Token token) {

    putInLexBuffer('\0'); //null terminate string
    TokenData *tokenData = (TokenData *) malloc(sizeof(TokenData));
    tokenData->token = token;
    tokenData->lexeme = malloc(sizeof(char) * strlen(lexBuffer));
    strcpy(tokenData->lexeme, lexBuffer);
    tokenData->lineNumber = lineNumber;
    tokenData->symbolTableEntry = NULL;

    memset(lexBuffer, 0, sizeof(char) * lexBufferCapacity);
    lexBufferPtr = 0;

    return tokenData;
}

TokenData *reportError(char c, bool retract, ErrorType errorType, bool printReqd) {
    if (lexBufferPtr != 1) {
        if (retract)
            retractOneChar(true);
        TokenData *tokenData = createTokenData(TK_ERROR);
        if (errorType == EXCEEDED_20_CHARS) {
            if (printReqd)
                printf("Line %d: Identifier is longer than the prescribed length of 20 characters\n", lineNumber);
        } else if (errorType == EXCEEDED_30_CHARS) {
            if (printReqd)
                printf("Line %d: Function Identifier is longer than the prescribed length of 30 characters\n",
                       lineNumber);
        } else if (errorType == OTHER) {
            if (printReqd)
                printf("Line %d: Unknown Pattern %s\n", lineNumber, tokenData->lexeme);
        }
        return tokenData;
    }
    lexBufferPtr = 0;
    if (printReqd)
        printf("Line %d: Unknown Symbol %c\n", lineNumber, c);
    return NULL;
}

void insertKeywordsInSymbolTable(symbolTable table) {
    putInSymbolTable(table, "with", TK_WITH);
    putInSymbolTable(table, "parameters", TK_PARAMETERS);
    putInSymbolTable(table, "end", TK_END);
    putInSymbolTable(table, "while", TK_WHILE);
    putInSymbolTable(table, "type", TK_TYPE);
    putInSymbolTable(table, "_main", TK_MAIN);
    putInSymbolTable(table, "global", TK_GLOBAL);
    putInSymbolTable(table, "parameter", TK_PARAMETER);
    putInSymbolTable(table, "list", TK_LIST);
    putInSymbolTable(table, "input", TK_INPUT);
    putInSymbolTable(table, "output", TK_OUTPUT);
    putInSymbolTable(table, "int", TK_INT);
    putInSymbolTable(table, "real", TK_REAL);
    putInSymbolTable(table, "endwhile", TK_ENDWHILE);
    putInSymbolTable(table, "if", TK_IF);
    putInSymbolTable(table, "then", TK_THEN);
    putInSymbolTable(table, "endif", TK_ENDIF);
    putInSymbolTable(table, "read", TK_READ);
    putInSymbolTable(table, "write", TK_WRITE);
    putInSymbolTable(table, "return", TK_RETURN);
    putInSymbolTable(table, "call", TK_CALL);
    putInSymbolTable(table, "record", TK_RECORD);
    putInSymbolTable(table, "endrecord", TK_ENDRECORD);
    putInSymbolTable(table, "else", TK_ELSE);
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

TokenData *getNextToken(symbolTable table, FILE *file, bool printReqd) {
    if (!keywordsInserted) {
        insertKeywordsInSymbolTable(table);
        keywordsInserted = true;
    }

    int currState = 1; // start state
    TokenData *error;

    while (true) {
        char readChar = getChar(file, false);
        if (readChar == '\n') { //increase line number
            lineNumber++;
        } else if (isspace(readChar)) { //ignore spaces
            continue;
        } else if (readChar == '%') { //ignore comments
            while (readChar != '\n')
                readChar = getChar(file, false);
            lineNumber++;
        } else {
            if (readChar == EOF)
                return NULL;
            retractOneChar(false);
            break;
        }
    }

    while (true) {
        char readChar = getChar(file, true);

        switch (currState) {
            case 1:
                switch (readChar) {
                    case '<':
                        currState = 2;
                        break;
                    case '>':
                        currState = 8;
                        break;
                    case '=':
                        currState = 11;
                        break;
                    case '!':
                        currState = 13;
                        break;
                    case '~':
                        return createTokenData(TK_NOT);
                    case '@':
                        currState = 16;
                        break;
                    case '&':
                        currState = 19;
                        break;
                    case '+':
                        return createTokenData(TK_PLUS);
                    case '-':
                        return createTokenData(TK_MINUS);
                    case '*':
                        return createTokenData(TK_MUL);
                    case '/':
                        return createTokenData(TK_DIV);
                    case '(':
                        return createTokenData(TK_OP);
                    case ')':
                        return createTokenData(TK_CL);
                    case '[':
                        return createTokenData(TK_SQL);
                    case ']':
                        return createTokenData(TK_SQR);
                    case ',':
                        return createTokenData(TK_COMMA);
                    case ';':
                        return createTokenData(TK_SEM);
                    case ':':
                        return createTokenData(TK_COLON);
                    case '.':
                        return createTokenData(TK_DOT);
                    case '%':
                        // comments already handled
                        break;
                    case '#':
                        currState = 35;
                        break;
                    default:
                        if (isdigit(readChar)) {
                            currState = 38;
                        } else if (readChar >= 'b' && readChar <= 'd') {
                            currState = 43;
                        } else if (readChar == 'a' || (readChar >= 'e' && readChar <= 'z')) {
                            currState = 47;
                        } else if (readChar == '_') {
                            currState = 49;
                        } else {
                            error = reportError(readChar, true, OTHER, printReqd);
                            return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                        }
                }
                break;
            case 2:
                switch (readChar) {
                    case '-':
                        currState = 3;
                        break;
                    case '=':
                        return createTokenData(TK_LE);
                    default:
                        retractOneChar(true);
                        return createTokenData(TK_LT);
                }
                break;
            case 3:
                switch (readChar) {
                    case '-':
                        currState = 4;
                        break;
                    default:
                        error = reportError(readChar, true, OTHER, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
                break;
            case 4:
                switch (readChar) {
                    case '-':
                        return createTokenData(TK_ASSIGNOP);
                    default:
                        error = reportError(readChar, true, OTHER, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
            case 8:
                switch (readChar) {
                    case '=':
                        return createTokenData(TK_GE);
                    default:
                        retractOneChar(true);
                        return createTokenData(TK_GT);
                }
            case 11:
                switch (readChar) {
                    case '=':
                        return createTokenData(TK_EQ);
                    default:
                        error = reportError(readChar, true, OTHER, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
            case 13:
                switch (readChar) {
                    case '=':
                        return createTokenData(TK_NE);
                    default:
                        error = reportError(readChar, true, OTHER, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
            case 16:
                switch (readChar) {
                    case '@':
                        currState = 17;
                        break;
                    default:
                        error = reportError(readChar, true, OTHER, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
                break;
            case 19:
                switch (readChar) {
                    case '&':
                        currState = 20;
                        break;
                    default:
                        error = reportError(readChar, true, OTHER, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
                break;
            case 17:
                switch (readChar) {
                    case '@':
                        return createTokenData(TK_OR);
                    default:
                        error = reportError(readChar, true, OTHER, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
            case 20:
                switch (readChar) {
                    case '&':
                        return createTokenData(TK_AND);
                    default:
                        error = reportError(readChar, true, OTHER, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
            case 35:
                if (islower(readChar)) {
                    currState = 36;
                } else {
                    error = reportError(readChar, true, OTHER, printReqd);
                    return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
                break;
            case 36:
                if (!islower(readChar)) {
                    retractOneChar(true);
                    return createTokenData(TK_RECORDID);
                }
                break;
            case 38:
                if (isdigit(readChar)) {
                    currState = 38;
                } else if (readChar == '.') {
                    currState = 39;
                } else {
                    retractOneChar(true);
                    return createTokenData(TK_NUM);
                }
                break;
            case 39:
                if (isdigit(readChar)) {
                    currState = 40;
                } else {
                    error = reportError(readChar, true, OTHER, printReqd);
                    return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
                break;
            case 40:
                if (isdigit(readChar)) {
                    return createTokenData(TK_RNUM);
                } else {
                    error = reportError(readChar, true, OTHER, printReqd);
                    return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
            case 43:
                if (readChar >= '2' && readChar <= '7') {
                    currState = 44;
                } else if (islower(readChar)) {
                    currState = 47;
                } else {
                    retractOneChar(true);
                    TokenData *tkData = createTokenData(TK_FIELDID);
                    Token tokenType = getToken(table, tkData->lexeme);

                    if (tokenType == TK_UNDEFINED) {
                        //entry doesn't exist in symbol table; Therefore it is an identifier which is not seen before
                        putInSymbolTable(table, tkData->lexeme, tkData->token);
                    } else if (tokenType != TK_FIELDID) {
                        //keyword
                        tkData->token = tokenType;
                    }
                    return tkData;
                }
                break;
            case 44:
                if (readChar >= 'b' && readChar <= 'd') {
                    currState = 44;
                } else if (readChar >= '2' && readChar <= '7') {
                    currState = 45;
                } else {
                    retractOneChar(true);
                    if (lexBufferPtr < 2 || lexBufferPtr > 20) {
                        error = reportError(readChar, false, EXCEEDED_20_CHARS, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                    }
                    TokenData *tkData = createTokenData(TK_ID);
                    putInSymbolTable(table, tkData->lexeme, tkData->token);
                    return tkData;
                }
                break;
            case 45:
                if (readChar >= '2' && readChar <= '7') {
                    currState = 45;
                } else {
                    retractOneChar(true);
                    if (lexBufferPtr < 2 || lexBufferPtr > 20) {
                        error = reportError(readChar, false, EXCEEDED_20_CHARS, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                    }
                    TokenData *tkData = createTokenData(TK_ID);
                    putInSymbolTable(table, tkData->lexeme, tkData->token);
                    return tkData;
                }
                break;
            case 47:
                if (islower(readChar)) {
                    currState = 47;
                } else {
                    retractOneChar(true);
                    TokenData *tkData = createTokenData(TK_FIELDID);
                    Token tokenType = getToken(table, tkData->lexeme);

                    if (tokenType == TK_UNDEFINED) {
                        //entry doesn't exist in symbol table; Therefore it is an identifier which is not seen before
                        putInSymbolTable(table, tkData->lexeme, tkData->token);
                    } else if (tokenType != TK_FIELDID) {
                        //keyword
                        tkData->token = tokenType;
                    }
                    return tkData;
                }
                break;
            case 49:
                if (islower(readChar) || isupper(readChar)) {
                    currState = 50;
                } else {
                    error = reportError(readChar, true, OTHER, printReqd);
                    return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                }
                break;
            case 50:
                if (islower(readChar) || isupper(readChar)) {
                    currState = 50;
                } else if (isdigit(readChar)) {
                    currState = 52;
                } else {
                    retractOneChar(true);
                    if (lexBufferPtr > 30) {
                        error = reportError(readChar, false, EXCEEDED_30_CHARS, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                    }
                    TokenData *tkData = createTokenData(TK_FUNID);
                    if (strcmp(tkData->lexeme, "_main") == 0) {
                        tkData->token = TK_MAIN;
                    }
                    return tkData;
                }
                break;
            case 52:
                if (isdigit(readChar)) {
                    currState = 52;
                } else {
                    retractOneChar(true);
                    if (lexBufferPtr > 30) {
                        error = reportError(readChar, false, EXCEEDED_30_CHARS, printReqd);
                        return (error == NULL) ? getNextToken(table, file, printReqd) : error;
                    }
                    TokenData *tkData = createTokenData(TK_FUNID);
                    return tkData;
                }
                break;
        }

    }

}

#pragma clang diagnostic pop

void removeComments(FILE *file) {
    currBufPtr = -1;

    char currChar = getChar(file, false);

    while (currChar != EOF) {
        if (currChar == '%') {
            while (getChar(file, false) != '\n');
            printf("\n");
            currChar = getChar(file, false);
            if (currChar == '%') {
                continue;
            }
        }
        printf("%c", currChar);
        currChar = getChar(file, false);

        if (currChar == '\n') {
            printf("\n");
            currChar = getChar(file, false);
        }
    }

    currBufPtr = -1;
}

void initialize() {
    currBufPtr = -1;
    lexBufferPtr = -1;
    lineNumber = 1;
    lexBufferCapacity = 0;
}

void deallocateTokenData(TokenData *tokenData) {
    free(tokenData->lexeme);
    free(tokenData);
}

void printTokens(symbolTable table, FILE *file, bool printReqd) {
    TokenData *tokenData = getNextToken(table, file, printReqd);

    while (tokenData != NULL) {
        printf("Line: %3d, Token = %s, Lexeme: %s\n", tokenData->lineNumber, TermSymbol[tokenData->token],
               tokenData->lexeme);
        deallocateTokenData(tokenData);
        tokenData = getNextToken(table, file, printReqd);
    }
}
