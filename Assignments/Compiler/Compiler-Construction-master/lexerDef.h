/*
GROUP - 14
Created By:   
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#ifndef COMPILER_LEXERDEF_H
#define COMPILER_LEXERDEF_H

/**
 * All default tokens with 3 custom tokens
 * The custom tokens are
 * TK_EPS -> epsilon
 * TK_UNDEFINED -> If no entry is found the symbol table for corresponding search, this token is returned
 * TK_ERROR -> If any lexical error happens
 */
typedef enum {
    TK_ASSIGNOP,
    TK_COMMENT,
    TK_FIELDID,
    TK_ID,
    TK_NUM,
    TK_RNUM,
    TK_FUNID,
    TK_RECORDID,
    TK_WITH,
    TK_PARAMETERS,
    TK_END,
    TK_WHILE,
    TK_INT,
    TK_REAL,
    TK_TYPE,
    TK_MAIN,
    TK_GLOBAL,
    TK_PARAMETER,
    TK_LIST,
    TK_SQL,
    TK_SQR,
    TK_INPUT,
    TK_OUTPUT,
    TK_SEM,
    TK_COLON,
    TK_DOT,
    TK_COMMA,
    TK_ENDWHILE,
    TK_OP,
    TK_CL,
    TK_IF,
    TK_THEN,
    TK_ENDIF,
    TK_READ,
    TK_WRITE,
    TK_RETURN,
    TK_PLUS,
    TK_MINUS,
    TK_MUL,
    TK_DIV,
    TK_CALL,
    TK_RECORD,
    TK_ENDRECORD,
    TK_ELSE,
    TK_AND,
    TK_OR,
    TK_NOT,
    TK_LT,
    TK_LE,
    TK_EQ,
    TK_GT,
    TK_GE,
    TK_NE,
    TK_EPS,
    TK_UNDEFINED,
    TK_ERROR,
    TK_NULL,
    TK_BOOLEAN
} Token;

/**
 * Symbol table entry contains a linked list of Attributes which contains key value pair
 */
typedef struct Attribute{
    char* key;
    void* value;
    struct Attribute* next;
} Attribute;

/**
 * A Symbol table entry.
 * Contains lexeme, token and a set of attributes
 */
typedef struct SymbolTableEntry {
    char *lexeme;
    Token token;
    Attribute* attributes;// Linked List
    int noOfAttributes;
    struct SymbolTableEntry* next;
} SymbolTableEntry;

/**
 * TokenData is returned on a call to getNextToken
 * It contains the token, lexeme, line number and a pointer to symbol table entry if required (for identifiers)
 */
typedef struct {
    Token token;
    char* lexeme;
    int lineNumber;
    SymbolTableEntry* symbolTableEntry;
} TokenData;

/**
 * SymbolTable is a hashtable which contains pointer to SymbolTableEntry
 */

typedef SymbolTableEntry** SymbolTable;

typedef struct symbolTable{
    SymbolTable table;
    int symbolTableCapacity;
    int symbolTableSize;
}ST;

typedef ST* symbolTable;

#endif //COMPILER_LEXERDEF_H
