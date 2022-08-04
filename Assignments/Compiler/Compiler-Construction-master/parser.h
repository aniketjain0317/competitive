/*
GROUP - 14
Created By:   
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include "parserDef.h"

/**
 * This function creates a new list of integers
 * @return List of Integers
 */
List newList();

/**
 * This function inserts a new integer at the end of the list
 * @param Pointer to the list
 * @param integer to be inserted
 * @return Pointer to the list after inserting the integer
 */
List insertAtEnd(List l,int i);

/**
 * This function inserts a new integer at the front of the list
 * @param Pointer to the list
 * @param integer to be inserted
 * @return Pointer to the list after inserting the integer
 */
List insertAtFront(List l,int val);

/**
 * This function tells whether the specified token is present in the list or not
 * @param Pointer to the list
 * @param The token whose status is to be determined
 * @return 1->element is present or 0->element is not present 
 */
int contains(List list,int token);

/**
 * Fills the grammar productions in an array
 * @param File pointer (fp)
 * @param hash table mapping strings (terminals & non-terminals) to int (hashtable) 
 */
void getRules(FILE *fp,hashtableInt* hashtable);

/**
 * Calculates first of a non-terminal
 * @param hash table mapping non-terminal to line numbers (table1)
 * @param hash table for storing firsts (table2)
 * @param line number of rule in grammar.txt (i)
 */
void first(hashtable_t *table1, hashtable_t *table2, int i);

/**
 * Calculates first for terminals and non-terminals by calling the above function
 * @param hash table mapping non-terminal to line numbers (table1)
 * @return hashtable storing firsts
 */
hashtable_t *computeFirst(hashtable_t *table1);

/**
 * Generates the Parse Table
 * @param hash table which stores firsts (first)
 * @param hash table which stores follow (follow)
 * @param hash table mapping strings (terminals & non-terminals) to int (hash_t)
 */
void generateParseTable(hashtable_t *first, hashtable_t *follow);

/**
 * Fills the parse table with synch as required
 * @param hash table which stores follow (follow)
 */
void fillParseTableWithSynchs(hashtable_t *follow);

/**
 * Creates stack to be used in parsing
 * @return stack
 */
Stack createStack();

/**
 * Pushes an element onto the stack
 * @param stack (s)
 * @param node to be pushed onto stack (node) 
 */
void push(Stack s, ParseTree node);

/**
 * Returns the top of the stack
 * @param stack (s)
 * @return top of the stack
 */
ParseTree top(Stack s);

/**
 * Pops the top of the stack
 * @param stack (s)
 * @return the top of the stack and also pops it from the stack
 */
tree_pointer pop(Stack s);

/**
 * Uses pop and initializes the lexeme of the element popped
 * @param stack (s)
 * @param lexeme to be initialized (str)
 * @param line number
 * @param token name(token)
 */
void pophelper(Stack s, char *str,int line,char* token);

/**
 * Allocates the parse tree node and initializes it appropriately
 * @param nodeSymbol (str)
 * @param parent (par)
 * @param token number (id)
 * @return the created Parse Tree node
 */
ParseTree createParseTreeNode(char *str, ParseTree par, int id);

/**
 * Adds the element to stack and tree simultaneously
 * @param stack (s)
 * @param RHS of non-terminal popped to be added to stack and parse tree (temp)
 * @param previous node in parse tree (prev)
 * @param parent (par)
 * @param flag for proper connection of nodes in parse tree (flag) 
 */
void addNodeToStackAndTree(Stack s, rule* temp, ParseTree prev, ParseTree par, int flag);

/**
 * Creates the parse tree for the input source code
 * @param file pointer of input source code (fp)
 * @param hash table mapping strings (terminals & non-terminals) to int (table)
 * @return the root of the parse tree 
 */
ParseTree generateParseTree(symbolTable tab,FILE *fp, hashtableInt *table,hashtable_t* first,bool printReqd);

/**
 * Creates the hashtable with key as a string and value as Linked list of integers
 * @param size of the hashtable
 * @return pointer to the hashtable
 */
hashtable_t *createHashtable(int size);

/**
 * Hash function which returns the hash value from [0, size of hashtable -1)
 * @param string to get hash value of
 * @param pointer to hashtable
 * @return hash value
 */
long int hash(hashtable_t *hashtable, char *key);

/**
 * This function creates the pointer to a hashtable entry with given key and value
 * @param string -> key
 * @param linked list of integers -> value
 * @return pointer to the hashtable entry
 */
entry_t *getPair( char *key, List value);

/**
 * This function puts an entry for the given key and its value in the hashtable
 * @param pointer to hashtable
 * @param linked list of integers -> value
 * @param string -> key
 */
void hash_put( hashtable_t *hashtable, char *key, List value );

/**
 * This function returns the value of the key in the hashtable
 * @param pointer to hashtable
 * @param string -> key
 * @return linked list of integers -> value
 */
List hash_get( hashtable_t *hashtable, char *key );

/**
 * Creates the hashtable with key as a string and value as integer
 * @param size of the hashtable
 * @return pointer to the hashtable
 */
hashtableInt *createHashtableInt(int size);

/**
 * Hash function which returns the hash value from [0, size of hashtable -1)
 * @param string to get hash value of
 * @param pointer to hashtable
 * @return hash value
 */
long int hashInt(hashtableInt *hashtable,char *key);

/**
 * This function creates the pointer to a hashtable entry with given key and value
 * @param string -> key
 * @param integer -> value
 * @return pointer to the hashtable entry
 */
entryInt *getPairInt(char *key,int value);

/**
 * This function puts an entry for the given key and its value in the hashtable
 * @param pointer to hashtable
 * @param integer -> value
 * @param string -> key
 */
void hash_putInt( hashtableInt *hashtable, char *key, int value ) ;

/**
 * This function returns the value of the key in the hashtable
 * @param pointer to hashtable
 * @param string -> key
 * @return integer -> value
 */
int hash_getInt( hashtableInt *hashtable, char *key ) ;

/**
 * This function populates the provided hashtable with mappings of grammar symbols to an integer
 * @param pointer to hashtable
 */
void populateWithSymbols(hashtableInt *h);

/**
 * @param pointer to table1
 * @param pointer to table2
 * This function populates the provided hashtables as follows ->
 * 1) table1 contains the mappings of non-terminals to linked list of line numbers on which they appear on lhs of rule 
 * 2) table2 contains the mappings of non-terminals to linked list of mapping of symbols which are present on the
 *    right side of that non-terminal in a rule followed by lhs of the rule and repeated for all rules in which that 
 *    particular non-terminal itself appears on the rhs
 */ 
void populateHashTables(hashtable_t* table1,hashtable_t* table2);

/**
 * This function is used to check if the symbol is a terminal or not
 * @param id of the symbol
 * @return 1->terminal or 0->non-terminal
 */
int checkIfTerminal(int id);

/**
 * This function computes the first set of a given string
 * @param pointer to a hashtable which stores the first set in a linked list of integers
 * @param string given as a linked list of integers
 */
List firstOfAlpha(hashtable_t* first,element head);

/**
 * This function serves as a helper function to compute the follow sets of the provided non-terminal.
 * @param pointer to hashtable which contains the entries to the right and the entry on the lhs of rule in which non-terminal occurs on rhs   
 * @param pointer to hashtable which stores the first sets of the grammar symbol
 * @param pointer to hashtable which will store the follow sets of the non-terminals
 * @param non-terminal whose follow is to computed
 * @param pointer to hashtable which contains the mappings of grammar symbols to integers
 */
void computeFollowHelp(hashtable_t* table,hashtable_t* first,hashtable_t* follow,char* nonTerminal,hashtableInt* hash_t);

/**
 * This function computes the follow sets of the provided grammar.
 * @param pointer to hashtable which contains the entries to the right and the entry on the lhs of rule in which non-terminal occurs on rhs   
 * @param pointer to hashtable which stores the first sets of the grammar symbol
 * @param pointer to hashtable which will store the follow sets of the non-terminals
 * @param pointer to hashtable which contains the mappings of grammar symbols to integers
 */
void computeFollow(hashtable_t* table,hashtable_t* first,hashtable_t* follow,hashtableInt* hash_t);

/**
 * This function serves as a helper function to print the parse tree generated
 * @param current node
 * @param file pointer  of the output file
 */
void printParseTreeHelp(ParseTree curr,bool memoryCalc);

/**
 * This function prints the parse tree generated by the inorder traversal
 * @param root of the parse tree
 * @param file pointer  of the output file
 * @param flag to indicate whether we need to print the tree or not
 */
void printParseTree(ParseTree root,bool flag,bool memoryCalc);

/**
 * This function invokes the lexer and parser,reports all lexical and syntax errors and prints the parse tree.
 * @param name of the grammar file
 * @param name of the testcase file
 * @param name of the output file
 * @param boolean value to indicate wehther we need to print errors or not
 */
ParseTree printParserLexer(symbolTable table,const char *grammar,const char *testcase,bool printReqd,bool memoryCalc);

void initializeVariablesParser();

long int getMemory();

long int getParseNodes();


#endif
