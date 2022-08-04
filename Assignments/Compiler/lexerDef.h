#ifndef LEXERDEF_H
#define LEXERDEF_H

#include "hashtable.h"
#include "driver.h"

#define BUFFER_SIZE 10000

typedef enum {
#include "tokens.txt"
} token_name;

typedef struct token {
  token_name name;
  union {
    struct{
      char str[MAX_KEY_LEN];
    }id;
    int num;
    double rnum;
  };
  int line_no;
} TOKEN;

int state;
int retract_count;

hashElement lookup_table[HASH_SIZE];

hashElement lookup_table[HASH_SIZE];

char buffer[BUFFER_SIZE];
char lexeme[MAX_KEY_LEN];

int lexeme_begin;
int forward_ptr;
int num_of_rounds;
int line_no;

extern char terminal_string[NUM_OF_TERMINALS][MAX_SYMBOL_LENGTH];

#endif
