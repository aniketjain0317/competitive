/*
GROUP - 14
Created By:   
1) Tarun Kumar (2016A7PS0005P)
2) Varun Gupta (2016A7PS0087P)
3) Avichal Jain (2016A7PS0046P)
4) Vaibhav Maheshwari (2016A7PS0081P)
*/

#ifndef COMPILER_PARSERDEF_H
#define COMPILER_PARSERDEF_H

#include"lexer.h"

#define NO_OF_RULES 92
#define NO_OF_TERMINALS 54
#define NO_OF_NON_TERMINALS 51
#define DOLLAR_ID 99
#define EOS_ID 98


// Linked list of Integers
typedef struct node {
    int data;
    struct node *next;
} Node;

typedef Node rule;
typedef Node *element;

typedef struct {
    element head;
    element tail;
    int size;
} list;

typedef list ruleList;
typedef list *List;


// Hashtable containing key,value pairs with key as string and value as Linked List of Integers
struct entry_s {
    char *key;
    List value;
    struct entry_s *next;
};

struct hashtable_s {
    int size;
    struct entry_s **table;
};

typedef struct hashtable_s hashtable_t;
typedef struct entry_s entry_t;


// Hashtable containing key,value pairs with key as string and value as Integer
struct entry_sInt {
    char *key;
    int value;
    struct entry_sInt *next;
};

struct hashtable_sInt {
    int size;
    struct entry_sInt **table;
};

typedef struct hashtable_sInt hashtableInt;

typedef struct hashlist{
    hashtableInt* head;
    int iterativeScope;
    struct hashlist* next;
}hashList;

typedef struct entry_sInt entryInt;


// Parse tree is composed of various tree nodes with the following structure
struct tree_node {
    char *lexeme;
    struct tree_node *parent;
    int id;
    char *tokenName;
    int lineno;
    char *nodeSymbol;
    struct tree_node *firstChild;
    int noOfChildren;
    struct tree_node *sibling;
    int ruleno;
    struct tree_node *inh;
    struct tree_node *syn;
    int dataType;
};

typedef struct tree_node *ParseTree;


// Stack of tree nodes
struct tree_pointer {
    ParseTree tnode;
    struct tree_pointer *next;
};

typedef struct tree_node ParseTreeNode;
typedef struct tree_pointer *tree_pointer;

typedef struct{
  tree_pointer head;
}linkedList;
typedef linkedList* LinkedList;

struct stack_entry {
    int size;
    tree_pointer list;
};
typedef struct stack_entry *Stack;


/*************GLOBAL DECLARATIONS***************/
ruleList *rules[NO_OF_RULES + 1];
int parse_table[NO_OF_NON_TERMINALS][NO_OF_TERMINALS];
extern bool hasErrors;

#endif

