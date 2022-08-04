#ifndef LEXER_H
#define LEXER_H

#include "lexerDef.h"
#include <stdio.h>

void populate_buffer(FILE *fp);

void populate_lookup_table();

void populate_terminal_string();

TOKEN get_next_token(FILE *fp);

char get_char(FILE *fp);

TOKEN get_token();

void retract(int num);

void lexer_init(FILE *source);

token_name search_lookup_table(char *lexeme);

void tokenize_source_file(FILE *source);

void remove_comments(FILE *source, char *no_comment_file);

#endif
