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
  int num = searchHashTable(lookup_table, lexeme);
  if (KEY_NOT_FOUND == num) {
    return ID;
  } else {
    return num;
  }
}
//
// /**
//  * @brief Get the token object recognized by the DFA
//  *
//  * @return TOKEN - line_no , rnumerated value, name/int_value/real_value
//  */
//
// TOKEN get_token() {
//
//   if (lexeme_begin == BUFFER_SIZE) {
//     lexeme_begin = 0;
//   }
//   TOKEN tkn;
//
//   tkn.line_no = line_no;
//   int lex_size = forward_ptr - lexeme_begin;
//   if (lex_size < 0) {
//     lex_size += num_of_rounds * BUFFER_SIZE;
//     num_of_rounds = 0;
//   }
//   int last_index = (lex_size < MAX_KEY_LEN) ? lex_size : MAX_KEY_LEN - 1;
//   lexeme[last_index] = '\0';
//
//   if (2 == state) {
//     if (lex_size > 20) {
//       tkn.name = LEX_ERROR;
//       strncpy(tkn.id.str, lexeme, MAX_KEY_LEN);
//       return tkn;
//     }
//
//     token_name name = search_lookup_table(lexeme);
//     tkn.name = name;
//     strncpy(tkn.id.str, lexeme, MAX_KEY_LEN);
//     return tkn;
//   }
//
//   if (4 == state || 6 == state) {
//     tkn.name = NUM;
//     tkn.num = atoi(lexeme);
//   }
//
//   if (8 == state || 12 == state) {
//     tkn.name = RNUM;
//     tkn.rnum = atof(lexeme);
//   }
//   return tkn;
// }
//
// /**
//  * @brief retract and push back a character to stream
//  *
//  * @param num_of_char - number of chracters to retract
//  */
//
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

// @TODO: CHANGE TOKENS
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

int main()
{
  populate_lookup_table();
  printf("%d\n", search_lookup_table("false"));
  printf("%d\n", search_lookup_table("fal"));

}

/**
 * @brief used to fill the buffer from source code
 *
 * @param fp - pointer to source code file
 */
//
// void populate_buffer(FILE *fp) {
//   int num;
//   if (forward_ptr == BUFFER_SIZE) {
//     forward_ptr = 0;
//     num_of_rounds++;
//   }
//   if (retract_count == 0) {
//     num = fread(&buffer[forward_ptr], 1, BUFFER_SIZE / 2, fp);
//     if (num != BUFFER_SIZE / 2)
//       buffer[num + forward_ptr] = EOF;
//   }
// }
//
// /**
//  * @brief does initialization work for lexer
//  *
//  * - initializes lookup table for keywords
//  * - reset DFA initial state
//  * - resets forward pointer and line number
//  * - populates buffer
//  *
//  * @param source
//  */
//
// void lexer_init(FILE *source) {
//   init_hash_table(lookup_table);
//   populate_lookup_table();
//
//   state = 0;
//   lexeme_begin = 0;
//   forward_ptr = 0;
//   retract_count = 0;
//   line_no = 1;
//   num_of_rounds = 0;
//
//   int num = fseek(source, 0, SEEK_SET); // go back to start of source code file
//   populate_buffer(source);
// }
//
// /**
//  * @brief gives a character from buffer to dfa, refills buffer when needed
//  *
//  * @param fp - pointer to source file
//  * @return char
//  */
// char get_char(FILE *fp) {
//   if ((forward_ptr == BUFFER_SIZE || forward_ptr == BUFFER_SIZE / 2)) {
//     populate_buffer(fp);
//   }
//   char c = buffer[forward_ptr];
//   int lex_index = forward_ptr - lexeme_begin;
//   if (lex_index < 0) {
//     lex_index += BUFFER_SIZE;
//   }
//   if (lex_index < MAX_KEY_LEN)
//     lexeme[lex_index] = c;
//   forward_ptr++;
//   if (retract_count > 0)
//     retract_count--;
//   return c;
// }
//
// /**
//  * @brief Get the next token object
//  *
//  * @param fp - source code file pointer
//  * @return TOKEN
//  */
TOKEN get_next_token(FILE *fp) {
  char c;
  TOKEN tkn;
  while (true) {
    tkn.line_no = line_no;
    switch (state) {
    case 0:;
      c = get_char(fp);
      if (isalpha1(c)) {
        state = 34;
      } else if (isalpha2(c)) {
        state = 35;
      } else if (isdigit(c)) {
        state = 52;
      } else if ('.' == c) {
        state = 9;
      } else if (';' == c) {
        state = 12;
      } else if (',' == c) {
        state = 10;
      } else if ('[' == c) {
        state = 3;
      } else if (']' == c) {
        state = 4;
      } else if ('(' == c) {
        state = 1;
      } else if (')' == c) {
        state = 2;
      } else if (EOF == c) {
        // @TODO: recheck
        tkn.name = DOLLAR;
        return tkn;
      } else if (' ' == c || '\n' == c || '\t' == c) {
        // @TODO: recheck
        tkn.num = c;
        if ('\n' == c) {
          line_no++;
        }
        state = 113;
      } else if ('+' == c) {
        state = 5;
      } else if ('-' == c) {
        state = 6;
      } else if ('*' == c) {
        state = 7;
      } else if ('/' == c) {
        state = 8;
      } else if ('<' == c) {
        state = 28;
      } else if ('>' == c) {
        state = 25;
      } else if ('=' == c) {
        state = 21;
      } else if ('!' == c) {
        state = 23;
      } else if (':' == c) {
        state = 11;
      } else if ('%' == c) {
        state = 13;
      } else if ('~' == c) {
        state = 14;
      } else if ('&' == c) {
        state = 15;
      } else if ('@' == c) {
        state = 18;
      } else if ('#' == c) {
        state = 40;
      } else if ('_' == c) {
        state = 43;
      } else if (':' == c) {
        state = 11;
      }
      else {
        state = 48;
      }
      break;

    case 34:;
      c = get_char(fp);
      if (isalpha(c)) {
        state = 34;
      } else {
        state = 36;
      }
      break;

    case 36:;
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 35:;
      c = get_char(fp);
      if (isalpha(c)) {
        state = 34;
      } else if (isdigit1(c)) {
        state = 37;
      } else {
        state = 36;
      }
      break;

    case 37:;
      c = get_char(fp);
      if (isalpha2(c)) {
        state = 37;
      } else if (isdigit1(c)) {
        state = 38;
      } else {
        state = 39;
      }
      break;

    case 38:;
      c = get_char(fp);
      if (isdigit1(c)) {
        state = 38;
      } else {
        state = 39;
      }
      break;

    case 36:;
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 40:;
      c = get_char(fp);
      if(isalpha(c)) {
          state = 41;
      } else {
          state = 400;
      }
      break;

    case 41:;
      c = get_char(fp);
      if(isalpha(c)) {
          state = 41;
      } else {
          state = 42;
      }
      break;


    case 42:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 43:;
      c = get_char(fp);
      if(isalpha3(c)) {
          state = 44;
      } else {
          state = 400;
      }
      break;

    case 44:;
      c = get_char(fp);
      if(isalpha3(c)) {
          state = 44;
      } else if(isdigit(c)) {
          state = 45;
      } else {
          state = 46;
      }
      break;

    case 45:;
      c = get_char(fp);
      if(isdigit(c)) {
          state = 45;
      } else {
          state = 46;
      }
      break;

    case 46:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 1:;
      tkn.name = TK_OP;
      strncpy(tkn.id.str, "(", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 2:;
      tkn.name = TK_CL;
      strncpy(tkn.id.str, ")", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 3:;
      tkn.name = TK_SQL;
      strncpy(tkn.id.str, "[", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 4:;
      tkn.name = TK_SQR;
      strncpy(tkn.id.str, "]", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 5:;
      tkn.name = TK_PLUS;
      strncpy(tkn.id.str, "+", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 6:;
      tkn.name = TK_MINUS;
      strncpy(tkn.id.str, "-", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 7:;
      tkn.name = TK_MUL;
      strncpy(tkn.id.str, "*", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 8:;
      tkn.name = TK_DIV;
      strncpy(tkn.id.str, "/", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 9:;
      tkn.name = TK_DOT;
      strncpy(tkn.id.str, ".", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 10:;
      tkn.name = TK_COMMA;
      strncpy(tkn.id.str, ",", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 11:;
      tkn.name = TK_COLON;
      strncpy(tkn.id.str, ":", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 12:;
      tkn.name = TK_SEM;
      strncpy(tkn.id.str, ";", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 13:;
      tkn.name = TK_COMMENT;
      strncpy(tkn.id.str, "%", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 14:;
      tkn.name = TK_NOT;
      strncpy(tkn.id.str, "~", MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 15:;
      c = get_char(fp);
      if(c=='&') {
          state = 16;
      } else {
          state = 400;
      }
      break;
    case 16:;
      c = get_char(fp);
      if(c=='&') {
          state = 17;
      } else {
          state = 400;
      }
      break;
    case 17:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 18:;
      c = get_char(fp);
      if(c=='@') {
          state = 19;
      } else {
          state = 400;
      }
      break;

    case 19:;
      c = get_char(fp);
      if(c=='@') {
          state = 20;
      } else {
          state = 400;
      }
      break;

    case 20:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 21:;
      c = get_char(fp);
      if(c=='=') {
          state = 22;
      } else {
          state = 400;
      }
      break;
    case 22:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 23:;
      c = get_char(fp);
      if(c=='=') {
          state = 24;
      } else {
          state = 400;
      }
      break;
    case 24:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 25:;
      c = get_char(fp);
      if(c=='=') {
          state = 26;
      } else {
          state = 27;
      }
      break;
    case 26:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 27:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 28:;
      c = get_char(fp);
      if(c=='=') {
          state = 29;
      } else if(c=='_') {
          state = 31;
      } else {
          state = 30;
      }
      break;
    case 29:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 30:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 31:;
      c = get_char(fp);
      if(c=='_') {
          state = 32;
      } else {
          state = 400;
      }
      break;
    case 32:;
      c = get_char(fp);
      if(c=='_') {
          state = 33;
      } else {
          state = 400;
      }
      break;
    case 33:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;

    case 52:;
      c = get_char(fp);
      if(isdigit(c)) {
          state = 52;
      } else if(c=='.') {
          state = 53;
      } else {
          state = 56;
      }
      break;

    case 53:;
      c = get_char(fp);
      if(isdigit(c)) {
          state = 54;
      } else {
          state = 400;
      }
      break;
    case 54:;
      c = get_char(fp);
      if(isdigit(c)) {
          state = 55;
      } else {
          state = 400;
      }
      break;

    case 55:;
      c = get_char(fp);
      if(c=='E') {
          state = 58;
      } else {
          state = 57;
      }
      break;
    case 56:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 57:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;
    case 58:;
      c = get_char(fp);
      if(c=='+' || c=='-') {
          state = 59;
      } else if(isdigit(c)) {
          state = 60;
      } else {
        state = 400;
      }
      break;
    case 59:;
      c = get_char(fp);
      if(isdigit(c)) {
          state = 60;
      } else {
          state = 400;
      }
      break;
    case 60:;
      c = get_char(fp);
      if(isdigit(c)) {
          state = 61;
      } else {
          state = 400;
      }
      break;
    case 61:; // RETURN STATE
      retract(1);
      tkn = get_token();
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
      break;


    case 400:
      tkn.name = LEX_ERROR;
      int lex_size = forward_ptr - lexeme_begin;
      if (lex_size < 0) {
        lex_size += num_of_rounds * BUFFER_SIZE;
        num_of_rounds = 0;
      }
      int last_index =
          (lex_size < MAX_KEY_LEN) ? lex_size : MAX_KEY_LEN - 1;
      lexeme[last_index] = '\0';
      strncpy(tkn.id.str, lexeme, MAX_KEY_LEN);
      lexeme_begin = forward_ptr;
      state = 0;
      return tkn;
    default:;
      break;
    }
  }
  return tkn;
}

// /**
//  * @brief Printing all the lexemes recognized by the DFA
//  *
//  * @param source - source file pointer
//  */
//
// void tokenize_source_file(FILE *source) {
//   TOKEN tkn;
//
//   printf("%-15s  |  %-20s  |  %-20s\n", "LINE_NUMBER", "KEY", "TOKEN_NAME");
//
//   if (source == NULL) {
//     printf("source null : print token stream\n");
//   }
//
//   while (true) {
//     tkn = get_next_token(source);
//     if (tkn.name == DOLLAR) {
//       break;
//     } else {
//       if (tkn.name == LEX_ERROR) {
//         printf("==========================================================\n");
//         printf("%-15d  |  %-20s  |  %-20s\n", tkn.line_no, tkn.id.str,
//                "LEXICAL ERROR");
//         printf("==========================================================\n");
//       } else {
//         if (tkn.name != DELIM) {
//           printf("%-15d  |  ", tkn.line_no);
//           switch (tkn.name) {
//           case NUM:
//             printf("%-20d  |  ", tkn.num);
//             break;
//           case RNUM:
//             printf("%-20f  |  ", tkn.rnum);
//             break;
//           default:
//             printf("%-20s  |  ", tkn.id.str);
//             break;
//           }
//           printf("%-20s\n", terminal_string[tkn.name]);
//         }
//       }
//     }
//   } // end of while
// }
//
// /**
//  * @brief Remove comments from the source file
//  *
//  * @param source - source file pointer
//  * @param no_comment_file - destination file name
//  */
// void remove_comments(FILE *source, char *no_comment_file) {
//
//   FILE *outp_fptr = fopen(no_comment_file, "w");
//   int state = 0;
//   char ch = get_char(source);
//
//   while (ch != EOF) {
//     switch (state) {
//     case 0: {
//       if ('*' == ch)
//         state = 1;
//       else
//         fputc(ch, outp_fptr);
//       break;
//     }
//     case 1: {
//       if ('*' == ch)
//         state = 2;
//       else {
//         state = 0;
//         fputc('*', outp_fptr);
//         fputc(ch, outp_fptr);
//       }
//       break;
//     }
//     case 2: {
//       if ('*' == ch)
//         state = 3;
//       else {
//         state = 2;
//         if ('\n' == ch)
//           fputc(ch, outp_fptr);
//       }
//       break;
//     }
//     case 3: {
//       if ('*' == ch)
//         state = 0;
//       else
//         state = 2;
//       break;
//     }
//     default:
//       break;
//     }
//     ch = get_char(source);
//   } // end of while - file read
//
//   fclose(outp_fptr);
//
//   printf("Comments removed!! Do you want to check the output : (Y/N)\n");
//   char choice;
//   scanf("\n%c", &choice);
//
//   if (choice == 'Y') {
//     FILE *fptr = fopen(no_comment_file, "r");
//     char *line = NULL;
//     size_t len = 0;
//     size_t read;
//
//     if (fptr == NULL) {
//       printf("Unable to write to file %s\n", no_comment_file);
//       return;
//     }
//
//     while ((read = getline(&line, &len, fptr)) != -1) {
//       printf("%s", line);
//     }
//     if (line)
//       free(line);
//
//     getchar();
//     printf("\nPress any character to continue\n");
//     char ch2;
//     scanf("%c", &ch2);
//     fclose(fptr);
//   }
// }
