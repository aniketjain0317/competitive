#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct record
{
  long long int card_no;
  char* bank_code;
  char* expiry_date;
  char* fname;
  char* lname;
};

long long myAtoi(char* str);
struct record parseRecordString(char* str);
void printRecord(struct record r);
