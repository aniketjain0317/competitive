#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "record.h"

long long myAtoi(char* str)
{
    long long res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}

struct record parseRecordString(char* str)
{
  char *token = strtok(str,",\"");
  struct record r;
  r.card_no = myAtoi(token);
  r.bank_code = (char*) malloc(sizeof(char)*20);
  r.expiry_date = (char*) malloc(sizeof(char)*20);
  r.fname = (char*) malloc(sizeof(char)*20);
  r.lname = (char*) malloc(sizeof(char)*20);
  int cs=0;
  while(cs<4)
  {
    token = strtok(NULL,",\"");
    if(cs==0) strcpy(r.bank_code, token);
    if(cs==1) strcpy(r.expiry_date, token);
    if(cs==2) strcpy(r.fname, token);
    if(cs==3) strcpy(r.lname, token);
    cs++;
  }
  return r;
}

void printRecord(struct record r)
{
  printf("CARD NO: %lld\n", r.card_no);
  printf("BANK CODE: %s\n", r.bank_code);
  printf("EXPIRY DATE: %s\n", r.expiry_date);
  printf("NAME: %s %s\n", r.fname, r.lname);
}
