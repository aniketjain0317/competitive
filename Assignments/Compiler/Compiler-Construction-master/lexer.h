/*
GROUP - 14
Created By:   
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#include "lexerDef.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * This enum characterizes the errors into different types.
 * EXCEEDED_20_CHARS -> When identifier exceeds 20 chars
 * EXCEEDED_30_CHARS -> When function identifierr exceeds 30 chars
 * OTHER -> This includes all other lexical errors apart from detecting unknown symbol i.e. unknown pattern
 */
typedef enum {
    EXCEEDED_20_CHARS,
    EXCEEDED_30_CHARS,
    OTHER
} ErrorType;

/**
 * initialize the lexer before using/reusing it.
 */
void initialize();

/**
 * Put the given lexeme, token & line number into the symbol table
 * @param lexeme
 * @param token
 * @param lineNumber
 */
SymbolTableEntry *putInSymbolTable(symbolTable table, char *lexeme, Token token);

/**
 * Add the attribute with given key and value to the provided lexeme.
 * @param lexeme
 * @param key
 * @param value
 */
void addAttribute(symbolTable table, char *lexeme, char *key, void *value);
void addAttributei(symbolTable table, char *lexeme, char *key, int value);
void addAttributeInEntry(SymbolTableEntry* symbolTableEntry, char *key, void *value);
void addAttributeInEntryi(SymbolTableEntry* symbolTableEntry, char *key, int value);

/**
 * Get attributes of the given lexeme from the Symbol Table.
 * @param lexeme
 * @return attributes of given lexeme if exist else return null.
 */
void *getAttributeValue(symbolTable table, char *lexeme, char *key);
int getAttributeValuei(symbolTable table, char *lexeme, char *key);
void *getAttributeValueFromEntry(SymbolTableEntry* symbolTableEntry, char *key);
int getAttributeValueFromEntryi(SymbolTableEntry* symbolTableEntry, char *key);

/**
 * Get the token of the given lexeme if exists from the Symbol Table. If the provided lexeme doesn't exist then
 * a special Token TK_UNDEFINED is returned.
 * @param lexeme
 */
Token getToken(symbolTable table, char *lexeme);

/**
 * retrieves the symbol table entry using the given lexeme.
 * @param lexeme to lookup in symbol table
 * @return pointer to entry in symbol table
 */
SymbolTableEntry *getSymbolTableEntry(symbolTable table, char *lexeme);

/**
 * This is a test function used for testing purpose only.
 * It prints the whole symbol table along with chains.
 */
void printSymbolTable(symbolTable table);


/**
 * This is a test function used for testing purpose only.
 * It prints the attributes in key value form.
 */
void printAttributes(symbolTable table, char *lexeme);

/**
 * A convenience function which is used to insert all keywords into the symbol table initially in order
 * to differentiate them with other identifiers while pattern matching.
 */
void insertKeywordsInSymbolTable();

/**
 * A convenience function used in implementation to create a TokenData from given token.
 * It gets other data from the global variables which keep track of the current state like lexeme read and line number.
 *
 * Note that the TokenData retrieved needs to be released after using with deallocateTokenData
 * @param token
 * @return newly created TokenData
 */
TokenData *createTokenData(Token token);

/**
 * deallocate and frees memory used by tokenData. This needs to be done after you are finished using the tokenData to
 * avoid memory leak
 * @param tokenData TokenData provided by createTokenData which needs to be released
 */
void deallocateTokenData(TokenData *tokenData);

/**
 * This function takes the input from the file pointed to by 'fp'.
 * This file is the source code written in the given language. The function uses efficient technique
 * to bring the fixed sized piece of source code into the memory for processing so as to avoid intensive
 * I/O operations mixed with CPU intensive tasks. The function also maintains the file pointer after
 * every access so that it can get more data into the memory on demand.
 * @param file stream from which to read characters efficiently
 * @return next character in file stream
 */
char getChar(FILE *file, bool toLexBuffer);

/**
 * This functions puts the provided character into the lexBuffer. It also manages the buffer memory and pointers
 * @param c character to put in lexBuffer
 */
void putInLexBuffer(char c);

/**
 * This function, used in conjunction with getChar, simulates putting one character back to the file stream.
 * Internally, it puts the character back to the buffer and adjust the pointers appropriately.
 * This function cannot be called consecutively without getChar in between. Doing so will result in
 * undefined behaviour.
 */
void retractOneChar(bool fromLexBuffer);

/**
 * @param num
 * @return if num is prime or not
 */
bool isPrime(int num);

/**
 * Hash function which returns the hash value from [0, mod-1)
 * @param string to get hash value of
 * @param mod
 * @return hash value
 */
int hashIt(char *string, int mod);

/**
 * This function is called when any lexical error happens. It returns a TokenData with the error lexeme and TK_ERROR as token
 * if it is not an unknown symbol error in which case, it returns NULL
 * @param c the character at which lexical error did happen
 * @param retract flag which tells if the error character is to be retracted.
 * @param errorType a value from ErrorType enum which tells the type of error.
 * @param printReqd flag which tells if this function should print the errors or not.
 * @return
 */
TokenData *reportError(char c, bool retract, ErrorType errorType, bool printReqd);

/**
 * This function reads the input character stream and uses efficient mechanism to recognize lexemes.
 * The function tokenizes the lexeme appropriately and returns all relevant information it collects
 * in this phase (lexical analysis phase) encapsulated as SymbolTableEntry. The function also displays
 * lexical errors appropriately.
 * @param file from which to fetch tokens
 * @return SymbolTableEntry which contains Token, lexeme & attributes (if required)
 */
TokenData *getNextToken(symbolTable table, FILE *file, bool printReqd);

/**
 * This function is an additional plug in to clean the source code by removal of comments.
 * The function takes as input the source code and writes the clean code in the file appropriately.
 * @param filename
 * @param cleanFile
 */
void removeComments(FILE *file);

/**
 * prints all the tokens from the file.
 * @param file
 * @param printReqd tells if errors are to be printed
 */
void printTokens(symbolTable table, FILE *file, bool printReqd);

symbolTable initializeSymbolTable();

void insertKeywordsInSymbolTable(symbolTable table);

#endif //COMPILER_LEXER_H
