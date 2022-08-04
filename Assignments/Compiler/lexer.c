#include "driver.h"
#include "hashtable.h"
#include "lexerDef.h"
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief search string in lookup table to check if it's keyword or identifier
 *
 * @param lexeme string to search for
 * @return token_name - ID or hash_table entry
 */
token_name search_lookup_table(char *lexeme) {
  int num = search_hash_table(lookup_table, lexeme);
  if (KEY_NOT_FOUND == num) {
    return ID;
  } else {
    return num;
  }
}

/**
 * @brief Get the token object recognized by the DFA
 *
 * @return TOKEN - line_no , rnumerated value, name/int_value/real_value
 */

TOKEN get_token() {

  if (lexeme_begin == BUFFER_SIZE) {
    lexeme_begin = 0;
  }
  TOKEN tkn;

  tkn.line_no = line_no;
  int lex_size = forward_ptr - lexeme_begin;
  if (lex_size < 0) {
    lex_size += num_of_rounds * BUFFER_SIZE;
    num_of_rounds = 0;
  }
  int last_index = (lex_size < MAX_LEXEME_LEN) ? lex_size : MAX_LEXEME_LEN - 1;
  lexeme[last_index] = '\0';

  if (2 == state) {
    if (lex_size > 20) {
      tkn.name = LEX_ERROR;
      strncpy(tkn.id.str, lexeme, MAX_LEXEME_LEN);
      return tkn;
    }

    token_name name = search_lookup_table(lexeme);
    tkn.name = name;
    strncpy(tkn.id.str, lexeme, MAX_LEXEME_LEN);
    return tkn;
  }

  if (4 == state || 6 == state) {
    tkn.name = NUM;
    tkn.num = atoi(lexeme);
  }

  if (8 == state || 12 == state) {
    tkn.name = RNUM;
    tkn.rnum = atof(lexeme);
  }
  return tkn;
}

/**
 * @brief retract and push back a character to stream
 *
 * @param num_of_char - number of chracters to retract
 */

void retract(int num_of_char) {
  forward_ptr -= num_of_char;
  if (forward_ptr < 0) {
    forward_ptr += BUFFER_SIZE;
  }
  retract_count += num_of_char;
}

/**
 * @brief inserts the entries for keywords in the lookup_table hashtable
 *
 */

void populate_lookup_table() {
  insertHashTable(lookup_table, "integer", INTEGER);
  insertHashTable(lookup_table, "real", REAL);
  insertHashTable(lookup_table, "boolean", BOOLEAN);
  insertHashTable(lookup_table, "of", OF);
  insertHashTable(lookup_table, "array", ARRAY);
  insertHashTable(lookup_table, "start", START);
  insertHashTable(lookup_table, "end", END);
  insertHashTable(lookup_table, "declare", DECLARE);
  insertHashTable(lookup_table, "module", MODULE);
  insertHashTable(lookup_table, "driver", DRIVER);
  insertHashTable(lookup_table, "program", PROGRAM);
  insertHashTable(lookup_table, "get_value", GET_VALUE);
  insertHashTable(lookup_table, "print", PRINT);
  insertHashTable(lookup_table, "use", USE);
  insertHashTable(lookup_table, "with", WITH);
  insertHashTable(lookup_table, "parameters", PARAMETERS);
  insertHashTable(lookup_table, "true", TRUE);
  insertHashTable(lookup_table, "false", FALSE);
  insertHashTable(lookup_table, "takes", TAKES);
  insertHashTable(lookup_table, "input", INPUT);
  insertHashTable(lookup_table, "returns", RETURNS);
  insertHashTable(lookup_table, "AND", AND);
  insertHashTable(lookup_table, "OR", OR);
  insertHashTable(lookup_table, "for", FOR);
  insertHashTable(lookup_table, "in", IN);
  insertHashTable(lookup_table, "switch", SWITCH);
  insertHashTable(lookup_table, "case", CASE);
  insertHashTable(lookup_table, "break", BREAK);
  insertHashTable(lookup_table, "default", DEFAULT);
  insertHashTable(lookup_table, "while", WHILE);
}

/**
 * @brief used to fill the buffer from source code
 *
 * @param fp - pointer to source code file
 */

void populate_buffer(FILE *fp) {
  int num;
  if (forward_ptr == BUFFER_SIZE) {
    forward_ptr = 0;
    num_of_rounds++;
  }
  if (retract_count == 0) {
    num = fread(&buffer[forward_ptr], 1, BUFFER_SIZE / 2, fp);
    if (num != BUFFER_SIZE / 2)
      buffer[num + forward_ptr] = EOF;
  }
}

/**
 * @brief does initialization work for lexer
 *
 * - initializes lookup table for keywords
 * - reset DFA initial state
 * - resets forward pointer and line number
 * - populates buffer
 *
 * @param source
 */

void lexer_init(FILE *source) {
  init_hash_table(lookup_table);
  populate_lookup_table();

  state = 0;
  lexeme_begin = 0;
  forward_ptr = 0;
  retract_count = 0;
  line_no = 1;
  num_of_rounds = 0;

  int num = fseek(source, 0, SEEK_SET); // go back to start of source code file
  populate_buffer(source);
}

/**
 * @brief gives a character from buffer to dfa, refills buffer when needed
 *
 * @param fp - pointer to source file
 * @return char
 */
char get_char(FILE *fp) {
  if ((forward_ptr == BUFFER_SIZE || forward_ptr == BUFFER_SIZE / 2)) {
    populate_buffer(fp);
  }
  char c = buffer[forward_ptr];
  int lex_index = forward_ptr - lexeme_begin;
  if (lex_index < 0) {
    lex_index += BUFFER_SIZE;
  }
  if (lex_index < MAX_LEXEME_LEN)
    lexeme[lex_index] = c;
  forward_ptr++;
  if (retract_count > 0)
    retract_count--;
  return c;
}

/**
 * @brief Get the next token object
 *
 * @param fp - source code file pointer
 * @return TOKEN
 */
TOKEN get_next_token(FILE *fp) {
  char c;
  TOKEN tkn;
  while (true) {
    tkn.line_no = line_no;
    switch (state) {
    case 0:;
      c = get_char(fp);
      if (isalpha(c)) {
        state = 1;
      } else if (isdigit(c)) {
        state = 3;
      } else if ('.' == c) {
        state = 38;
      } else if (';' == c) {
        state = 40;
      } else if (',' == c) {
        state = 41;
      } else if ('[' == c) {
        state = 42;
      } else if (']' == c) {
        state = 43;
      } else if ('(' == c) {
        state = 44;
      } else if (')' == c) {
        state = 45;
      } else if (EOF == c) {
        tkn.name = DOLLAR;
        return tkn;
      } else if (' ' == c || '\n' == c || '\t' == c) {
        tkn.num = c;
        if ('\n' == c) {
          line_no++;
        }
        state = 13;
      } else if ('+' == c) {
        state = 15;
      } else if ('-' == c) {
        state = 16;
      } else if ('*' == c) {
        state = 17;
      } else if ('/' == c) {
        state = 22;
      } else if ('<' == c) {
        state = 23;
      } else if ('>' == c) {
        state = 27;
      } else if ('=' == c) {
        state = 31;
      } else if ('!' == c) {
        state = 33;
      } else if (':' == c) {
        state = 35;
      }

      else {
        state = 48;
      }
      break;

    case 1:;
      c = get_char(fp);
      if (isalnum(c) || '_' == c) {
        state = 1;
      } else {
        state = 2;
      }
      break;

    case 2:;
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 3:;
      c = get_char(fp);
      if (isdigit(c)) {
        state = 3;
      } else if ('.' == c) {
        state = 5;
      } else {
        state = 4;
      }
      break;

    case 4:;
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 5:;
      c = get_char(fp);
      if ('.' == c) {
        state = 6;
      } else if (isdigit(c)) {
        state = 7;
      } else {
        retract(1);
        state = 48;
      }
      break;

    case 6:;
      retract(2);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 7:;
      c = get_char(fp);
      if (isdigit(c)) {
        state = 7;
      } else if ('e' == c || 'E' == c) {
        state = 9;
      } else {
        state = 8;
      }
      break;

    case 8:;
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 9:;
      c = get_char(fp);
      if ('+' == c || '-' == c) {
        state = 10;
      } else if (isdigit(c)) {
        state = 11;
      } else {
        retract(1);
        state = 48;
      }
      break;

    case 10:;
      c = get_char(fp);
      if (isdigit(c)) {
        state = 11;
      } else {
        retract(1);
        state = 48;
      }
      break;

    case 11:;
      c = get_char(fp);
      if (isdigit(c)) {
        state = 11;
      } else {
        state = 12;
      }
      break;

    case 12:;
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 13:;
      c = get_char(fp);
      if (' ' == c || '\n' == c || '\t' == c) {
        if ('\n' == c)
          line_no++;
        state = 13;
      } else {
        state = 14;
      }
      break;

    case 14:;
      retract(1);
      tkn.name = DELIM;
      lexeme_begin = forward_ptr;
      state = 0;
      break;

    case 15:;
      tkn.name = PLUS;
      strncpy(tkn.id.str, "+", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 16:;
      tkn.name = MINUS;
      strncpy(tkn.id.str, "-", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 17:;
      c = get_char(fp);
      if ('*' == c) {
        state = 19;
      } else {
        state = 18;
      }
      break;

    case 18:;
      retract(1);
      tkn.name = MUL;
      strncpy(tkn.id.str, "*", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 19:;
      lexeme_begin++;
      c = get_char(fp);
      if ('*' != c) {
        state = 19;
        if ('\n' == c)
          line_no++;
      } else {
        state = 20;
      }
      break;

    case 20:;
      lexeme_begin++;
      c = get_char(fp);
      if ('*' == c) {
        state = 21;
      } else {
        state = 19;
        if ('\n' == c)
          line_no++;
      }
      break;

    case 21:;
      state = 0;
      // get_char(fp);
      lexeme_begin = forward_ptr;
      break;

    case 22:;
      tkn.name = DIV;
      strncpy(tkn.id.str, "/", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 23:;
      c = get_char(fp);
      if ('=' == c) {
        state = 25;
      } else if ('<' == c) {
        state = 26;
      } else {
        state = 24;
      }
      break;

    case 24:;
      retract(1);
      tkn.name = LT;
      strncpy(tkn.id.str, "<", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 25:;
      tkn.name = LE;
      strncpy(tkn.id.str, "<=", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 26:;
      c = get_char(fp);
      if ('<' == c) {
        state = 46;
      } else {
        retract(1);
        tkn.name = DEF;
        strncpy(tkn.id.str, "<<", MAX_LEXEME_LEN);
        lexeme_begin = forward_ptr;
        state = 0;
        return tkn;
      }
      break;

    case 27:;
      c = get_char(fp);
      if ('=' == c) {
        state = 29;
      } else if ('>' == c) {
        state = 30;
      } else {
        state = 28;
      }
      break;

    case 28:;
      retract(1);
      tkn.name = GT;
      strncpy(tkn.id.str, ">", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 29:;
      tkn.name = GE;
      strncpy(tkn.id.str, ">=", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 30:;
      c = get_char(fp);
      if ('>' == c) {
        state = 47;
      } else {
        retract(1);
        tkn.name = ENDDEF;
        strncpy(tkn.id.str, ">>", MAX_LEXEME_LEN);
        lexeme_begin = forward_ptr;
        state = 0;
        return tkn;
      }
      break;

    case 31:;
      c = get_char(fp);
      if ('=' == c) {
        state = 32;
      } else {
        retract(1);
        state = 48;
      }
      break;

    case 32:;
      tkn.name = EQ;
      strncpy(tkn.id.str, "==", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 33:;
      c = get_char(fp);
      if ('=' == c) {
        state = 34;
      } else {
        retract(1);
        state = 48;
      }
      break;

    case 34:;
      tkn.name = NE;
      strncpy(tkn.id.str, "!=", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 35:;
      c = get_char(fp);
      if ('=' == c) {
        state = 36;
      } else {
        state = 37;
      }
      break;

    case 36:;
      tkn.name = ASSIGNOP;
      strncpy(tkn.id.str, ":=", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 37:;
      retract(1);
      tkn.name = COLON;
      strncpy(tkn.id.str, ":", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 38:;
      c = get_char(fp);
      if ('.' == c) {
        state = 39;
      } else {
        retract(1);
        state = 48;
      }
      break;

    case 39:;
      tkn.name = RANGEOP;
      strncpy(tkn.id.str, "..", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 40:;
      tkn.name = SEMICOL;
      strncpy(tkn.id.str, ";", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 41:;
      tkn.name = COMMA;
      strncpy(tkn.id.str, ",", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 42:;
      tkn.name = SQBO;
      strncpy(tkn.id.str, "[", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 43:;
      tkn.name = SQBC;
      strncpy(tkn.id.str, "]", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 44:;
      tkn.name = BO;
      strncpy(tkn.id.str, "(", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 45:;
      tkn.name = BC;
      strncpy(tkn.id.str, ")", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 46:;
      tkn.name = DRIVERDEF;
      strncpy(tkn.id.str, "<<<", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 47:;
      tkn.name = DRIVERENDDEF;
      strncpy(tkn.id.str, ">>>", MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 48:
      tkn.name = LEX_ERROR;
      int lex_size = forward_ptr - lexeme_begin;
      if (lex_size < 0) {
        lex_size += num_of_rounds * BUFFER_SIZE;
        num_of_rounds = 0;
      }
      int last_index =
          (lex_size < MAX_LEXEME_LEN) ? lex_size : MAX_LEXEME_LEN - 1;
      lexeme[last_index] = '\0';
      strncpy(tkn.id.str, lexeme, MAX_LEXEME_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
    default:;
      break;
    }
  }
  return tkn;
}

/**
 * @brief Printing all the lexemes recognized by the DFA
 *
 * @param source - source file pointer
 */

void tokenize_source_file(FILE *source) {
  TOKEN tkn;

  printf("%-15s  |  %-20s  |  %-20s\n", "LINE_NUMBER", "LEXEME", "TOKEN_NAME");

  if (source == NULL) {
    printf("source null : print token stream\n");
  }

  while (true) {
    tkn = get_next_token(source);
    if (tkn.name == DOLLAR) {
      break;
    } else {
      if (tkn.name == LEX_ERROR) {
        printf("==========================================================\n");
        printf("%-15d  |  %-20s  |  %-20s\n", tkn.line_no, tkn.id.str,
               "LEXICAL ERROR");
        printf("==========================================================\n");
      } else {
        if (tkn.name != DELIM) {
          printf("%-15d  |  ", tkn.line_no);
          switch (tkn.name) {
          case NUM:
            printf("%-20d  |  ", tkn.num);
            break;
          case RNUM:
            printf("%-20f  |  ", tkn.rnum);
            break;
          default:
            printf("%-20s  |  ", tkn.id.str);
            break;
          }
          printf("%-20s\n", terminal_string[tkn.name]);
        }
      }
    }
  } // end of while
}

/**
 * @brief Remove comments from the source file
 *
 * @param source - source file pointer
 * @param no_comment_file - destination file name
 */
void remove_comments(FILE *source, char *no_comment_file) {

  FILE *outp_fptr = fopen(no_comment_file, "w");
  int state = 0;
  char ch = get_char(source);

  while (ch != EOF) {
    switch (state) {
    case 0: {
      if ('*' == ch)
        state = 1;
      else
        fputc(ch, outp_fptr);
      break;
    }
    case 1: {
      if ('*' == ch)
        state = 2;
      else {
        state = 0;
        fputc('*', outp_fptr);
        fputc(ch, outp_fptr);
      }
      break;
    }
    case 2: {
      if ('*' == ch)
        state = 3;
      else {
        state = 2;
        if ('\n' == ch)
          fputc(ch, outp_fptr);
      }
      break;
    }
    case 3: {
      if ('*' == ch)
        state = 0;
      else
        state = 2;
      break;
    }
    default:
      break;
    }
    ch = get_char(source);
  } // end of while - file read

  fclose(outp_fptr);

  printf("Comments removed!! Do you want to check the output : (Y/N)\n");
  char choice;
  scanf("\n%c", &choice);

  if (choice == 'Y') {
    FILE *fptr = fopen(no_comment_file, "r");
    char *line = NULL;
    size_t len = 0;
    size_t read;

    if (fptr == NULL) {
      printf("Unable to write to file %s\n", no_comment_file);
      return;
    }

    while ((read = getline(&line, &len, fptr)) != -1) {
      printf("%s", line);
    }
    if (line)
      free(line);

    getchar();
    printf("\nPress any character to continue\n");
    char ch2;
    scanf("%c", &ch2);
    fclose(fptr);
  }
}
